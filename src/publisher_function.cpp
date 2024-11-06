/**
 * @file pub.cpp
 * @author Apoorv Thapliyal
 * @brief C++ source file for the ROS2 publisher node.
 * @version 0.1
 * @date 2024-11-05
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <chrono>
#include <functional>
#include <memory>
#include <string>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

/**
 * @class MinimalPublisher
 * @brief A minimal ROS2 publisher node that demonstrates basic publishing functionality.
 *
 * This class implements a basic ROS2 node that publishes string messages
 * to a topic at regular intervals using a timer.
 */
class MinimalPublisher : public rclcpp::Node {
 public:
  /**
   * @brief Constructor for MinimalPublisher
   *
   * Initializes the publisher node with a name, creates a publisher
   * for string messages, and sets up a timer for periodic publishing.
   */
  MinimalPublisher()
    : Node("minimal_publisher"), count_(0) {
    publisher_ = this->create_publisher<std_msgs::msg::String>("topic", 10);
    timer_ = this->create_wall_timer(
      std::chrono::milliseconds(500),
      std::bind(&MinimalPublisher::TimerCallback, this));
  }

 private:
  /**
   * @brief Timer callback function for periodic message publishing
   *
   * This function is called periodically by the timer and publishes
   * a string message containing a counter value.
   */
  void TimerCallback() {
    auto message = std_msgs::msg::String();
    message.data = "Apoorv Thapliyal " + std::to_string(count_++);
    RCLCPP_INFO(
      this->get_logger(),
      "Publishing: '%s'", message.data.c_str());
    publisher_->publish(message);
  }

  /**
   * @brief timer_ member variable
   * 
   */
  rclcpp::TimerBase::SharedPtr timer_;

  /**
   * @brief publisher_ member variable
   * 
   */
  rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_;

  /**
  * @brief count_ member variable
  * 
  */ 
  size_t count_;
};

/**
 * @brief Main function for the publisher node
 *
 * @param argc Number of command line arguments
 * @param argv Array of command line arguments
 * @return int 0 on successful execution, non-zero otherwise
 */
int main(int argc, char* argv[]) {
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<MinimalPublisher>());
  rclcpp::shutdown();
  return 0;
}
