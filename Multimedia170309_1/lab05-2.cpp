/*
#include <opencv2/core/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/opencv.hpp>
#include <iostream>
#include <string>
#include <math.h>

using namespace cv;
using namespace std;

int main(int argc, char** argv)
{
	string imageName("C:/Users/Jayden/Pictures/image/badro.jpg");
	if (argc > 1)
	{
		imageName = argv[1];
	}

	Mat image;

	image = imread(imageName.c_str(), IMREAD_COLOR);
	if (image.empty())
	{
		cout << "Could not open or find the image" << std::endl;
		return -1;
	}

	double N;
	cin >> N;

	Mat result = Mat(int((image.size().height)* N + 0.5 ), int((image.size().width) * N + 0.5), CV_8UC3);
	result.setTo(Scalar(0));

	double new_i = 0;
	double new_j = 0;
	for (int i = 0; i < image.size().width; i++) {
		for (int j = 0; j < image.size().height; j++) {
			new_i = i*N;
			new_j = j*N;
			if (new_i / 1.00 == (int)new_i && new_j / 1.00 == (int)new_j) {
				result.at<Vec3b>(new_j, new_i)[0] = saturate_cast<uchar>(image.at<Vec3b>(j, i)[0]);
				result.at<Vec3b>(new_j, new_i)[1] = saturate_cast<uchar>(image.at<Vec3b>(j, i)[1]);
				result.at<Vec3b>(new_j, new_i)[2] = saturate_cast<uchar>(image.at<Vec3b>(j, i)[2]);
			}
		}
	}
	result.at<Vec3b>(result.size().height - 1, result.size().width - 1)[0] = image.at<Vec3b>(image.size().height - 1, image.size().width - 1)[0];
	result.at<Vec3b>(result.size().height - 1, result.size().width - 1)[1] = image.at<Vec3b>(image.size().height - 1, image.size().width - 1)[1];
	result.at<Vec3b>(result.size().height - 1, result.size().width - 1)[2] = image.at<Vec3b>(image.size().height - 1, image.size().width - 1)[2];
	for (int i = 0; i < result.size().width; i++) {
		for (int j = 0; j < result.size().height; j++) {
			if (result.at<Vec3b>(j, i)[0] == 0 && result.at<Vec3b>(j, i)[1] == 0 && result.at<Vec3b>(j, i)[2] == 0) {
				int a = floor(j / N) * N; //y-axis
				int b = floor(i / N) * N; //x-axis
				int c = (floor(j / N) + 1) * N; //y-axis
				int d = (floor(i / N) + 1) * N; //x-axis
				
				if (c >= result.size().height || d >= result.size().width) {
					c = result.size().height - 1;
					d = result.size().width - 1;
				}
				
				// i : x-axis, j : y-axis
				double alpha = (c - j) / (c - a);
				double beta = (j - a) / (c - a);
				double p = (i - b) / (d - b);
				double q = (d - i) / (d - b);
				int A[3], B[3], C[3], D[3];
				B[0] = result.at<Vec3b>(a, b)[0];
				B[1] = result.at<Vec3b>(a, b)[1];
				B[2] = result.at<Vec3b>(a, b)[2];
				A[0] = result.at<Vec3b>(c, b)[0];
				A[1] = result.at<Vec3b>(c, b)[1];
				A[2] = result.at<Vec3b>(c, b)[2];
				C[0] = result.at<Vec3b>(a, d)[0];
				C[1] = result.at<Vec3b>(a, d)[1];
				C[2] = result.at<Vec3b>(a, d)[2];
				D[0] = result.at<Vec3b>(c, d)[0];
				D[1] = result.at<Vec3b>(c, d)[1];
				D[2] = result.at<Vec3b>(c, d)[2];

				result.at<Vec3b>(j, i)[0] = saturate_cast<uchar>(q * (beta * A[0] + alpha * B[0]) + p * (beta * D[0] + alpha * C[0]));
				result.at<Vec3b>(j, i)[1] = saturate_cast<uchar>(q * (beta * A[1] + alpha * B[1]) + p * (beta * D[1] + alpha * C[1]));
				result.at<Vec3b>(j, i)[2] = saturate_cast<uchar>(q * (beta * A[2] + alpha * B[2]) + p * (beta * D[2] + alpha * C[2]));
			}
		}
	}

	//namedWindow("Display window : image 1", WINDOW_AUTOSIZE);
	imshow("DIsplay window : image 1", image);
	//namedWindow("Display window : image 1", WINDOW_AUTOSIZE);
	imshow("DIsplay window : image 2", result);


	waitKey(0);
	return 0;
}
*/