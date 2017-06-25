
#include <opencv2/core/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/opencv.hpp>
#include <iostream>
#include <string>
#include <math.h>
#include <vector>

using namespace cv;
using namespace std;
vector<int> find_key(Mat src);
Mat hist;
int main(int argc, char** argv)
{
	string imageName("C:/Users/Jayden/Pictures/image/girl.jpg");
	string imageName2("C:/Users/Jayden/Pictures/image/background.jpg");
	if (argc > 1)
	{
		imageName = argv[1];
		imageName2 = argv[2];
	}

	Mat src, cvt_src;
	Mat back, cvt_back;

	// Load the image
	src = imread(imageName.c_str(), IMREAD_COLOR);
	back = imread(imageName2.c_str(), IMREAD_COLOR);
	if (src.empty() || back.empty())
	{
		cout << "Could not open or find the image" << std::endl;
		return -1;
	}

	resize(src, cvt_src, src.size(), 0, 0, CV_INTER_CUBIC);
	cvtColor(src, cvt_src, CV_BGR2YCrCb);
	resize(back, cvt_back, src.size(), 0, 0, CV_INTER_CUBIC);
	cvtColor(back, cvt_back, CV_BGR2YCrCb);

	vector<int> result = find_key(cvt_src);
	int width = src.cols;
	int height = src.rows;
	float alpha = 1;
	int inner = 30;
	int outer = 35;

	vector<int> background = { 0,0,0 };
	for (int i = 0; i < width; i++) {
		for (int j = 0; j < height; j++) {
			float now = sqrt(pow(cvt_src.at<Vec3b>(j, i)[1] - result[2], 2) +
				pow(cvt_src.at<Vec3b>(j, i)[2] - result[1], 2) );
			//printf("%f\n", now);
			if (now < inner) {
				alpha = 1.0;
			}
			else if (now >= inner && now < outer) {
				alpha = (now - inner) / (outer - inner);
			}
			else {
				alpha = 0.0;
			}
			cvt_src.at<Vec3b>(j, i)[0] = saturate_cast<uchar>( ((1 - alpha ) * cvt_src.at<Vec3b>(j, i)[0]) + (alpha * cvt_back.at<Vec3b>(j, i)[0]));
			cvt_src.at<Vec3b>(j, i)[1] = saturate_cast<uchar>(cvt_src.at<Vec3b>(j,i)[1] -  (alpha * (float)result[2]) + (alpha * cvt_back.at<Vec3b>(j,i)[1]));
			cvt_src.at<Vec3b>(j, i)[2] = saturate_cast<uchar>(cvt_src.at<Vec3b>(j,i)[2] -  (alpha * (float)result[1]) + (alpha * cvt_back.at<Vec3b>(j, i)[2]));
		}
	}

	cvtColor(cvt_src, src, CV_YCrCb2BGR);
	imshow("DIsplay window : image 1", src);
	//imshow("DIsplay window : image 1", hist);
	//imshow("DIsplay window : image 2", cvt_src);

	waitKey(0);

	return 0;
}
vector<int> find_key(Mat src) {
	vector<int> result;
	int width = src.cols;
	int height = src.rows;
	vector<Mat> bgr_planes;
	split(src, bgr_planes);

	int histSize = 256;

	float range[] = { 0, 256 };
	const float* histRange = { range };
	bool uniform = true; bool accumulate = false;
	Mat Y_hist, Cb_hist, Cr_hist;

	calcHist(&bgr_planes[0], 1, 0, Mat(), Y_hist, 1, &histSize, &histRange, uniform, accumulate);
	calcHist(&bgr_planes[2], 1, 0, Mat(), Cb_hist, 1, &histSize, &histRange, uniform, accumulate);
	calcHist(&bgr_planes[1], 1, 0, Mat(), Cr_hist, 1, &histSize, &histRange, uniform, accumulate);
	
	float Y_max = 0;
	int Y_key = 0;
	float Cb_max = 0;
	int Cb_key = 0;
	float Cr_max = 0;
	int Cr_key = 0;
	
	for (int i = 0; i < Y_hist.size().height; i++) {
		float current = Y_hist.at<float>(i);
		if (current > Y_max) {
			Y_max = current;
			Y_key = i;
		}
	}
	for (int i = 0; i < Cb_hist.size().height; i++) {
		float current = Cb_hist.at<float>(i);
		if (current > Cb_max) {
			Cb_max = current;
			Cb_key = i;
		}
	}
	for (int i = 0; i < Cr_hist.size().height; i++) {
		float current = Cr_hist.at<float>(i);
		if (current > Cr_max) {
			Cr_max = current;
			Cr_key = i;
		}
	}

	result.push_back(Y_key);
	result.push_back(Cb_key);
	result.push_back(Cr_key);
	return result;
}
