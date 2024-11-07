/**
 * @file subscriber_node.cpp
 * @author Apoorv Thapliyal
 * @brief A simple ROS2 subscriber node implementation
 * @version 0.1
 * @date 2024-11-07
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

#include <iostream>
#include <memory>
#include <rclcpp/logging.hpp>
#include <std_msgs/msg/string.hpp>
#include <string>

#include "beginner_tutorials/srv/change_output_string.hpp"
#include "rclcpp/rclcpp.hpp"

/**
 * @brief Class for the subscriber node
 *
 */
class SubscriberNode : public rclcpp::Node {
 public:
  /**
   * @brief Constructor for the SubscriberNode
   */
  SubscriberNode() : Node("subscriber_node") {
    // Create subscription to listen to the "topic"
    subscription_ = this->create_subscription<std_msgs::msg::String>(
        "topic", 10,
        std::bind(&SubscriberNode::message_callback, this,
                  std::placeholders::_1));

    // Create a service client to interact with the publisher's change_string
    // service
    client_ = this->create_client<beginner_tutorials::srv::ChangeOutputString>(
        "change_string");

    // Wait for the service to be available
    while (!client_->wait_for_service(std::chrono::seconds(1))) {
      if (!rclcpp::ok()) {
        RCLCPP_ERROR(this->get_logger(),
                     "Interrupted while waiting for the service. Exiting.");
        return;
      }
      RCLCPP_INFO(this->get_logger(), "Waiting for service to be available...");
    }

    RCLCPP_INFO(this->get_logger(), "Subscriber node initialized");

    // Get parameter after node initialization
    this->declare_parameter<std::string>("new_message", "");

    // Retrieve the parameter after node is initialized
    std::string new_message = this->get_parameter("new_message").as_string();

    // If a new message is provided, send it to the publisher's service
    if (!new_message.empty()) {
      send_service_request(new_message);
    }
  }

 private:
  /**
   * @brief Callback function for processing received messages
   * @param msg The received string message
   */
  void message_callback(const std_msgs::msg::String::SharedPtr msg) {
    RCLCPP_INFO_STREAM(this->get_logger(), "Received message: " << msg->data);
  }

  /**
   * @brief Sends a service request to change the message in the publisher
   * @param new_message The new message to set in the publisher
   */
  void send_service_request(const std::string& new_message) {
    auto request = std::make_shared<
        beginner_tutorials::srv::ChangeOutputString::Request>();
    request->new_string = new_message;

    // Call the service asynchronously
    auto future_result = client_->async_send_request(request);

    // Print output message if new message is set
    if (new_message.empty()) {
      RCLCPP_WARN_STREAM(this->get_logger(), "New message not set");
    } else {
      RCLCPP_INFO_STREAM(this->get_logger(),
                         "New message set: " << new_message);
    }
  }

  /**
   * @brief ROS2 subscription handle for the topic
   *
   */
  rclcpp::Subscription<std_msgs::msg::String>::SharedPtr subscription_;

  /**
   * @brief Client for the service to change the message
   *
   */
  rclcpp::Client<beginner_tutorials::srv::ChangeOutputString>::SharedPtr
      client_;
};

/**
 * @brief Main function to initialize and run the subscriber node
 * @param argc Number of command line arguments
 * @param argv Command line arguments
 * @return Exit status
 */
int main(int argc, char* argv[]) {
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<SubscriberNode>());
  rclcpp::shutdown();
  return 0;
}
