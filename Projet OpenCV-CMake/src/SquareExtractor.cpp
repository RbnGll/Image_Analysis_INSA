//
// Created by xizheng on 12/4/19.
//

#include <opencv2/core/mat.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include "SquareExtractor.h"
using namespace cv;

void extract(std::string path, int ur_X, int ur_Y, int ll_X, int ll_Y) {

        const int sizeX = 2480;
        const int sizeY = 3508;
        const int urX = 2145;
        const int urY = 548;
        const int llX = 294;
        const int llY = 3162;



        int xList[5] = {330, 666, 992, 1325, 1659};
        int yList[7] = {228, 554, 883, 1216, 1544, 1875, 2205};



        cv::Mat input = cv::imread("../Images/00000.png");
        cv::Mat croppedImage = getSquare(input, llX, urY, urX - llX, llY - urY);
        
        cv::imshow("input", input);
        cv::imshow("croped", croppedImage);

    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 7; ++j) {
            cv::Mat firstSquare = getSquare(input, xList[i] + llX, yList[j] + urY, 250, 250);
            cv::imshow("Square" + std::to_string(i)+", " + std::to_string(j)+" : ", firstSquare);
            imwrite("../ImageResult/Square " + std::to_string(i)+" " + std::to_string(j)+".png ", firstSquare);
        }
    }


}

cv::Mat getSquare(cv::Mat src, int x, int y, int disX, int disY) {
    cv::Rect myROI(x, y, disX, disY);
    cv::Mat croppedImage = src(myROI);
    return croppedImage;
}
