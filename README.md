# ROS 2 Beginner Tutorials - ENPM700

This repository features the publisher-subscriber package developed for the ROS 2 beginner tutorials as part of the ENPM700 course. This project was created by **Apoorv Thapliyal** for the course *ENPM700: Software Development for Robotics* at the University of Maryland.

### Project Dependencies
This package relies on the ROS Humble Hawksbill distribution. Please ensure it is installed beforehand.  
You can find the installation instructions [here](https://docs.ros.org/en/humble/Installation.html).

### Building the Project

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

Clone the repository into your workspace:

```bash
git clone https://github.com/Apoorv-1009/my_beginner_tutorials.git
```

Once the repository is cloned, change back to the workspace directory:

```bash
cd ~/ros_ws
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

### Running the Nodes

To start the publisher, open a terminal and run the following command:

```bash
ros2 run beginner_tutorials talker
```

Then, in a new terminal (make sure to source ROS2 and the workspace setup again), start the subscriber with:

```bash
ros2 run beginner_tutorials listener
```

### Style Check Guidelines

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
cpplint --filter=-build/c++11,+build/c++17,-build/namespaces,-build/include_order src/*.cpp > results/cpplint.txt
```

Run clang tidy for diagnosing and fixing common issues:
```bash
clang-tidy -extra-arg=-std=c++17 src/*.cpp > results/clangtidy_output.txt
```