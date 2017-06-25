/*
#include <opencv2/core/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/opencv.hpp>
#include <math.h>
#include <iostream>
#include <string>

using namespace cv;
using namespace std;

int main(int argc, char** argv)
{
	string imageName("./left.png");
	if (argc > 1)
	{
		imageName = argv[1];
	}
	string image2Name("./right.png");

	Mat image;
	Mat image2;

	image = imread(imageName.c_str(), IMREAD_COLOR);
	image2 = imread(image2Name.c_str(), IMREAD_COLOR);
	if (image.empty())
	{
		cout << "Could not open or find the image" << std::endl;
		return -1;
	}
	cvtColor(image, image, CV_BGR2GRAY);
	cvtColor(image2, image2, CV_BGR2GRAY);

	int width = image.cols;
	int height = image.rows;
	double sum_list[17];
	double sum_a_search = 0.0;

	Mat disparity = Mat::zeros(height, width, image.type());

	for (int i = 2; i <= width - 3; i++) {
		for (int j = 2; j <= height - 3; j++) {
			// for a pixel
			for (int k = 1; k <= 16; k++) {
				if (i + k > width - 3)
					continue;
				//for a search
				sum_a_search = 0.0;
				for (int m = -2; m <= 2; m++) {
					for (int n = -2; n <= 2; n++) {
						//for a block [ 5 X 5 ]
						sum_a_search += pow((image2.at<uchar>((j + n), (i + m)) - image.at<uchar>((j + n),(i + m + k))) , 2);
					}
				}
				sum_list[k-1] = sum_a_search;
			}
			double min = 999999;
			int min_k;
			for (int c = 0; c < 16; c++) {
				if (sum_list[c] < min) {
					min = sum_list[c];
					min_k = c + 1;
				}
			}
			disparity.at<uchar>(j, i) = min_k * 16;
			for (int ini = 0; ini < 17; ini++)
				sum_list[ini] = 99999;
		}
	}

	imshow("DIsplay window : image 1", disparity);

	waitKey(0);
	return 0;
}
*/