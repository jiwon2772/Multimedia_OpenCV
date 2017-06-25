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
int main(int argc, char** argv)
{
	Point2f srcTri[3];
	Point2f dstTri[3];

	Mat warp_mat(2, 3, CV_32FC1);

	string imageName("C:/Users/Jayden/Pictures/image/badro.jpg");
	if (argc > 1)
	{
		imageName = argv[1];
	}

	Mat src, warp_dst;

	// Load the image
	src = imread(imageName.c_str(), IMREAD_COLOR);
	if (src.empty())
	{
		cout << "Could not open or find the image" << std::endl;
		return -1;
	}

	warp_dst = Mat::zeros(src.rows, src.cols, src.type());

	// Set your 3 points to calculate the Affine Transform
	srcTri[0] = Point2f(0, 0);
	srcTri[1] = Point2f(src.cols - 1, 0);
	srcTri[2] = Point2f(0, src.rows - 1);

	dstTri[0] = Point2f(src.cols*0.0, src.rows*0.33);
	dstTri[1] = Point2f(src.cols*0.85, src.rows*0.25);
	dstTri[2] = Point2f(src.cols*0.15, src.rows*0.7);

	// Get the Affine Transform
	warp_mat = getAffineTransform(srcTri, dstTri);

	// Apply the Affine Transform just found to the src image
	warpAffine(src, warp_dst, warp_mat, warp_dst.size());

	imshow("DIsplay window : image 1", src);
	imshow("DIsplay window : image 2", warp_dst);
	waitKey(0);

	return 0;
}
*/