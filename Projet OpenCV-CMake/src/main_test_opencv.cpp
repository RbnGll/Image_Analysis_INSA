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

using namespace std;

#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"
using namespace cv;

#include "histogram.hpp"
#include "reformat_image.h"




int main (void) {
//	computeHistogram("histogramme", im);
//	calc_threshold("threshold", im);
//    performSift();
    /*Matcher matcher;
    for (int i = 0; i < 35; ++i) {
        matcher.classifyImage("../ImageResult/Square" + to_string(i) + ".png");
    }*/
    Mat src, dst, dst_reduite;
    src=imread("../Images/00000.png");

    dst=src.clone();
    Point2f pc(src.cols/2., src.rows/2.);
    rotate_image(src,dst,pc,);
    int factor=5;
    Size tailleReduite(dst.cols/factor, dst.rows/factor);
    dst_reduite = Mat(tailleReduite,CV_8UC3);
    resize(dst,dst_reduite, tailleReduite);
    imshow("Reduite",dst_reduite);

    Mat test, dest_test;



//    std::cout << "Not a match: " << surfTest("../Images/query.png", "../Images/trainWrong.png") << endl;

//    extract("../Images/00000.png", 2145, 548, 294, 3162);
//    extract("/home-info/commun/p/p12/5info/irfBD/NicIcon/all-scans/02202.png", 2201, 468, 257, 3232);
//    extract("/home-info/commun/p/p12/5info/irfBD/NicIcon/all-scans/02601.png", 2205, 470, 263, 3232);

	waitKey(0);
	return EXIT_SUCCESS;
}
