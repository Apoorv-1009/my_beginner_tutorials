/**
 * @file publisher_function.cpp
 * @author Apoorv Thapliyal
 * @brief C++ file for the ROS2 node to broadcast a tf frame called /talk with
 * parent /world
 * @version 0.1
 * @date 2024-13-07
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

#include <chrono>
#include <cstddef>
#include <functional>
#include <memory>
#include <rclcpp/logging.hpp>
#include <std_msgs/msg/string.hpp>
#include <string>

#include "geometry_msgs/msg/transform_stamped.hpp"
#include "rclcpp/rclcpp.hpp"
#include "tf2_ros/buffer.h"
#include "tf2_ros/transform_broadcaster.h"

/**
 * @brief Simple ROS2 node
 *
 */
class MessagePublisherNode : public rclcpp::Node {
 private:
  /**
   * @brief tf broadcaster for the static tf frame
   *
   */
  std::shared_ptr<tf2_ros::TransformBroadcaster> tf_static_broadcaster_;

  /**
   * @brief Timer for the tf broadcast
   *
   */
  rclcpp::TimerBase::SharedPtr timer_;

 public:
  MessagePublisherNode() : Node("tf_publisher") {
    // Set the tf broadcaster
    tf_static_broadcaster_ =
        std::make_shared<tf2_ros::TransformBroadcaster>(this);

    // Set the timer for the tf broadcast
    timer_ = this->create_wall_timer(
        std::chrono::milliseconds(500),
        std::bind(&MessagePublisherNode::publish_message, this));
  }

  /**
   * @brief Function to broadcast the tf frame
   */
  void publish_message() {
    // Create a transform message
    geometry_msgs::msg::TransformStamped t;

    // Set header
    t.header.stamp = this->get_clock()->now();

    // Set frame ID
    t.header.frame_id = "world";

    // Set child frame ID
    t.child_frame_id = "talk";

    // Define the translation and quaternion
    double x = 1.0, y = 1.0, z = 1.0;
    double qx = 0.5, qy = 0.5, qz = 0.5, qw = 0.5;

    // Set translation (static)
    t.transform.translation.x = x;
    t.transform.translation.y = y;
    t.transform.translation.z = z;

    // Set rotation (static)
    t.transform.rotation.x = qx;
    t.transform.rotation.y = qy;
    t.transform.rotation.z = qz;
    t.transform.rotation.w = qw;

    // Broadcast the transform
    tf_static_broadcaster_->sendTransform(t);

    RCLCPP_INFO(this->get_logger(),
                "Broadcasted the tf frame: (x, y, z) = (%f, %f, %f) and (qx, "
                "qy, qz, qw) = (%f, %f, %f, %f)",
                x, y, z, qx, qy, qz, qw);
  }
};

/**
 * @brief Main function to initialize and run the node
 * @param argc Number of command line arguments
 * @param argv Command line arguments
 * @return Exit status
 */
int main(int argc, char* argv[]) {
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<MessagePublisherNode>());
  rclcpp::shutdown();
  return 0;
}
