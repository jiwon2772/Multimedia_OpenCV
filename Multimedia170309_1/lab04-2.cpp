/*
#include <opencv2/core/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/opencv.hpp>

#include <iostream>
#include <string>

using namespace cv;
using namespace std;

void HSV_brightness(Mat src, double ratio) {
	int width = src.size().width;
	int height = src.size().height;

	for (int i = 0; i < width; i++) {
		for (int j = 0; j < height; j++) {
			src.at<Vec3b>(j, i)[2] = saturate_cast<uchar>(src.at<Vec3b>(j, i)[2] * ratio);
		}
	}
}
void CMY_brightness(Mat src, double ratio) {
	int width = src.size().width;
	int height = src.size().height;

	for (int i = 0; i < width; i++) {
		for (int j = 0; j < height; j++) {
			src.at<Vec3b>(j, i)[0] = saturate_cast<uchar>(src.at<Vec3b>(j, i)[0] * ratio + 255 * (1 - ratio));
			src.at<Vec3b>(j, i)[1] = saturate_cast<uchar>(src.at<Vec3b>(j, i)[1] * ratio + 255 * (1 - ratio));
			src.at<Vec3b>(j, i)[2] = saturate_cast<uchar>(src.at<Vec3b>(j, i)[2] * ratio + 255 * (1 - ratio));
		}
	}
}
void RGB_brightness(Mat src, double ratio) {
	int width = src.size().width;
	int height = src.size().height;

	for (int i = 0; i < width; i++) {
		for (int j = 0; j < height; j++) {
			src.at<Vec3b>(j, i)[0] = saturate_cast<uchar>(src.at<Vec3b>(j, i)[0] * ratio);
			src.at<Vec3b>(j, i)[1] = saturate_cast<uchar>(src.at<Vec3b>(j, i)[1] * ratio);
			src.at<Vec3b>(j, i)[2] = saturate_cast<uchar>(src.at<Vec3b>(j, i)[2] * ratio);
		}
	}
}
void YCbCr_brightness(Mat src, double ratio) {
	int width = src.size().width;
	int height = src.size().height;

	for (int i = 0; i < width; i++) {
		for (int j = 0; j < height; j++) {
			src.at<Vec3b>(j, i)[0] = saturate_cast<uchar>(src.at<Vec3b>(j, i)[0] * ratio);
		}
	}
}
void CV_BGR2CMY(Mat src, Mat dst) {

	int width = src.size().width;
	int height = src.size().height;

	for (int i = 0; i < width; i++) {
		for (int j = 0; j < height; j++) {
			dst.at<Vec3b>(j, i)[0] = saturate_cast<uchar>(255 - src.at<Vec3b>(j, i)[0]);
			dst.at<Vec3b>(j, i)[1] = saturate_cast<uchar>(255 - src.at<Vec3b>(j, i)[1]);
			dst.at<Vec3b>(j, i)[2] = saturate_cast<uchar>(255 - src.at<Vec3b>(j, i)[2]);
		}
	}
}
int main(int argc, char** argv)
{
	string imageName("C:/Users/Jayden/Pictures/image/badro.jpg");
	if (argc > 1)
	{
		imageName = argv[1];
	}

	Mat RGB;
	Mat CMY;
	Mat HSV;
	Mat YCbCr;

	RGB = imread(imageName.c_str(), IMREAD_COLOR);
	if (RGB.empty())
	{
		cout << "Could not open or find the image" << std::endl;
		return -1;
	}
	resize(RGB, HSV, RGB.size(), 0, 0, CV_INTER_CUBIC);
	resize(RGB, YCbCr, RGB.size(), 0, 0, CV_INTER_CUBIC);
	resize(RGB, CMY, RGB.size(), 0, 0, CV_INTER_CUBIC);
	cvtColor(RGB, HSV, CV_BGR2HSV);
	cvtColor(RGB, YCbCr, CV_BGR2YCrCb);
	CV_BGR2CMY(RGB, CMY);

	//HSV
	HSV_brightness(HSV, 0.7);
	cvtColor(HSV, HSV, CV_HSV2BGR);
	//RGB
	RGB_brightness(RGB, 0.7);
	//CMY
	CMY_brightness(CMY, 0.7);  
	CV_BGR2CMY(CMY, CMY);
	//YCbCr
	YCbCr_brightness(YCbCr, 0.7);
	cvtColor(YCbCr, YCbCr, CV_YCrCb2BGR);


	//namedWindow("Display window : image 1", WINDOW_AUTOSIZE);
	imshow("DIsplay window : image 1", RGB);
	//namedWindow("Display window : image 1", WINDOW_AUTOSIZE);
	imshow("DIsplay window : image 2", HSV);
	imshow("DIsplay window : image 3", YCbCr);
	imshow("DIsplay window : image 4", CMY);


	waitKey(0);
	return 0;
}
*/