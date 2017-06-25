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

Mat gaussian(Mat src, Mat dst, int n, double sigma) {

	int width = src.size().width;
	int height = src.size().height;

	double sum = 0.0;
	double gk[100][100] = {};
	for (int k = -((n - 1) / 2); k <= (n - 1) / 2; k++) {
		for (int l = -((n - 1) / 2); l <= (n - 1) / 2; l++) {
			double r = sqrt(k*k + l*l);
			double s = 2.0 * sigma * sigma;
			gk[k + (n-1)/2][l + (n-1)/2] = (exp(-(r*r) / s)) / ((3.14) * s);
			sum += gk[k + (n - 1)/2][l + (n - 1)/2];
		}
	}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			gk[i][j] /= sum;

	for (int i = 0; i < width; i++) {
		for (int j = 0; j < height; j++) {
			double sum = 0.0;
			for (int k = 0; k < n; k++) {
				for (int l = 0; l < n; l++) {
					if ((i + (l - ((n - 1) / 2)) >= 0) && (i + (l - ((n - 1) / 2)) < width) && (j + (k - ((n - 1) / 2)) >= 0) && (j + (k - ((n - 1) / 2)) < height))
						sum += src.at<uchar>(j + (k - ((n - 1) / 2)), i + (l - ((n - 1) / 2))) * gk[k][l];
				}
			}
			dst.at<uchar>(j, i) = saturate_cast<uchar>(sum);
		}
	}
	return dst;
}
int main(int argc, char** argv)
{
	string imageName("C:/Users/Jayden/Pictures/image/badro.jpg");
	if (argc > 1)
	{
		imageName = argv[1];
	}

	Mat image;
	Mat image2;
	Mat image3;

	int N = 3;
	double sigma = 1.0;

	image = imread(imageName.c_str(), IMREAD_COLOR);
	if (image.empty())
	{
		cout << "Could not open or find the image" << std::endl;
		return -1;
	}
	resize(image, image2, image.size(), 0, 0, CV_INTER_CUBIC);
	cvtColor(image, image, CV_BGR2GRAY);
	cvtColor(image2, image2, CV_BGR2GRAY);

	//get input N and sigma from the user
	cout << "Enter N for mask-size fix : ";
	cin >> N;
	if (N % 2 == 0) {
		cout << "N should be a odd number\n" << std::endl;
		return -1;
	}

	cout << "Enter sigma for gaussian smoothing : ";
	cin >> sigma;

	image2 = gaussian(image, image2, N, sigma);

	//namedWindow("Display window : image 1", WINDOW_AUTOSIZE);
	imshow("DIsplay window : image 1", image);
	//namedWindow("Display window : image 1", WINDOW_AUTOSIZE);
	imshow("DIsplay window : image 2", image2);


	waitKey(0);
	return 0;
}
*/