## Repo Architecture:
The repo is organized in the following fashion:
carlikeBot ROS2 package: This package was developed using ROS2 Humble though it should be able to transfer to other ROS2 distros easily. Refer to the package dependencies and validate by checking to see if that distro has the same dependencies available for download.
- bringup dir: this directory contains the config and launch directory which allows us to easily view the params available for the robot for tuning and launch files to run the package.
    - config/carlikebot_controllers.yaml: This YAML file contains all the parameters for the ROS2_control package. We specify the controller manager parameters ie. update rate, controllers, etc. We also include the controller params for initialization. These can be referred to in the [docs](https://control.ros.org/humble/doc/ros2_controllers/doc/controllers_index.html). 
    - launch/carlike.launch.py: This launch file will launch: 
        1. 2 ros2_control_node instances from the controller_manager package (ie. 2 ros2_control_nodes with appropriate parameters)
        2. robot_state_publisher node from the robot_state_publisher package
        3. rviz2 from the rviz2 package
        4. 2 spawners from the controller_manager package.
- description dir: This directory contains all the files related to describing the attributes of the robot. ROS2, Gazebo, and ROS2_control will all use this directory to determine the attributes of the robot for code initialization. 
    - launch/view_robot.launch.py: This launch file serves as a test launch file to ensure everything is working. It simply runs the nodes necessary to view the robot in rviz2. It runs the following command and nodes:
        1. xacro command: This runs the xacro command to get the urdf via xacro which means that we don't have to create a new urdf file everytime we update the car.urdf.xacro file.
        2. **If the gui arg is true** then run the joint_state_publisher_gui node from the joint_state_publisher_gui.
        3. robot_state_publisher node from the robot_state_publisher package.
        4. **If the gui arg is true** then run the rviz2 node from the rviz2 package with an argument for rviz2 config file and a log file output.
