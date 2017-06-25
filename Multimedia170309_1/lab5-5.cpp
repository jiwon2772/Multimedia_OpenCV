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

	// Inputpoints
	Point2f inputQuad[4];
	// Corresponding points
	Point2f outputQuad[4];
	// warpMatrix
	Mat warp_mat(2, 4, CV_32FC1);

	// Thesefourptsarethesidesof therectboxusedasinput(from top-left in clockwise order)
	inputQuad[0] = Point2f(-30, -60);
	inputQuad[1] = Point2f(src.cols + 50, -50);
	inputQuad[2] = Point2f(src.cols + 100, src.rows + 50);
	inputQuad[3] = Point2f(-50, src.rows + 50);
	// The 4 pointswherethemappingistobedone, fromtop-leftinclockwiseorder
	outputQuad[0] = Point2f(0, 0);
	outputQuad[1] = Point2f(src.cols - 1, 0);
	outputQuad[2] = Point2f(src.cols - 1, src.rows - 1);
	outputQuad[3] = Point2f(0, src.rows - 1);

	// GetthePerspectiveTransformMatrixi.e. lambda
	warp_mat = getPerspectiveTransform(inputQuad, outputQuad);

	// ApplythePerspectiveTransformjustfoundtothesrcimage
	warpPerspective(src, warp_dst, warp_mat, warp_dst.size());

	imshow("DIsplay window : image 1", src);
	imshow("DIsplay window : image 2", warp_dst);
	waitKey(0);

	return 0;
}
*/