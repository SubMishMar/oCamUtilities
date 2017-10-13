# oCamUtilities
Code for viewing images acquired by oCam-1CGN-U using OpenCV and MATLAB.

This package is meant for capturing live video feed from oCam using OpenCV. This camera has a GRBG pixel format and cannot be used for live video streaming using the videoCapture function of OpenCV, in a straight forward way. 

Also includes a package for getting the video streams as ros image topics.

Tested on Ubuntu 16.04 and ROS Kinetic
