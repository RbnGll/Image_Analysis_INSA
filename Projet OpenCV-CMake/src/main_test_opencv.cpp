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
    Matcher matcher;
    /* k: number of scriptor*/
    for (int k = 0; k < 3 /*35*/; ++k) {
        /* i: number of page*/
        for (int i = 0; i < 23/*23*/; ++i) {
            string imagePath = basePath + "w0" + (k < 10 ? "0" + to_string(k) : to_string(k)) + "-scans/";
            string imageName = "0" + (k < 10 ? "0" + to_string(k) : to_string(k)) +
                    (i < 10 ? "0" + to_string(i) : to_string(i));
            cout << imagePath + imageName << endl;
            std::vector<cv::Mat> extractedVec = extract(imagePath, imageName, 2201, 468, 257, 3232);
            cout << "Size: " << extractedVec.size() << endl;
            int _i = 0;
            for(const auto& _im: extractedVec) {
                string p = "../ImageResult/Unclassified/0" + (k < 10 ? "0" + to_string(k) : to_string(k))
                        + "/"+ to_string(i) + "-" +to_string(_i++) + ".png";
                imwrite(p, _im);
            }
            /* number of icon */
            
            for (int j = 0; j < 7; ++j) {
                cv::Mat img = extractedVec[i];
                string maxCls = matcher.classifyImage(img);
                /* number of handwritten image */
                for (int l = 7 + j * 5; l <  7 + (j + 1) * 5; l++) {
                    cout << "l=" << to_string(l) << endl;
                    cv::Mat _img = extractedVec[l];
                    string name = maxCls + "_0" + (k < 10 ? "0" + to_string(k) : to_string(k)) + "_" +
                            (i < 10 ? "0" + to_string(i) : to_string(i)) + "_" + to_string(j) +
                            to_string((l - 7) % 5);
                    cout << "Generate " << name << endl;
                    imwrite("../ImageResult/" + maxCls + "/" + name + ".png", _img);
//                    // Write the txt file
                    std::ofstream out("../ImageResult/" + maxCls + "/" + name + ".txt");
                    out << "label " << maxCls << endl;
                    out << "form 0" << (k < 10 ? "0" + to_string(k) : to_string(k)) <<
                        (i < 10 ? "0" + to_string(i) : to_string(i)) << endl;
                    out << "scripter 0" << (k < 10 ? "0" + to_string(k) : to_string(k)) << endl;
                    out << "page" << (i < 10 ? "0" + to_string(i) : to_string(i)) << endl;
                    out << "row " << i << endl;
                    out << "column " << (l - 7) % 5 << endl;
                    out << "size medium" << endl;
                    out.close();
                }
            }
        }
    }

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
	waitKey(0);
	return EXIT_SUCCESS;
}
