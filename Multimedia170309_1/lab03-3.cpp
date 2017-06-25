/*
#include <opencv2/core/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/opencv.hpp>
#include <algorithm>
#include <iostream>
#include <string>

using namespace cv;
using namespace std;

void medianFilter(Mat src, Mat dst) {
	int width = src.size().width;
	int height = src.size().height;

	for (int i = 0; i < width; i++) {
		for (int j = 0; j < height; j++) {
			int arr[100];
			int point = 0;
			for (int k = 0; k < 10; k++) {
				for (int l = 0; l < 10; l++) {
					if ((i + (k - 1) >= 0) && (i + (k - 1) < width) && (j + (l - 1) >= 0) && (j + (l - 1) < height)) {
						arr[point] = src.at<uchar>((j + (l - 1)), (i + (k - 1)));
						point++;
					}
				}
			}
			sort(arr, arr + 100);
			dst.at<uchar>(j, i) = arr[(int)(point / 2)];
		}
	}
	
}
int main(int argc, char** argv)
{
	string imageName("C:/Users/Jayden/Pictures/image/photo6.jpg");
	if (argc > 1)
	{
		imageName = argv[1];
	}

	Mat image;
	Mat image2;

	image = imread(imageName.c_str(), IMREAD_COLOR);
	if (image.empty())
	{
		cout << "Could not open or find the image" << std::endl;
		return -1;
	}
	resize(image, image2, image.size(), 0, 0, CV_INTER_CUBIC);
	cvtColor(image, image, CV_BGR2GRAY);
	cvtColor(image2, image2, CV_BGR2GRAY);

	medianFilter(image, image2);


	//namedWindow("Display window : image 1", WINDOW_AUTOSIZE);
	imshow("DIsplay window : image 1", image);
	//namedWindow("Display window : image 1", WINDOW_AUTOSIZE);
	imshow("DIsplay window : image 2", image2);


	waitKey(0);
	return 0;
}
*/