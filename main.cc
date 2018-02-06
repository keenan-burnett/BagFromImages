#include<iostream>
#include<ros/ros.h>
#include<rosbag/bag.h>
#include<rosbag/view.h>
#include<sensor_msgs/Image.h>
#include<std_msgs/Time.h>
#include<std_msgs/Header.h>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <cv_bridge/cv_bridge.h>
#include <sensor_msgs/image_encodings.h>

#include "Thirdparty/DLib/FileFunctions.h"
#include <fstream>


using namespace std;

int main(int argc, char **argv)
{
    ros::init(argc, argv, "BagFromImages");

    if(argc!=4)
    {
        cerr << "Usage: rosrun BagFromImages BagFromImages <path to .dat file> <frequency> <path to output bag>" << endl;
        return 0;
    }

    ros::start();
    std::string vFile(argv[1]);
    std::ifstream infile(vFile, std::ifstream::in);
    // Frequency
    double freq = atof(argv[2]);
    // Output bag
    rosbag::Bag bag_out(argv[3],rosbag::bagmode::Write);
    ros::Time t = ros::TIME_MIN;

    const float T=1.0f/freq;
    ros::Duration d(T);

    int i = 0;
    std::string file_name;
    int x,y,w,h,dummy;
    while(infile >> file_name >> dummy >> x >> y >> w >> h)
    {
        if(!ros::ok())
            break;
        cv::Mat im = cv::imread(file_name,CV_LOAD_IMAGE_COLOR);
        cv_bridge::CvImage cvImage;
        cvImage.image = im;
        cvImage.encoding = sensor_msgs::image_encodings::BGR8;
        cvImage.header.stamp = t;
        bag_out.write("/camera/image_color",ros::Time(t),cvImage.toImageMsg());
        t+=d;
        cout << i << endl;
        i++;
    }

    bag_out.close();

    ros::shutdown();

    return 0;
}
