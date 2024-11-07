import launch
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, LogInfo
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        # Declare the launch arguments for setting the parameters
        DeclareLaunchArgument('publish_frequency', default_value='500', description='Publish frequency for the publisher node (in ms)'),
        DeclareLaunchArgument('new_message', default_value='', description='New message to be set by the subscriber'),

        # Launch the publisher node
        Node(
            package='beginner_tutorials',
            executable='talker',
            name='publisher_node',
            output='screen',
            parameters=[{
                'publish_frequency': LaunchConfiguration('publish_frequency')
            }],
            remappings=[('topic', 'topic')]  # You can adjust topic names if needed
        ),

        # Launch the subscriber node
        Node(
            package='beginner_tutorials',
            executable='listener',
            name='subscriber_node',
            output='screen',
            parameters=[{
                'new_message': LaunchConfiguration('new_message')
            }],
            remappings=[('topic', 'topic')]  # You can adjust topic names if needed
        ),
    ])
