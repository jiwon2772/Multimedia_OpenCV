/*
#include <opencv2/core/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/opencv.hpp>

#include <iostream>
#include <string>

using namespace cv;
using namespace std;

Mat laplacian(Mat src, Mat dst) {

	int mask[3][3] = { { -1,-1,-1 },{ -1,8,-1 },{ -1,-1,-1 } };
	int width = src.size().width;
	int height = src.size().height;

	for (int i = 0; i < width; i++) {
		for (int j = 0; j < height; j++) {
			double value = 0.0;
			int count = 0;
			for (int k = 0; k < 3; k++) {
				for (int l = 0; l < 3; l++) {
					if ((i + (k - 1) >= 0) && (i + (k - 1) < width) && (j + (l - 1) >= 0) && (j + (l - 1) < height)) {
						value = value + (src.at<uchar>((j + (l - 1)), (i + (k - 1))) * mask[k][l]);
						count++;
					}
				}
			}
			dst.at<uchar>(j, i) = saturate_cast<uchar>(value);
		}
	}
	return dst;
}
Mat sumOfImage(Mat src, Mat src2) {

	Mat dst;

	resize(src, dst, src.size(), 0, 0, CV_INTER_CUBIC);
	int width = src.size().width;
	int height = src.size().height;

	for (int i = 0; i < width; i++) {
		for (int j = 0; j < height; j++) {
			dst.at<uchar>(j, i) = saturate_cast<uchar>(src.at<uchar>(j,i) + src2.at<uchar>(j, i));
		}
	}
	return dst;
}
int main(int argc, char** argv)
{
	string imageName("C:/Users/Jayden/Pictures/image/reinhardt.jpg");
	if (argc > 1)
	{
		imageName = argv[1];
	}

	Mat image;
	Mat image2;
	Mat image3;

	image = imread(imageName.c_str(), IMREAD_COLOR);
	if (image.empty())
	{
		cout << "Could not open or find the image" << std::endl;
		return -1;
	}
	resize(image, image2, image.size(), 0, 0, CV_INTER_CUBIC);
	resize(image, image3, image.size(), 0, 0, CV_INTER_CUBIC);
	cvtColor(image, image, CV_BGR2GRAY);
	cvtColor(image2, image2, CV_BGR2GRAY);
	cvtColor(image3, image3, CV_BGR2GRAY);

	image2 = laplacian(image, image2);
	image3 = sumOfImage(image, image2);


	//namedWindow("Display window : image 1", WINDOW_AUTOSIZE);
	imshow("DIsplay window : image 1", image);
	//namedWindow("Display window : image 1", WINDOW_AUTOSIZE);
	imshow("DIsplay window : image 2", image2);
	imshow("DIsplay window : image 3", image3);


	waitKey(0);
	return 0;
}
*/