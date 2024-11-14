from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, OpaqueFunction
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node
from launch.actions import ExecuteProcess
import os
from ament_index_python.packages import get_package_share_directory

def launch_setup(context, *args, **kwargs):
    # Get the package share directory
    package_dir = get_package_share_directory('beginner_tutorials')

    # Read the launch argument for recording
    record_topics = LaunchConfiguration('record_topics').perform(context)

    # Create the node
    talker_node = Node(
        package='beginner_tutorials',
        executable='talker',
        name='talker'
    )

    # Create the bag recorder if recording is enabled
    if record_topics == 'true':
        bag_recorder = ExecuteProcess(
            cmd=['ros2', 'bag', 'record', '--all', '-o', 'recorded_topics'],
            output='screen'
        )
        return [talker_node, bag_recorder]
    else:
        return [talker_node]

def generate_launch_description():
    return LaunchDescription([
        DeclareLaunchArgument(
            'record_topics',
            default_value='true',
            description='Enable/Disable recording of all topics'
        ),
        OpaqueFunction(function=launch_setup)
    ])