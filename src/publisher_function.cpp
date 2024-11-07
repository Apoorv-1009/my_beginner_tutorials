/**
 * @file publisher_function.cpp
 * @author Apoorv Thapliyal
 * @brief C++ file for the ROS2 publisher node with a service to change the
 * published message
 * @version 0.1
 * @date 2024-11-07
 *
 * @copyright Copyright (c) 2024
 */

#include <chrono>
#include <cstddef>
#include <functional>
#include <memory>
#include <rclcpp/logging.hpp>
#include <std_msgs/msg/string.hpp>
#include <string>

#include "beginner_tutorials/srv/change_output_string.hpp"
#include "rclcpp/rclcpp.hpp"

/**
 * @brief Simple ROS2 node that publishes messages at a specified frequency
 *
 */
class MessagePublisherNode : public rclcpp::Node {
 public:
  /**
   * @brief Constructor for the MessagePublisherNode
   *
   */
  MessagePublisherNode() : Node("message_publisher"), message_count_(0) {
    // Declare the parameter with a default value, without using `as_int()` yet
    this->declare_parameter<int>("publish_frequency", 500);

    // Retrieve the parameter value, using 500 as a fallback if it's not set
    int publish_frequency;
    this->get_parameter_or("publish_frequency", publish_frequency, 500);

    // Fatal check for negative frequency
    if (publish_frequency < 0) {
      RCLCPP_FATAL_STREAM(this->get_logger(),
                          "Fatal error: Publish frequency cannot be negative");
      rclcpp::shutdown();
      std::exit(EXIT_FAILURE);
    }

    // Set default message
    this->current_message_.data = "Apoorv Thapliyal";

    // Create publisher
    message_publisher_ =
        this->create_publisher<std_msgs::msg::String>("topic", 10);

    // Create service
    message_service_ =
        this->create_service<beginner_tutorials::srv::ChangeOutputString>(
            "change_string",
            std::bind(&MessagePublisherNode::handle_message_change, this,
                      std::placeholders::_1, std::placeholders::_2));

    // Check if default frequency is being used
    if (publish_frequency == 500) {
      RCLCPP_WARN_STREAM(
          this->get_logger(),
          "Publisher frequency is not changed: " << publish_frequency);
    }

    // Create timer for publishing
    publish_timer_ = this->create_wall_timer(
        std::chrono::milliseconds(publish_frequency),
        std::bind(&MessagePublisherNode::publish_message, this));
  }

 private:
  /**
   * @brief Callback function for the publishing timer
   * @details Publishes the current message at the specified frequency
   */
  void publish_message() {
    auto message = this->current_message_;
    RCLCPP_INFO_STREAM(this->get_logger(), "Publishing: " << message.data);
    message_publisher_->publish(message);
  }

  /**
   * @brief Service callback to modify the published message
   * @param request The service request containing the new message
   * @param response The service response confirming the change
   */
  void handle_message_change(
      const std::shared_ptr<
          beginner_tutorials::srv::ChangeOutputString::Request>
          request,
      std::shared_ptr<beginner_tutorials::srv::ChangeOutputString::Response>
          response) {
    if (request->new_string.empty()) {
      RCLCPP_ERROR_STREAM(this->get_logger(),
                          "Received empty message in service request. Keeping "
                          "current message.");
      response->output =
          this->current_message_.data;  // Keep the current message as response
    } else {
      this->current_message_.data = request->new_string;
      response->output = request->new_string;
      RCLCPP_DEBUG_STREAM(this->get_logger(),
                          "Received Service Request: " << request->new_string);
    }
  }

  /**
   * @brief Current message to publish
   *
   */
  std_msgs::msg::String current_message_;

  /**
   * @brief Timer for publishing
   *
   */
  rclcpp::TimerBase::SharedPtr publish_timer_;

  /**
   * @brief Message publisher
   *
   */
  rclcpp::Publisher<std_msgs::msg::String>::SharedPtr message_publisher_;

  /**
   * @brief Service to change message
   *
   */
  rclcpp::Service<beginner_tutorials::srv::ChangeOutputString>::SharedPtr
      message_service_;

  /**
   * @brief Message counter
   *
   */
  size_t message_count_;
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
