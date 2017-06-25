/*
#include <opencv2/core/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/opencv.hpp>

#include <iostream>
#include <string>

using namespace cv;
using namespace std;

int main(int argc, char** argv)
{
	string imageName("C:/Users/Jayden/Pictures/image/160701세미나발표준비/test2.jpg");
	if (argc > 1)
	{
		imageName = argv[1];
	}

	Mat image;
	Mat image2;

	image = imread(imageName.c_str(), IMREAD_COLOR);
	image2 = imread(imageName.c_str(), IMREAD_COLOR);
	if (image.empty())
	{
		cout << "Could not open or find the image" << std::endl;
		return -1;
	}
	cvtColor(image, image, CV_BGR2GRAY);
	cvtColor(image2, image2, CV_BGR2GRAY);

	equalizeHist(image2, image2);

	

	//namedWindow("Display window : image 1", WINDOW_AUTOSIZE);
	imshow("DIsplay window : image 1", image);
	//namedWindow("Display window : image 1", WINDOW_AUTOSIZE);
	imshow("DIsplay window : image 2", image2);


	waitKey(0);
	return 0;
}
void jiwonHist(Mat src, Mat dst) {

	int hist[256] = { 0, };
	int n = src.size().height * src.size().width;

	for (int i = 0; i < src.size().height; i++) {
		for (int j = 0; j < src.size().width; j++) {
			hist[src.at<Vec3b>(i, j)[0]]+=1;
			//dst.at<Vec3b>(j, i)[0] = alpha * src1.at<Vec3b>(j, i)[0] + beta * src2.at<Vec3b>(j, i)[0];
		}
	}

	int cdf_hist[256] = { 0, };
	int sum = 0;

	for (int i = 1; i < 256; i++)
	{
		sum += hist[i];
		cdf_hist[i] = sum;
	}
}
*/