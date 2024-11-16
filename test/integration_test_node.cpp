/**
 * @file integration_test_node.cpp
 * @author Apoorv Thapliyal
 * @brief C++ file for the ROS2 node to perform L2 integration tests on the tf
 * frame using Catch2
 * @version 0.1
 * @date 2024-11-14
 *
 * @copyright Copyright (c) 2024
 *
 */

#include <tf2_ros/buffer.h>
#include <tf2_ros/transform_listener.h>

#include <catch_ros2/catch_ros2.hpp>
#include <chrono>
#include <geometry_msgs/msg/transform_stamped.hpp>
#include <rclcpp/executors.hpp>
#include <rclcpp/logging.hpp>
#include <rclcpp/rclcpp.hpp>

using namespace std::chrono_literals;

////////////////////////////////////////////////
// Define Fixture
////////////////////////////////////////////////
auto Logger = rclcpp::get_logger("");  // create an initial Logger

class TransformTestFixture {
 public:
  TransformTestFixture() {
    // Create the test node
    testerNode = rclcpp::Node::make_shared("IntegrationTestNode2");
    Logger = testerNode->get_logger();

    // Declare the test duration parameter
    testerNode->declare_parameter<double>("test_duration");
    TEST_DURATION = testerNode->get_parameter("test_duration").as_double();

    // Initialize the tf2 listener
    tf_buffer_ = std::make_shared<tf2_ros::Buffer>(testerNode->get_clock());
    tf_listener_ = std::make_shared<tf2_ros::TransformListener>(*tf_buffer_);

    RCLCPP_INFO_STREAM(Logger,
                       "Initialized TransformTestFixture with test_duration = "
                           << TEST_DURATION);
  }

  ~TransformTestFixture() {}

 protected:
  double TEST_DURATION;
  rclcpp::Node::SharedPtr testerNode;
  std::shared_ptr<tf2_ros::Buffer> tf_buffer_;
  std::shared_ptr<tf2_ros::TransformListener> tf_listener_;
};

////////////////////////////////////////////////
// Test Case: Check Static Transform
////////////////////////////////////////////////

/* In this test case, the node under test (aka Auxiliary test node)
   is a static tf publisher, which got launched by the launcher.

   We will test the static transform between the world and talk frames.
    The expected transform values are:
    - Translation: [1.0, 1.0, 1.0]
    - Rotation: [0.5, 0.5, 0.5, 0.5]
*/

TEST_CASE_METHOD(TransformTestFixture, "test static transform", "[tf]") {
  // Define the expected transform values
  const std::string parent_frame = "world";
  const std::string child_frame = "talk";
  const double expected_x = 1.0;
  const double expected_y = 1.0;
  const double expected_z = 1.0;
  const double expected_qx = 0.5;
  const double expected_qy = 0.5;
  const double expected_qz = 0.5;
  const double expected_qw = 0.5;

  bool transform_found = false;
  rclcpp::Time start_time = rclcpp::Clock().now();
  auto timeout = rclcpp::Duration::from_seconds(TEST_DURATION);
  auto duration = rclcpp::Clock().now() - start_time;

  geometry_msgs::msg::TransformStamped t;

  RCLCPP_INFO_STREAM(Logger, "Looking up transform between '"
                                 << parent_frame << "' and '" << child_frame
                                 << "'...");

  while (!transform_found && duration < timeout) {
    try {
      // Look up the transform
      t = tf_buffer_->lookupTransform(parent_frame, child_frame,
                                      rclcpp::Time(0));
      transform_found = true;
    } catch (const tf2::TransformException& ex) {
      RCLCPP_WARN_STREAM(Logger, "Transform lookup failed: " << ex.what());
    }

    rclcpp::spin_some(testerNode);
    duration = rclcpp::Clock().now() - start_time;
  }

  RCLCPP_INFO_STREAM(Logger, "Transform lookup duration: " << duration.seconds()
                                                           << " seconds");

  // Check if the transform was found
  CHECK(transform_found);

  // Validate the transform values
  CHECK(t.transform.translation.x == Catch::Approx(expected_x));
  CHECK(t.transform.translation.y == Catch::Approx(expected_y));
  CHECK(t.transform.translation.z == Catch::Approx(expected_z));
  CHECK(t.transform.rotation.x == Catch::Approx(expected_qx));
  CHECK(t.transform.rotation.y == Catch::Approx(expected_qy));
  CHECK(t.transform.rotation.z == Catch::Approx(expected_qz));
  CHECK(t.transform.rotation.w == Catch::Approx(expected_qw));

  RCLCPP_INFO_STREAM(rclcpp::get_logger("integration_test_node"),
                     "Transform values verified successfully.");
}