/*
#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
int main(int argc, char** argv)
{
	double alpha = 0.5; double beta; double input;
	Mat src1, src2, dst;

	std::cout << "Enter alpha [0-1] : " << std::endl;
	std::cin >> input;

	if (input >= 0.0 && input <= 1.0) {
		alpha = input;
	}

	src1 = imread("C:/Users/Jayden/Pictures/image/badro.jpg");
	src2 = imread("C:/Users/Jayden/Pictures/image/house.jpg");

	if (!src1.data) { printf("Error loading src1 \n"); return -1; }
	if (!src2.data) { printf("Error loading src2 \n"); return -1; }

	namedWindow("Linear Blend", 1);
	resize(src2, src2, src1.size(), 0, 0, CV_INTER_CUBIC);
	resize(src2, dst, src2.size(), 0, 0, CV_INTER_CUBIC);

	beta = (1.0 - alpha);

	for (int i = 0; i < src1.size().width; i++) {
		for (int j = 0; j < src1.size().height; j++) {
			dst.at<Vec3b>(j, i)[0] = alpha * src1.at<Vec3b>(j, i)[0] + beta * src2.at<Vec3b>(j, i)[0];
			dst.at<Vec3b>(j, i)[1] = alpha * src1.at<Vec3b>(j, i)[1] + beta * src2.at<Vec3b>(j, i)[1];
			dst.at<Vec3b>(j, i)[2] = alpha * src1.at<Vec3b>(j, i)[2] + beta * src2.at<Vec3b>(j, i)[2];
		}
	}

	imshow("Linear Blend", dst);

	waitKey(0);
	return 0;

}
*/