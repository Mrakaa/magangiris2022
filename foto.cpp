#include <bits/stdc++.h>
#include <opencv2/opencv.hpp> 

using namespace std;
using namespace cv;

int main (int argc, char** argv){
    Mat foto,foto_resize,foto_color,tresh,foto_flip,foto_edit;
    foto=imread("/home/inyournight/Dokumen/Visual Code/Open CV 1/bola.jpg");
    Point2f center;
    // center.x=100;
    // center.y=50;
    float radius;
    resize(foto,foto_resize,Size(1200,700));
    cvtColor(foto_resize, foto_color, COLOR_BGR2HSV);
    int L_H = 0;
    int U_H = 60;
    int L_S = 95;
    int U_S = 255;
    int L_V = 0;
    int U_V = 255;

    inRange(foto_color, Scalar (L_H, L_S, L_V), Scalar(U_H, U_S, U_V), tresh);
    vector<vector<Point>> contours;
    vector<Vec4i> hierarchy;
    findContours(tresh, contours, hierarchy, RETR_TREE, CHAIN_APPROX_NONE);
    for (int i=0;i<contours.size();i++){
            vector<Point>contours_lagi;
            contours_lagi = contours[i];
            minEnclosingCircle(contours_lagi,center,radius);
            if (radius>=90 && radius <=180){
                circle(foto_resize,center,radius,Scalar(225,0,0),3);
                printf ("x= %.2f, y= %.2f, rad= %.2f\n\n", center.x, center.y, radius);
                }
    }
    // flip(foto_resize,foto_flip,-1);
    rotate(foto_resize,foto_edit,ROTATE_90_COUNTERCLOCKWISE);
    imshow("WINDOW", foto_edit);
    waitKey(0);
}