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
To run the colcon test:
```bash
colcon test --packages-select beginner_tutorials
```
To view the test logs:
```bash
cat log/latest_test/beginner_tutorials/stdout_stderr.log > src/beginner_tutorials/results/catch2_tests_output.txt
```

## Style Check Guidelines

To maintain code quality, you can perform style checks using cppcheck and cpplint. First, navigate to the package directory:

```bash
cd ~/ros_ws/src/beginner_tutorials
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
