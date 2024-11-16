[![License](https://img.shields.io/badge/license-MIT-blue.svg)](LICENSE)

# ROS 2 Beginner Tutorials - ENPM700

This repository features the publisher-subscriber package developed for the ROS 2 beginner tutorials as part of the ENPM700 course. This project was created by **Apoorv Thapliyal** for the course *ENPM700: Software Development for Robotics* at the University of Maryland.

## Project Dependencies
This package relies on the ROS Humble Hawksbill distribution. Please ensure it is installed beforehand.  
You can find the installation instructions [here](https://docs.ros.org/en/humble/Installation.html).
Ensure to have empy==3.34 package installed:
```bash
pip install empy==3.3.4
```

## Building the Project

First, you need to source the ROS 2 setup script to configure your environment:

```bash
source /opt/ros/humble/setup.bash
```

Next, create a new ROS2 workspace directory:

```bash
mkdir -p ~/my_beginner_tutorials/src
```

Navigate to the source directory of your ROS2 workspace:

```bash
cd ~/my_beginner_tutorials/src
```

Clone the package into your workspace:

```bash
git clone https://github.com/Apoorv-1009/my_beginner_tutorials.git
```

Once the repository is cloned, change back to the workspace directory:

```bash
cd ~/my_beginner_tutorials
```

Before building the package, install the necessary dependencies using rosdep:

```bash
rosdep install -i --from-path src --rosdistro humble -y
```

Now, compile the package with colcon:

```bash
colcon build 
```

After a successful build, source the package to make the executables available:

```bash
source ./install/setup.bash
```

## Running the Nodes

Make sure to checkout into the `ros_tf2_unitTest_bagFiles` branch:
```bash
cd ~/my_beginner_tutorials/src/beginner_tutorials/
git checkout ros_tf2_unitTest_bagFiles
cd ../../
```
To start the publisher, open a terminal and run the following command:
```bash
ros2 run beginner_tutorials talker
```

## Running the Launch file
To start the talker and record a ros2 bag file of the transforms being published:
```bash
ros2 launch beginner_tutorials publisher_subscriber.launch.py
```
The bag file would be saved as `recorded_topics` and can be found in the workspace directory where the command was run </br>
To not record the topics, but run the launch file:
```bash
ros2 launch beginner_tutorials publisher_subscriber.launch.py record_topics:=False
```

## Viewing the tf tree
After launching the publisher, you can get the transform between `/world` and `/talk` with:
```bash
ros2 run tf2_ros tf2_echo world talk
```
To see the tf tree:
```bash
ros2 run tf2_tools view_frames
```
This would save a `frames.pdf` in the directory where it was run. A sample output has been provided under results.

### ROS2 Bag file 
To verify the topic messages of the recorded bag file, you can get its output with:
```bash
ros2 bag info recorded_topics
```

To run the bag file:
```bash
ros2 bag play recorded_topics
```
Then, in a new terminal (make sure to source ROS2 and the workspace setup again), start the subscriber with:
```bash
ros2 run beginner_tutorials listener
```
The listener would print the frames being published

## Testing
To test the `beginner_tutorials` package, we use `catch_ros2`. Install if necessary:
```bash
apt install ros-${ROS_DISTRO}-catch-ros2
```

Clone the `ros2_integration_test` in the `src/` directory, we will modify package to suit the `beginner_tutorials` package:
```bash
cd ~/my_beginner_tutorials/src
git clone git@github.com:TommyChangUMD/ros2_integration_test.git
```

Copy the `integration_test_node.cpp` in the `test/` directory and the `publisher_function.cpp` from the `src/`, into `src/` directory of `ros2_integration_test` we cloned earlier:
```bash
cp beginner_tutorials/test/integration_test_node.cpp ros2_integration_test/src
cp beginner_tutorials/src/publisher_function.cpp ros2_integration_test/src 
```

Now we will modify the `ros2_integration_test` package:
```bash
cd ros2_integration_test
```

Edit the `launch/integration_test.launch.yaml` to launch the `talker` in `beginner_tutorials`:
```bash
################################################    
# 3.) Auxiliary nodes (i.e, nodes under test) 
################################################    
- node:
    pkg: 'integration_test'
    exec: 'integration_test_node'     # This executable is built by this package (See CMakeLists.txt)

- node:
    pkg: 'beginner_tutorials'      # Note: this package is in beginner_tutorials
    exec: 'talker'
```

Edit the `CMakeLists.txt` to add the `talker` executable:
```bash
# Add executables
add_executable(talker src/publisher_function.cpp)
ament_target_dependencies(talker rclcpp std_msgs tf2_ros geometry_msgs)
```

And add it to the install Targets:
```bash
install(TARGETS
  integration_test_node
  talker
  DESTINATION lib/${PROJECT_NAME}
  )
```

Update the package dependencies of `integration_test_node.cpp`:
```bash
###########################################################################
# 1.) BUILD THE INTEGRATION TEST NODE (aka Node that performs the test)  ##
###########################################################################
# This is the node in which integration tests occur
add_executable(integration_test_node
  src/integration_test_node.cpp
  )
# The link libraries call this node with "catch_ros2::catch_ros2_with_node_main"
# to get the default integration test node main function
target_link_libraries(integration_test_node
  catch_ros2::catch_ros2_with_node_main
  )
ament_target_dependencies(integration_test_node
  rclcpp std_srvs std_msgs tf2 tf2_ros geometry_msgs
  )
```

Update the `package.xml`:
```bash
  <depend>rclcpp</depend>
  <depend>std_msgs</depend>
  <depend>std_srvs</depend>
  <depend>geometry_msgs</depend>
  <depend>tf2_ros</depend>
```

Our `ros2_integration_test` package is now up to date. </br>
To build the packages:
```bash
cd ~/my_beginner_tutorials/
colcon build --packages-select integration_test
```

To run the tests:
```bash
ros2 launch integration_test integration_test.launch.yaml
```
You can save the results with:
```bash
cat log/latest_test/integration_test/stdout_stderr.log > src/beginner_tutorials/results/catch2_tests_output.txt 
```

## Style Check Guidelines

To maintain code quality, you can perform style checks using cppcheck and cpplint. First, navigate to the package directory:

```bash
cd ~/my_beginner_tutorials/src/beginner_tutorials
```

Run cppcheck for code analysis:

```bash
cppcheck --enable=all --std=c++17 --suppress=missingIncludeSystem $(find . -name "*.cpp" | grep -vE -e "^./build/") --check-config > results/cppcheck_output.txt
```

Run cpplint for style checking:

```bash
cpplint --filter=-build/c++11,+build/c++17,-build/namespaces,-build/include_order src/*.cpp > results/cpplint_output.txt
```

Run clang tidy for diagnosing and fixing common issues:
```bash
clang-tidy -extra-arg=-std=c++17 src/*.cpp
```
You can save the output with:
```bash
echo $? > results/clangtidy_output.txt
```

To directly format the code to Google style C++:
```bash
clang-format -style=Google -i src/*.cpp
```
