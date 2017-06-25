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
int main(int, char**)
{
	Mat gray = imread("C:/Users/Jayden/Pictures/image/Lena_color.png", 0);

	int width = gray.cols;
	int height = gray.rows;

	Mat diff = Mat::zeros(height, width, gray.type());
	Mat diff_hist = Mat::zeros(height, width, gray.type());

	for (int i = 0; i < width; i++) {
		for (int j = 0; j < height; j++) {
			int temp;
			if (i == 0) temp = 0;
			else temp = gray.at<uchar>(j, i - 1);
			float x = temp - gray.at<uchar>(j, i);
			diff.at<uchar>(j, i) = saturate_cast<uchar>((255 * (x + 255)/(255 + 255)));
			diff_hist.at<uchar>(j, i) = saturate_cast<uchar>(abs(x));
		}
	}
	// Initialize parameters
	int histSize = 256; // bin size
	float range[] = { 0, 255 };
	const float *ranges[] = { range };
	// Calculate histogram
	Mat hist, hist2;
	calcHist(&diff, 1, 0, Mat(), hist, 1, &histSize, ranges, true, false);
	calcHist(&diff_hist, 1, 0, Mat(), hist2, 1, &histSize, ranges, true, false);
	// Plot the histogram
	int hist_w = 512; int hist_h = 400;
	int bin_w = cvRound((double)hist_w / histSize);
	Mat histImage(hist_h, hist_w, CV_8UC1, Scalar(0, 0, 0));
	Mat histImage2(hist_h, hist_w, CV_8UC1, Scalar(0, 0, 0));
	// Normalize the result to [ 0, histImage.rows]
	normalize(hist, hist, 0, histImage.rows, NORM_MINMAX, -1, Mat());
	normalize(hist2, hist2, 0, histImage2.rows, NORM_MINMAX, -1, Mat());
	for (int i = 1; i< histSize; i++)
	{
		line(histImage, Point(bin_w*(i - 1), hist_h - cvRound(hist.at<float>(i - 1))),
			Point(bin_w*(i), hist_h - cvRound(hist.at<float>(i))),
			Scalar(255, 0, 0), 2, 8, 0);
		line(histImage2, Point(bin_w*(i - 1), hist_h - cvRound(hist2.at<float>(i - 1))),
			Point(bin_w*(i), hist_h - cvRound(hist2.at<float>(i))),
			Scalar(255, 0, 0), 2, 8, 0);
	}
	namedWindow("Result", 1); 
	imshow("Result", histImage);
	namedWindow("Result2", 1);
	imshow("Result2", histImage2);
	waitKey(0);
	return 0;
}
*/