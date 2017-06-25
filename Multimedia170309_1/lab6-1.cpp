/*
#include <opencv2/core/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/opencv.hpp>
#include <iostream>
#include <string>
#include <math.h>

using namespace cv;
using namespace std;

int main(int, char**)
{
	VideoCapture cap(0);
	if (!cap.isOpened())
		return -1;

	Point2f srcTri[3];
	Point2f dstTri[3];

	Mat edges;
	//namedWindow("edges", 1);
	for (;;)
	{

		Mat warp_mat(2, 3, CV_32FC1);
		Mat frame;
		cap >> frame;

		// Set your 3 points to calculate the Affine Transform
		srcTri[0] = Point2f(0, 0);
		srcTri[1] = Point2f(frame.cols - 1, 0);
		srcTri[2] = Point2f(0, frame.rows - 1);

		dstTri[0] = Point2f(frame.cols*0.0, frame.rows*0.33);
		dstTri[1] = Point2f(frame.cols*0.85, frame.rows*0.25);
		dstTri[2] = Point2f(frame.cols*0.15, frame.rows*0.7);

		Mat warp_dst = Mat::zeros(frame.rows, frame.cols, frame.type());

		// Get the Affine Transform
		warp_mat = getAffineTransform(srcTri, dstTri);

		// Apply the Affine Transform just found to the src image
		warpAffine(frame, warp_dst, warp_mat, warp_dst.size());

		//cvtColor(frame, edges, COLOR_BGR2GRAY);
		//GaussianBlur(edges, edges, Size(7, 7), 1.5, 1.5);
		//Canny(edges, edges, 0, 30, 3);
		imshow("frame", warp_dst);
		if (waitKey(30) >= 0) break;
	}
}
*/