cmake_minimum_required(VERSION 3.8)
project(beginner_tutorials)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

set(CMAKE_EXPORT_COMPILE_COMMANDS ON) # Enable compile_commands.json
execute_process(COMMAND cmake -E create_symlink
                "${PROJECT_BINARY_DIR}/compile_commands.json"
                "${PROJECT_SOURCE_DIR}/compile_commands.json")

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(tf2_ros REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(rosidl_default_generators REQUIRED)
# find_package(beginner_tutorials REQUIRED)

rosidl_generate_interfaces(${PROJECT_NAME}
  "srv/ChangeOutputString.srv"
  DEPENDENCIES std_msgs 
)

# find_package(${PROJECT_NAME} REQUIRED)

# Add executables
add_executable(talker src/publisher_function.cpp)
ament_target_dependencies(talker rclcpp std_msgs tf2_ros geometry_msgs)

add_executable(listener src/subscriber_function.cpp)
ament_target_dependencies(listener rclcpp std_msgs tf2_ros geometry_msgs)

# Export ROS2 runtime dependencies
ament_export_dependencies(rosidl_default_runtime)

rosidl_get_typesupport_target(cpp_typesupport_target
  ${PROJECT_NAME} rosidl_typesupport_cpp)

target_link_libraries(talker "${cpp_typesupport_target}")
target_link_libraries(listener "${cpp_typesupport_target}")

install(TARGETS
  talker
  listener
  DESTINATION lib/${PROJECT_NAME})

install(DIRECTORY launch/
  DESTINATION share/${PROJECT_NAME})

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  set(ament_cmake_copyright_FOUND TRUE)
  set(ament_cmake_cpplint_FOUND TRUE)
  set(ament_cmake_flake8_FOUND TRUE)
  set(ament_cmake_uncrustify_FOUND TRUE)
  set(ament_cmake_lint_cmake_FOUND TRUE)
  set(ament_cmake_xmllint_FOUND TRUE)

  find_package(ament_cmake_gtest REQUIRED)

  ament_add_gtest(${PROJECT_NAME}_tutorial_test test/beginner_tutorials_tests.cpp)
  ament_lint_auto_find_test_dependencies()
  # ament_target_dependencies(${PROJECT_NAME}_tutorial_test rclcpp)
  ament_target_dependencies(${PROJECT_NAME}_tutorial_test rclcpp tf2 tf2_ros geometry_msgs)
  ament_export_dependencies(rosidl_default_runtime)

  rosidl_get_typesupport_target(cpp_typesupport_target
    ${PROJECT_NAME} rosidl_typesupport_cpp)
  target_link_libraries(${PROJECT_NAME}_tutorial_test "${cpp_typesupport_target}")
endif()

ament_package()