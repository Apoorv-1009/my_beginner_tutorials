/**
 * @file subscriber_node.cpp
 * @author Apoorv Thapliyal
 * @brief A simple ROS2 subscriber node implementation
 * @version 0.1
 * @date 2024-14-07
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

#include <tf2_ros/buffer.h>
#include <tf2_ros/transform_listener.h>
#include <memory>
#include <geometry_msgs/msg/transform_stamped.hpp>
#include <rclcpp/logging.hpp>
#include <rclcpp/rclcpp.hpp>
#include <string>

class TfSubscriberNode : public rclcpp::Node {
 private:
  /**
   * @brief tf buffer for the transform listener
   *
   */
  std::shared_ptr<tf2_ros::Buffer> tf_buffer_;

  /**
   * @brief tf listener for the transform
   *
   */
  std::shared_ptr<tf2_ros::TransformListener> tf_listener_;

  /**
   * @brief Timer to periodically check for the transform
   *
   */
  rclcpp::TimerBase::SharedPtr timer_;

 public:
  TfSubscriberNode() : Node("tf_subscriber") {
    // Initialize the TF buffer and listener
    tf_buffer_ = std::make_shared<tf2_ros::Buffer>(this->get_clock());
    tf_listener_ = std::make_shared<tf2_ros::TransformListener>(*tf_buffer_);

    // Create a timer to periodically check for the transform
    timer_ = this->create_wall_timer(
        std::chrono::milliseconds(500),
        std::bind(&TfSubscriberNode::check_transform, this));
  }

  /**
   * @brief Function to check and print the transform between /world and /talk
   * if available
   */
  void check_transform() {
    // Check if the transform exists between /world and /talk
    if (tf_buffer_->canTransform("world", "talk", tf2::TimePointZero)) {
      try {
        // Lookup the transform
        geometry_msgs::msg::TransformStamped transformStamped;
        transformStamped =
            tf_buffer_->lookupTransform("world", "talk", tf2::TimePointZero);

        // Get translation and rotation
        double x = transformStamped.transform.translation.x;
        double y = transformStamped.transform.translation.y;
        double z = transformStamped.transform.translation.z;

        double qx = transformStamped.transform.rotation.x;
        double qy = transformStamped.transform.rotation.y;
        double qz = transformStamped.transform.rotation.z;
        double qw = transformStamped.transform.rotation.w;

        // Print the translation and rotation
        RCLCPP_INFO(
            this->get_logger(),
            "Received transform: x=%f, y=%f, z=%f, qx=%f, qy=%f, qz=%f, qw=%f",
            x, y, z, qx, qy, qz, qw);
      } catch (tf2::TransformException &ex) {
        RCLCPP_WARN(this->get_logger(),
                    "Could not transform /world to /talk: %s", ex.what());
      }
    }
  }
};

int main(int argc, char **argv) {
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<TfSubscriberNode>());
  rclcpp::shutdown();
  return 0;
}
