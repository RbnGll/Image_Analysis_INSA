//////////////////////////////////////////////////////////////////////////
// Option Images
// Projet, s�ance 1
// th�me : premier pas en OpenCV
// contenu : charge, affiche, r�duction, calcul et affichage d'histogramme
// version : 17.1128
//////////////////////////////////////////////////////////////////////////


#include <iostream>
#include <thresholding.h>
#include <SquareExtractor.h>
#include <matcher.h>
#include <experimental/filesystem>
namespace fs = std::experimental::filesystem;

using namespace std;

#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"
using namespace cv;

#include <iostream>
#include <fstream>
#include <cross_detector.h>
#include "histogram.hpp"
#include "reformat_image.h"




int main () {
//    string basePath = "/home-info/commun/p/p12/5info/irfBD/NicIcon/all-scans/";
//    for (const auto & entry : fs::directory_iterator(basePath)) {
//        std::cout << entry.path() << std::endl;
//        int crossCoordinates[4];
//        // TODO
//        // fill in the coordinate array
//        extract(entry.path(), crossCoordinates[0], crossCoordinates[1], crossCoordinates[2], crossCoordinates[3]);
//    }
//    Matcher matcher;
//    for (int i = 0; i < 35; ++i) {
//        matcher.classifyImage("../ImageResult/Square" + to_string(i) + ".png");
//    }

//    std::cout << "Not a match: " << surfTest("../Images/query.png", "../Images/trainWrong.png") << endl;


    //Cross detection test
    Mat src = imread("/home-info/commun/p/p12/5info/irfBD/NicIcon/all-scans/03202.png");
    tuple<Point,Point> crosses = searchCross(src);
    circle(src,get<0>(crosses),25,Scalar(0,0,255),25);
    circle(src,get<1>(crosses),2,Scalar(0,0,255),2);
    double reduction = 3.5;
    Size reduite(src.cols/reduction, src.rows/reduction);
    Mat reducted = Mat(reduite,CV_8UC3);
    resize(src,reducted,reduite);
    imshow("crosses", reducted);
//    extract("/home-info/commun/p/p12/5info/irfBD/NicIcon/all-scans/02202.png", 2201, 468, 257, 3232);
//    extract("/home-info/commun/p/p12/5info/irfBD/NicIcon/all-scans/02601.png", 2205, 470, 263, 3232);

	waitKey(0);
	return EXIT_SUCCESS;
}
