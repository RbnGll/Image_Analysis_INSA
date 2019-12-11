//
// Created by brdaniel on 11/12/19.
//

#ifndef PROJET_OPENCV_CMAKE_REFORMAT_IMAGE_H
#define PROJET_OPENCV_CMAKE_REFORMAT_IMAGE_H

#include <iostream>
#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"
using namespace std;
using namespace cv;

void rotate_image(Mat src, Mat dst, Point rot_pt, double angle);
double compute_rotation_angle(Point bas, Point haut);

#endif //PROJET_OPENCV_CMAKE_REFORMAT_IMAGE_H
