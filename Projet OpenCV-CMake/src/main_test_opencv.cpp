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

#include <iostream>
#include <fstream>
#include "histogram.hpp"


int main () {
    string basePath = "/home-info/commun/p/p12/5info/irfBD/NicIcon/";
    Matcher matcher;

    for (int k = 0; k < 35; ++k) {
        for (int i = 0; i < 23; ++i) {
            string imagePath = basePath + "w0" + (k < 10 ? "0" + to_string(k) : to_string(k)) + "-scans/";
            string imageName = "0" + (k < 10 ? "0" + to_string(k) : to_string(k)) +
                    (i < 10 ? "0" + to_string(i) : to_string(i));
            cout << imagePath + imageName << endl;
            extract(imagePath, imageName, 2201, 468, 257, 3232);
        }  
    }
    for (int i = 0; i < 35; ++i) {
//        matcher.classifyImage("../ImageResult/Square" + to_string(i) + ".png");
    }

//    std::cout << "Not a match: " << surfTest("../Images/query.png", "../Images/trainWrong.png") << endl;
//    extract("../Images/00000.png", 2145, 548, 294, 3162);
//    for (int i = 0; i < 7; ++i) {
//        string maxCls = matcher.classifyImage("../ImageResult", "Icon" + to_string(i) + ".png");
//        cout << "Match result: " << "../ImageResult/" << "Icon" + to_string(i) + ".png" << "  ---  " <<
//            maxCls << endl << endl;
//        for (int j = i * 5; j <  (i + 1) * 5; j++) {
//            cv::Mat _img = cv::imread("../ImageResult/Square" + to_string(j) + ".png");
//            imwrite("../ImageResult/" + maxCls + "/Square" + to_string(j) + ".png", _img);
//
//            // Write the txt file
//
//            std::ofstream out("../ImageResult/" + maxCls + "/Square" + to_string(j) + ".txt");
//            out << "label " << maxCls << endl;
//            out << "row " << i << endl;
//            out << "column" << j % 5 << endl;
//            out.close();
//        }
//    }

//    extract("/home-info/commun/p/p12/5info/irfBD/NicIcon/all-scans/02202.png", 2201, 468, 257, 3232);
//    extract("/home-info/commun/p/p12/5info/irfBD/NicIcon/all-scans/02601.png", 2205, 470, 263, 3232);

	waitKey(0);
	return EXIT_SUCCESS;
}
