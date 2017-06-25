/*
#include <opencv2/core/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/opencv.hpp>

#include <iostream>
#include <string>

using namespace cv;
using namespace std;

Mat derivative(Mat src, Mat dst) {

	int maskX[3][3] = { { 1,0,-1 },{ 2,0,-2 },{ 1,0,-1 } };
	int maskY[3][3] = { { 1,2,1 },{ 0,0,0 },{ -1,-2,-1 } };
	int width = src.size().width;
	int height = src.size().height;

	for (int i = 0; i < width; i++) {
		for (int j = 0; j < height; j++) {
			double xValue = 0.0;
			double yValue = 0.0;
			int count = 0;
			for (int k = 0; k < 3; k++) {
				for (int l = 0; l < 3; l++) {
					if ((i + (k - 1) >= 0) && (i + (k - 1) < width) && (j + (l - 1) >= 0) && (j + (l - 1) < height)) {
						xValue = xValue + (src.at<uchar>((j + (l - 1)), (i + (k - 1))) * maskX[k][l]);
						yValue = yValue + (src.at<uchar>((j + (l - 1)), (i + (k - 1))) * maskY[k][l]);
						count++;
					}
				}
			}
			dst.at<uchar>(j, i) = saturate_cast<uchar>((int)sqrt((xValue * xValue) + (yValue * yValue)));
		}
	}
	return dst;
}
int main(int argc, char** argv)
{
	string imageName("C:/Users/Jayden/Pictures/image/tor.jpg");
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

	image2 = derivative(image, image2);


	//namedWindow("Display window : image 1", WINDOW_AUTOSIZE);
	imshow("DIsplay window : image 1", image);
	//namedWindow("Display window : image 1", WINDOW_AUTOSIZE);
	imshow("DIsplay window : image 2", image2);


	waitKey(0);
	return 0;
}
*/