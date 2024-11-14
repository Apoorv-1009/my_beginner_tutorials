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

#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <stdlib.h>

#include <rclcpp/rclcpp.hpp>
#include <tf2_ros/transform_listener.h>
#include <tf2_ros/buffer.h>
#include <geometry_msgs/msg/transform_stamped.hpp>

/**
 * @brief Class to handle ROS2 node setup and cleanup for tests
 */
class TfPublisherTestHelper {
public:
    TfPublisherTestHelper() : node_(std::make_shared<rclcpp::Node>("tf_test_node")) {
        RCLCPP_INFO_STREAM(node_->get_logger(), "Test Node Constructor Initialized");
        tf_buffer_ = std::make_shared<tf2_ros::Buffer>(node_->get_clock());
        tf_listener_ = std::make_shared<tf2_ros::TransformListener>(*tf_buffer_);
    }

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

    rclcpp::Node::SharedPtr node_;
    std::shared_ptr<tf2_ros::Buffer> tf_buffer_;
    std::shared_ptr<tf2_ros::TransformListener> tf_listener_;

private:
    std::stringstream cmd_ss, cmdInfo_ss, killCmd_ss;
};

// Initialize ROS before all tests
struct RosTestsFixture {
    RosTestsFixture() {
        rclcpp::init(0, nullptr);
    }
    ~RosTestsFixture() {
        rclcpp::shutdown();
        std::cout << "ROS Shutdown Completed" << std::endl;
    }
};

TEST_CASE_METHOD(RosTestsFixture, "Verify TF Transform", "[tf]") {
    std::cout << "Starting TF Transform Test" << std::endl;
    
    TfPublisherTestHelper helper;
    
    REQUIRE(helper.StartROSExec("beginner_tutorials", "tf_publisher", "talker"));

    // Wait for the transform to be published
    geometry_msgs::msg::TransformStamped transform;
    try {
        transform = helper.tf_buffer_->lookupTransform(
            "world", "talk", tf2::TimePointZero, tf2::durationFromSec(2.0));
        RCLCPP_INFO_STREAM(helper.node_->get_logger(), "Transform received successfully");
    } catch (const tf2::TransformException& ex) {
        RCLCPP_ERROR_STREAM(helper.node_->get_logger(), "Transform Exception: " << ex.what());
        FAIL("Failed to receive transform");
    }

    // Verify the translation
    CHECK(transform.transform.translation.x == Approx(1.0));
    CHECK(transform.transform.translation.y == Approx(1.0));
    CHECK(transform.transform.translation.z == Approx(1.0));

    // Verify the rotation
    CHECK(transform.transform.rotation.x == Approx(0.5));
    CHECK(transform.transform.rotation.y == Approx(0.5));
    CHECK(transform.transform.rotation.z == Approx(0.5));
    CHECK(transform.transform.rotation.w == Approx(0.5));

    REQUIRE(helper.StopROSExec());
}