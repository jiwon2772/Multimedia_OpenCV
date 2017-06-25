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
	string imageName("C:/Users/Jayden/Desktop/Jiwon/2017 SWDM/Multimedia/caltrain/caltrain000.png");
	if (argc > 1)
	{
		imageName = argv[1];
	}
	string image2Name("C:/Users/Jayden/Desktop/Jiwon/2017 SWDM/Multimedia/caltrain/caltrain001.png");

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

	int midX, midY;
	int b_p[2][2];
	int s_p[2][2];
	int c_p[2][2];
	double minDifference = 9999;
	int min_point[2];
	double amp[27][35];

	int width = image.size().width;
	int height = image.size().height;

	for (int i = 0; i < height/16; i++) {
		for (int j = 0; j < width/16; j++) {
			minDifference = 9999;
			midX = i * 16 + 7;
			midY = j * 16 + 7;
			b_p[0][0] = midX - 7;
			b_p[0][1] = midY - 7;
			b_p[1][0] = midX + 8;
			b_p[1][1] = midY + 8;
			s_p[0][0] = midX - 14;
			s_p[0][1] = midY - 14;
			s_p[1][0] = midX + 16;
			s_p[1][1] = midY + 16;
			for (int t = 0; t < 2; t++) {
				if (s_p[0][t] < 0)
					s_p[0][t] = 0;
			}
			if (s_p[1][0] >= width)
				s_p[1][0] = width - 1;
			if (s_p[1][1] >= height)
				s_p[1][1] = height - 1;
			
			for (int k = s_p[0][0]; k <= s_p[1][0]; k++) {
				for (int l = s_p[0][1]; l <= s_p[1][1]; l++) {
					double sum = 0.0;
					int count = 0;
					c_p[0][0] = k - 7;
					c_p[0][1] = l - 7;
					c_p[1][0] = k + 8;
					c_p[1][1] = l + 8;
					for (int m = 0; m < 16; m++) {
						for (int n = 0; n < 16; n++) {
							if (!(c_p[0][0] + m < 0) && !(c_p[0][0] + n < 0) && (c_p[0][0] + m < width) && (c_p[0][0] + m < height)) {
								sum += abs(image.at<uchar>(b_p[0][0] + m, b_p[0][0] + n) - image2.at<uchar>(c_p[0][0] + m, c_p[0][0] + n));
								count++;
							}
						}
					}
					double differ = sum / count;
					if (differ < minDifference) {
						minDifference = differ;
						min_point[0] = k;
						min_point[1] = l;
					}
				}
			}

			int dx = abs(midX - min_point[0]);
			int dy = abs(midY - min_point[1]);
			amp[i][j] = sqrt(pow(dx, 2) + pow(dy, 2));
			printf("%d , %d : %f\n", i, j, amp[i][j]);
 		}
	}

	double max = 0, min = 99999;
	for (int i = 0; i < 25; i++) {
		for (int j = 0; j < 32; j++) {
			if (max < amp[i][j])
				max = amp[i][j];
			if (min > amp[i][j])
				min = amp[i][j];
		}
	}

	//printf("max : %f\n", max);
	//printf("min : %f\n", min);
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			uchar newval = (unsigned char)((amp[i/16][j/16] - min)*(255 / (max - min)));
			image.at<uchar>(i, j) = newval;
		}
	}
	//namedWindow("Display window : image 1", WINDOW_AUTOSIZE);
	imshow("DIsplay window : image 1", image);
	//namedWindow("Display window : image 1", WINDOW_AUTOSIZE);
	//imshow("DIsplay window : image 2", image2);

	

	waitKey(0);
	return 0;
}
*/