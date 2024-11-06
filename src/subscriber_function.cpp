/**
 * @file sub.cpp
 * @author Apoorv Thapliyal
 * @brief C++ source file for the ROS2 subscriber node.
 * @version 0.1
 * @date 2024-11-05
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <memory>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

using std::placeholders::_1;

/**
 * @class MinimalSubscriber
 * @brief A minimal ROS2 subscriber node that demonstrates basic subscription functionality.
 *
 * This class implements a basic ROS2 node that subscribes to string messages
 * from a topic and processes them using a callback function.
 */
class MinimalSubscriber : public rclcpp::Node {
 public:
  /**
   * @brief Constructor for MinimalSubscriber
   *
   * Initializes the subscriber node with a name and creates a subscription
   * to process incoming string messages.
   */
  MinimalSubscriber()
    : Node("minimal_subscriber") {
    subscription_ = this->create_subscription<std_msgs::msg::String>(
      "topic",
      10,
      std::bind(&MinimalSubscriber::TopicCallback, this, _1));
  }

 private:
  /**
   * @brief Callback function for processing received messages
   *
   * This function is called whenever a message is received on the subscribed topic.
   * It logs the received message content using ROS2 logging.
   *
   * @param msg The received string message
   */
  void TopicCallback(const std_msgs::msg::String & msg) const {
    RCLCPP_INFO(
      this->get_logger(),
      "I heard: '%s'", msg.data.c_str());
  }

  // Subscriber handle for receiving messages
  rclcpp::Subscription<std_msgs::msg::String>::SharedPtr subscription_;
};

/**
 * @brief Main function for the subscriber node
 *
 * @param argc Number of command line arguments
 * @param argv Array of command line arguments
 * @return int 0 on successful execution, non-zero otherwise
 */
int main(int argc, char* argv[]) {
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<MinimalSubscriber>());
  rclcpp::shutdown();
  return 0;
}
