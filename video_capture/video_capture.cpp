#include <errno.h>
#include <fcntl.h>
#include <linux/videodev2.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <sys/ioctl.h>
#include <sys/mman.h>
#include <unistd.h>

#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

#include <iostream>

#include "ocam_header.h"

int main(int argc, char** argv)
{
        int fd;
 
        fd = open(argv[1], O_RDWR);//accepts the name of the device as a string argument
        if (fd == -1)
        {
                perror("Opening video device");
                return 1;
        }
        if(print_caps(fd))
            return 1;
        
        if(init_mmap(fd))
            return 1;
        int i;
        cv::namedWindow("video");
        while(true)
        {
            cv::Mat frame = capture_image(fd); 
            if(!frame.empty())
            {
            cv::cvtColor(frame, frame, CV_BGR2GRAY);
            cv::imshow("video", frame);
            cv::waitKey(1);
            }   
        }
        cv::destroyWindow("video");
        close(fd);
        return 0;
}
