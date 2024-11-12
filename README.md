# f1tenth_amr:
This project is based on the [F1Tenth project](https://f1tenth.org/). Refer to their [build documentation](https://f1tenth.org/build) for any additional information that may not be listed here on the repo. Our hope with this project is to learn how to develop autonomous robots and the become proficient with the tools that are used to develop such robots:
1. ROS
1. Isaac Sim (preferably) or another robot simulation tool
1. Sensor fusion algorithms
    - Kalman Filtering
    - Image fusion
    - Depth and Lidar Fusion
1. Signal processing for sensor hardware.
1. Controls for Robotics
1. Computervision

## Repo Architecture:
The repo is organized in the following fashion:
 - f1tenth_amr repo directory:
    - vscode_ros2_workspace: This is to enable portability and reproducibility of code. The repo was developed on VS Code so you can use VS Code to open the devcontainer and run the code in the repo. This devcontainer is designed for WSL2 on Windows and provides ROS2 Humble, gazebo classic, ign gazebo, and nvidia gpu support. GUIs should display and if there are any issues then please refer to the README under that directory. The devcontainer comes with built in VS Code tasks which enable easy installing repos, exporting repos, building, etc. 
    - src: This directory contains all the ROS2 Packages developed for this project. It will be the build path for `colcon build`. All ROS2 code should go under this folder in a package structure.
    - .gitignore: This file removes any unnecessary files from tracking. Make adjustments as necessary to ensure repo only contains files that are relevant.
    - hardwareList.md: This file contains all the hardware that was used in the project to develop the car.
    - .gitsubmodules: This file will list all the submodules present in this repo. The submodules are: 
        1. vscode-devcontainer submodule for running the code on a machine with WSL2.
        2. diffdrive_arduino for implementing hardware interface between SBC and arduino for ros2_control.
        3. RPA1 Lidar ros2 package. (currently the submodule feature for this isn't working.)
    - workflowSteps.md: This file walks through how the project was developed to assist others who may be trying to imitate or learn how we developed this car. 


The F1tenth_amr is a autonomous guided car that uses Lidar and camera to navigate the map. The project uses the Robotics Operation System (ROS), and use Issac Sim to simulate the robot. 

Refer to the hardware list for a table of the components used: [Hardware List](./hardwareList.md)