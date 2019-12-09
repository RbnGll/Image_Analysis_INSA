//
// Created by xizheng on 11/28/19.
//

#ifndef PROJET_OPENCV_CMAKE_MATCHER_H
#define PROJET_OPENCV_CMAKE_MATCHER_H

#include <iostream>
using namespace std;

#include "opencv2/imgproc.hpp"
using namespace cv;

void performSift();


class Matcher {
private:
    static float DEFAULT_RATIO;

    float ratio_thresh;
    int surf(std::string ref, std::string qry);

public:
    Matcher(float ratio) : ratio_thresh(ratio) {};
    Matcher() : Matcher(DEFAULT_RATIO) {};
    void classifyImage(const string& path);
};


#endif //PROJET_OPENCV_CMAKE_MATCHER_H
