# Jetson Containers
Jetson containers allow us to run Docker containers that will utilize the Nvidia GPU and can build on arm64 architecture. The Docker Image that you use depends on the L4T version and the Jetpack version. 

To view all the available ROS containers go to: https://github.com/dusty-nv/jetson-containers/tree/master/packages/ros
- All Jetson containers are available at: https://github.com/dusty-nv/jetson-containers/tree/master

---

Find the compatability of the Jetson board with the L4T version and Jetpack version at the following links:
- https://developer.nvidia.com/embedded/jetpack-archive
- https://developer.nvidia.com/embedded/jetson-linux-archive

## Jetson Xavier NX
If you want to use ROS2 Humble on the Xavier NX then use the following image [ROS2 Humble Desktop version](https://hub.docker.com/layers/dustynv/ros/humble-desktop-l4t-r35.3.1/images/sha256-08eafdabc4d3d9ed6395bef3fd9b12636b10258a6c2968a68eb1e611acddde5b?context=explore) or `docker pull dustynv/ros:humble-desktop-l4t-r35.3.1`.

If you want to use Pytorch with ROS2 Humble Base install then use the following image [ROS2 Humble with Pytorch](https://hub.docker.com/layers/dustynv/ros/humble-pytorch-l4t-r35.3.1/images/sha256-b1ec6f8b67f25bcf0ebb124555c058fe97c2cc03aba2fc299c2ce3296f876a55?context=explore) or `docker pull dustynv/ros:humble-pytorch-l4t-r35.3.1`. It comes with an ImageNet, SegNet, and Video DL ROS2 executables.

## Jetson Nano 4b
I have used the Jetson image available at this [repo](https://github.com/Qengineering/Jetson-Nano-Ubuntu-20-image). It comes with Jetpack 4.6.1 and L4T 32.6.1.
### ROS2 Humble
**Be aware that the Humble containers require a higher version of L4T so the image above may not work.**

If you want to use ROS2 Humble then you must use the base image [ROS2 Humble Base](https://hub.docker.com/layers/dustynv/ros/humble-ros-base-l4t-r32.7.1/images/sha256-110e55a4671fd90ad47dc1ab19fd67a98c780307e38ba4a4acc3c5efe317adc1?context=explore) or `docker pull dustynv/ros:humble-ros-base-l4t-r32.7.1`. 

This image requires that you use the highest L4T version that is available for Jetson Nano. ROS2 Humble with Pytorch can be used here [ROS2 Humble with Pytorch](https://hub.docker.com/layers/dustynv/ros/humble-pytorch-l4t-r32.7.1/images/sha256-90f184c0930e4aeb6ae8f62326746278fe40cf80659a72aa903c7233e666992c?context=explore) or `docker pull dustynv/ros:humble-pytorch-l4t-r32.7.1`.

The desktop version may not work but is available. [ROS2 Humble Desktop](https://hub.docker.com/layers/dustynv/ros/humble-desktop-l4t-r32.7.1/images/sha256-d93c0fc366578dac6ccba2770a60ce53d18655d04d8ece9de53dd12f6aa669b5?context=explore) or `docker pull dustynv/ros:humble-desktop-l4t-r32.7.1`


### ROS2 Foxy
If you want to use Pytorch on the gpu with ROS2 Foxy then use the following image: [ROS2 Foxy with Pytorch](https://hub.docker.com/layers/dustynv/ros/foxy-pytorch-l4t-r32.6.1/images/sha256-46b293335178693339f7cb11062a6f19dc1a640f82badb252265bbd2680abd06?context=explore) or `docker pull dustynv/ros:foxy-pytorch-l4t-r32.6.1`

If you want to use SLAM with ROS2 Foxy then use the following image [ROS2 Foxy with SLAM](https://hub.docker.com/layers/dustynv/ros/foxy-slam-l4t-r32.6.1/images/sha256-c0d61d653c464c7d08309fd7af57b13ad68c4622da463dd97b8bb2938ef7522e?context=explore) or `docker pull dustynv/ros:foxy-slam-l4t-r32.6.1`