//
// Created by xizheng on 12/4/19.
//

#include <opencv2/core/mat.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>
#include "SquareExtractor.h"
using namespace cv;

void extract(std::string path, int ur_X, int ur_Y, int ll_X, int ll_Y) {
    //                reference: 2145, 548, 294, 3162
    const int SIZE_X = 2480;     // Same size for all images
    const int SIZE_Y = 3508;

    int spanX = ur_X - ll_X;
    int spanY = ll_Y - ur_Y;
    double scaleX = (spanX + 0.0) / 1851;
    double scaleY = (spanY + 0.0) / 2614;

    const int WINDOW_X = 220.0 * scaleX;
    const int WINDOW_Y = 220.0 * scaleY;

    int ur_X_scaled, ur_Y_scaled, ll_X_scaled, ll_Y_scaled;


    int xOffsets[5] = {330, 666, 988, 1320, 1660};
    int yOffsets[7] = {228, 554, 883, 1220, 1544, 1875, 2205};

    cv::Mat input = cv::imread(path);
//    cv::Mat croppedImage = getSquare(input, ll_X , ur_Y, (ur_X - ll_X) * scaleX, (ll_Y - ur_Y) * scaleY);

    //        cv::imshow("input", input);
//            cv::imshow("croped", croppedImage);
    std::vector<cv::Mat> resVec;
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 7; ++j) {
            int squareX = (xOffsets[i] + ll_X) * scaleX;
            int squareY = (yOffsets[j] + ur_Y) * scaleY;
            cv::Mat firstSquare = getSquare(input,
                                        squareX,
                                        squareY,
                                        WINDOW_X,
                                        WINDOW_Y);
        //            cv::imshow("Square" + std::to_string(i)+", " + std::to_string(j)+" : ", firstSquare);
//        imwrite("../ImageResult/Square " + std::to_string(i)+" " + std::to_string(j)+" - "+
//        std::to_string(squareX)+"-"+std::to_string(squareY)+"-"+std::to_string(int(WINDOW_X))+"-"+std::to_string(int(WINDOW_Y))+".png ", firstSquare);
        resVec.push_back(firstSquare);
        }
    }

    for (int k = 0; k < resVec.size(); ++k) {
        cv::Mat _img = resVec[k];
        for (int i = 0; i < _img.rows; ++i) {
            for (int j = 0; j < _img.cols; ++j) {
                Vec3b color = _img.at<cv::Vec3b>(j, i);
                if(color[0] <150 && color[1] <150 && color[2] <150) {
                    _img.at<Vec3b>(Point(j, i)) = Vec3b(255, 255, 255);
                    std::cout << "Set to white" << std::endl;
                } else {
                    if(_img.at<Vec3b>(Point(j, i))[0]!=255&&_img.at<Vec3b>(Point(j, i))[1]!=255&&_img.at<Vec3b>(Point(j, i))[2]!=255)
                        std::cout << "Not black: " << _img.at<Vec3b>(Point(j, i)) << std::endl;
                }
            }
        }
        imwrite("../ImageResult/Square" + std::to_string(k) + ".png", _img);
    }

}

cv::Mat getSquare(cv::Mat src, int x, int y, int disX, int disY) {
    cv::Rect myROI(x, y, disX, disY);
    cv::Mat croppedImage = src(myROI);
    return croppedImage;
}
