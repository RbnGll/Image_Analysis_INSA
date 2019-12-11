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

Point searchCrossCenter (Mat src) {
    //Frame approximately localized on the cross position in the image
    Mat crossMat, cannied, block, color_dst;
    int xFenetre = (2 * src.cols / 3);
    int yFenetre = 2 * src.rows / 7;
    Rect fenetre(xFenetre, 0, src.cols - (xFenetre), (yFenetre));
    crossMat = src(fenetre);
    //Applying Canny threshold
    Canny(crossMat, cannied, 250, 500);
    //Noise deletion
    block = getStructuringElement(MORPH_RECT, Size(4, 4));
    dilate(cannied, cannied, block);
    erode(cannied, cannied, block);
    vector<Vec4i> lines;
    HoughLinesP(cannied, lines, 1, CV_PI/90, 80, 30, 10);
    color_dst=crossMat.clone();
    for (int i = 0; i < lines.size(); i++){
        line(color_dst, Point(lines[i][0], lines[i][1]), Point(lines[i][2], lines[i][3]), Scalar(0, 0, 255), 3, 8);
    }
    float upperCrossY = cannied.rows;
    float upperCrossX = 0.f;

    for (int i = 0; i < lines.size(); i++) {
        //Centre de la ligne suivant y
        float ptx = (lines[i][0] + lines[i][2]) / 2.f;
        float pty = (lines[i][1] + lines[i][3]) / 2.f;
        if ((pty < upperCrossY && pty > 0))
            upperCrossY = pty;
        upperCrossX = ptx;
    }

    return Point(upperCrossX, upperCrossY);
}
