//
// Created by brdaniel on 11/12/19.
//

#include "cross_detector.h"

#include <iostream>
#include <thresholding.h>

using namespace std;

#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"
using namespace cv;

Point searchCrossCenter(const Mat &src, const bool top) {

    Mat crossMat, edgesImage, block;
    //Frame approximately localized on the cross position in the image
    int xWindow, yWindow;
    Rect Window;
    if (top) {
        xWindow = 2 * src.cols / 3;
        yWindow =  2 * src.rows / 7;
        Window = Rect(xWindow, 0, src.cols - (xWindow), (yWindow));
    } else {
        xWindow = 1 * src.cols / 3;
        yWindow= 5 * src.rows /7;
        Window = Rect(0, yWindow, xWindow, src.rows - yWindow);
    }
    crossMat = src(Window);
    //Applying Canny threshold
    Canny(crossMat, edgesImage, 250, 500);
    //Noise deletion
    block = getStructuringElement(MORPH_RECT, Size(4, 4));
    dilate(edgesImage, edgesImage, block);
    erode(edgesImage, edgesImage, block);
    //Edge detection
    vector<Vec4i> lines;
    HoughLinesP(edgesImage, lines, 1, CV_PI/90, 80, 30, 10);

    //Lines drawing used to tune
    Mat color_dst=crossMat.clone();
    for (int i = 0; i < lines.size(); i++){
        line(color_dst, Point(lines[i][0], lines[i][1]), Point(lines[i][2], lines[i][3]), Scalar(0, 0, 255), 3, 8);
    }
    //imshow("lines", color_dst);

    float crossY, crossX;
    if (top) {
        crossY = edgesImage.rows;
        crossX = edgesImage.cols;
    } else {
        crossY = 0.f;
        crossX = 0.f;
    }

    for (int i ; i<lines.size(); i++) {
        //Centre de la ligne suivant y
        float ptx = (lines[i][0] + lines[i][2]) / 2.f;
        float pty = (lines[i][1] + lines[i][3]) / 2.f;
        if ((top && (pty < crossY && pty > 0)) || (!top && (pty>crossY))) {
            crossY = pty;
            crossX = ptx;
        }
    }

    if(top){
        crossX += xWindow;
    }else{
        crossY += yWindow;
    }


    return {(int)crossX, (int)crossY};
}

tuple<Point,Point> searchCross (const Mat& src) {
    Point bottomCross = searchCrossCenter(src, false);
    Point topCross = searchCrossCenter(src, true);
    return make_tuple(bottomCross,topCross);
}
