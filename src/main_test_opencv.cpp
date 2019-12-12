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
#include "reformat_image.h"



void generateUnclassifiedIcons() {
    int count = 0;
    string basePath = "/home-info/commun/p/p12/5info/irfBD/NicIcon/";
    for (int k = 0; k < 3/*35*/; ++k) {
        /* i: number of page*/
        for (int i = 0; i < 23; ++i) {
            string imagePath = basePath + "w0" + (k < 10 ? "0" + to_string(k) : to_string(k)) + "-scans/";
            string imageName = "0" + (k < 10 ? "0" + to_string(k) : to_string(k)) +
                               (i < 10 ? "0" + to_string(i) : to_string(i));
            cout << "Parsing file: " << imagePath + imageName << endl;
            cout << "\t\t" << to_string(k * 22 + i) << "/" << to_string(35 * 22) <<
                 "files\t\t\t" <<  (k * 22 + i) * 100 / (35 * 22) << "% completed " << endl;
            std::vector<cv::Mat> extractedVec = extract(imagePath, imageName, 2201, 468, 257, 3232);
            int _i = 0;
            for(int z = 0; z < 7; z++) {
                string p = "../ImageResult/UnclassifiedIcons/" + to_string(count++) + ".png";
                imwrite(p, extractedVec[z]);
            }
        }
    }
}

void classifyIcons(int ctr, float f, int i) {
    Matcher matcher(f, i);
    std::ofstream out("../ImageResult/ClassifiedIcons/result.txt");
    for (int i = 0; i < 482/*5635*/; ++i) {
        cv::Mat img = imread("../ImageResult/UnclassifiedIcons/" + to_string(i) + ".png");
        string cls = matcher.classifyImage(img);
        string name = "../ImageResult/ClassifiedIcons/" + to_string(ctr) + "/" + cls + "-" + to_string(i) + ".png";
        out << name << endl;
        cout << name << endl;
        imwrite(name, img);
    }
    out.close();
}

int main () {
    system("/home-reseau/xizheng/TP/Image/image-analysis/src/clean.sh");
    generateUnclassifiedIcons();
    int ctr = 0;
    for (int m = 0; m < 60; m++) {
        for (int i = 200; i < 600; i += 20) {
            string thePath = "mkdir ../ImageResult/ClassifiedIcons/" + to_string(ctr);
            char *cstr = new char[thePath.length() + 1];
            strcpy(cstr, thePath.c_str());
            system(cstr);
            classifyIcons(ctr, 0.4f + 0.02f * m, i);
            ctr++;
        }
    }

    return 0;










    string basePath = "/home-info/commun/p/p12/5info/irfBD/NicIcon/";
    Matcher matcher;
    /* k: number of scriptor*/
    for (int k = 0; k < 3 /*35*/; ++k) {
        /* i: number of page*/
        for (int i = 0; i < 23; ++i) {
            string imagePath = basePath + "w0" + (k < 10 ? "0" + to_string(k) : to_string(k)) + "-scans/";
            string imageName = "0" + (k < 10 ? "0" + to_string(k) : to_string(k)) +
                    (i < 10 ? "0" + to_string(i) : to_string(i));
            cout << "Parsing file: " << imagePath + imageName << endl;
            cout << "\t\t" << to_string(k * 22 + i) << "/" << to_string(35 * 22) <<
            "files\t\t\t" <<  (k * 22 + i) * 100 / (35 * 22) << "% completed " << endl;
            std::vector<cv::Mat> extractedVec = extract(imagePath, imageName, 2201, 468, 257, 3232);
            int _i = 0;
            for(int z = 0; z < 7; z++) {
                string p = "../ImageResult/Unclassified/0" + (k < 10 ? "0" + to_string(k) : to_string(k))
                           + "/"+ to_string(i) + "-" +to_string(_i++) + ".png";
                imwrite(p, extractedVec[z]);
            }
            /* number of icon */
            
            for (int j = 0; j < 7; ++j) {
                cv::Mat img = extractedVec[i];
                string maxCls = matcher.classifyImage(img);
                /* number of handwritten image */
                for (int l = 7 + j * 5; l <  7 + (j + 1) * 5; l++) {
                    cv::Mat _img = extractedVec[l];
                    string name = maxCls + "_0" + (k < 10 ? "0" + to_string(k) : to_string(k)) + "_" +
                            (i < 10 ? "0" + to_string(i) : to_string(i)) + "_" + to_string(j) +
                            to_string((l - 7) % 5);
//                    cout << "Generate " << name << endl;
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
                    out << "size " << to_string(_img.cols) << " * " << to_string(_img.rows) << endl;
                    out.close();
                }
            }
        }
    }
	waitKey(0);
	return EXIT_SUCCESS;
}
