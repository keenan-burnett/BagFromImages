# BagFromImages

ROS package to generate a rosbag from a collection of images. Images are ordered alphabetically. The timestamp for each image is assigned according to the specified frequency. 

The bag will publish the images to topic `/camera/image_raw`.

Tested in ROS Kinetic + OpenCV 3.3.1 + C++ 11

## Installation

In your ROS_PACKAGE_PATH (check your environment variable ROS_PACKAGE_PATH):

    mkdir -p /catkin_ws/src
    cd /catkin/src
    git clone https://github.com/keenan-burnett/BagFromImages.git
    cd ..
    catkin build

## Usage:

    rosrun BagFromImages main PATH_TO_VEC_FILE FREQUENCY PATH_TO_OUPUT_BAG
  
 - `PATH_TO_VEC_FILE`: Path to a .dat file while contains the absolute path of each image, one per line
 - `FREQUENCY`: Frames per second.
 - `PATH_TO_OUTPUT_BAG`: Path to save the bag (including the filename e.g. directory/filename.bag)

