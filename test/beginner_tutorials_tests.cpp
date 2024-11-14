/**
 * @file beginner_tutorials_tests.cpp
 * @author Apoorv Thapliyal
 * @brief 
 * @version 0.1
 * @date 2024-11-14
 * 
 * @copyright Copyright (c) 2024
 * @license MIT License
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#include <gtest/gtest.h>
#include <stdlib.h>

#include <rclcpp/rclcpp.hpp>
#include <tf2_ros/transform_listener.h>
#include <tf2_ros/buffer.h>
#include <geometry_msgs/msg/transform_stamped.hpp>

/**
 * @brief Testing fixture for the level 2 ROS Node Test
 *
 */
class TfPublisherTestFixture : public testing::Test {
    public:
    TfPublisherTestFixture() : node_(std::make_shared<rclcpp::Node>("tf_test_node")) {
        RCLCPP_INFO_STREAM(node_->get_logger(), "Test Node Constructor Initialized");
    }

    void SetUp() override {
        bool retVal = StartROSExec("beginner_tutorials", "tf_publisher", "talker");
        ASSERT_TRUE(retVal);
        tf_buffer_ = std::make_shared<tf2_ros::Buffer>(node_->get_clock());
        tf_listener_ = std::make_shared<tf2_ros::TransformListener>(*tf_buffer_);
        RCLCPP_INFO_STREAM(node_->get_logger(), "Test Setup Completed");
    }

    void TearDown() override {
        bool retVal = StopROSExec();
        ASSERT_TRUE(retVal);
        std::cout << "Teardown Completed" << std::endl;
    }

    protected:
        rclcpp::Node::SharedPtr node_;
        std::shared_ptr<tf2_ros::Buffer> tf_buffer_;
        std::shared_ptr<tf2_ros::TransformListener> tf_listener_;
        std::stringstream cmd_ss, cmdInfo_ss, killCmd_ss;

        bool StartROSExec(const char* pkg_name, const char* node_name, const char* exec_name) {
            // Build command strings
            cmd_ss << "ros2 run " << pkg_name << " " << exec_name << " > /dev/null 2> /dev/null &";
            cmdInfo_ss << "ros2 node info "
                        << "/" << node_name << " > /dev/null 2> /dev/null";
            char execName[16];
            snprintf(execName, sizeof(execName), "%s", exec_name);  // pkill uses exec name <= 15 char only
            killCmd_ss << "pkill --signal SIGINT " << execName << " > /dev/null 2> /dev/null";

            // Kill any existing instances of the node
            StopROSExec();

            // Start the ROS 2 node and wait for it to become active
            int retVal = system(cmd_ss.str().c_str());
            if (retVal != 0) return false;

            retVal = -1;
            while (retVal != 0) {
                retVal = system(cmdInfo_ss.str().c_str());
                sleep(1);
            }
            return true;
        }

        bool StopROSExec() {
            if (killCmd_ss.str().empty()) return true;
            int retVal = system(killCmd_ss.str().c_str());
            return retVal == 0;
        }
};

/**
 * @brief Test case to verify the TF transform broadcast by the node
 */
TEST_F(TfPublisherTestFixture, VerifyTfTransform) {
    std::cout << "Starting TF Transform Test" << std::endl;

    // Wait for the transform to be published
    geometry_msgs::msg::TransformStamped transform;
    try {
        transform = tf_buffer_->lookupTransform("world", "talk", tf2::TimePointZero, tf2::durationFromSec(2.0));
        RCLCPP_INFO_STREAM(node_->get_logger(), "Transform received successfully");
    } catch (const tf2::TransformException& ex) {
        RCLCPP_ERROR_STREAM(node_->get_logger(), "Transform Exception: " << ex.what());
        FAIL() << "Failed to receive transform";
    }

    // Verify the translation
    EXPECT_DOUBLE_EQ(transform.transform.translation.x, 1.0);
    EXPECT_DOUBLE_EQ(transform.transform.translation.y, 1.0);
    EXPECT_DOUBLE_EQ(transform.transform.translation.z, 1.0);

    // Verify the rotation
    EXPECT_DOUBLE_EQ(transform.transform.rotation.x, 0.5);
    EXPECT_DOUBLE_EQ(transform.transform.rotation.y, 0.5);
    EXPECT_DOUBLE_EQ(transform.transform.rotation.z, 0.5);
    EXPECT_DOUBLE_EQ(transform.transform.rotation.w, 0.5);
}

/**
 * @brief Main function to initialize and run the tests
 */
int main(int argc, char** argv) {
    rclcpp::init(argc, argv);
    ::testing::InitGoogleTest(&argc, argv);
    int result = RUN_ALL_TESTS();
    rclcpp::shutdown();
    std::cout << "ROS Shutdown Completed" << std::endl;
    return result;
}
