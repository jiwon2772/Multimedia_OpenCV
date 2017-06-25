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

	Mat result = Mat(int((image.size().height)*N), int((image.size().width)*N), CV_8UC3);
	result.setTo(Scalar(0));

	double new_i = 0;
	double new_j = 0;
	for (int i = 0; i < image.size().width; i++) {
		for (int j = 0; j < image.size().height; j++) {
			new_i = i*N;
			new_j = j*N;
			if (new_i / 1.00 == (int)new_i && new_j / 1.00 == (int)new_j) {
				result.at<Vec3b>(j*N, i*N)[0] = image.at<Vec3b>(j, i)[0];
				result.at<Vec3b>(j*N, i*N)[1] = image.at<Vec3b>(j, i)[1];
				result.at<Vec3b>(j*N, i*N)[2] = image.at<Vec3b>(j, i)[2];
			}
		}
	}
	for (int i = 0; i < result.size().width; i++) {
		for (int j = 0; j < result.size().height; j++) {
			if (result.at<Vec3b>(j, i)[0] == 0 && result.at<Vec3b>(j, i)[1] == 0 && result.at<Vec3b>(j, i)[2] == 0) {
				int current = 1;
				int check[3] = { 255,255,255 };
				while (1) {
					if ((j - current) >= 0 && !(result.at<Vec3b>(j - current,i)[0] == 0 && result.at<Vec3b>(j - current, i)[1] == 0 && result.at<Vec3b>(j - current, i)[2] == 0)) {
						check[0] = result.at<Vec3b>(j - current, i)[0];
						check[1] = result.at<Vec3b>(j - current, i)[1];
						check[2] = result.at<Vec3b>(j - current, i)[2];
						break;
					}
					else if ((j + current < result.size().height && !(result.at<Vec3b>(j + current,i)[0] == 0 && result.at<Vec3b>(j + current, i)[1] == 0 && result.at<Vec3b>(j + current, i)[2] == 0))) {
						check[0] = result.at<Vec3b>(j + current, i)[0];
						check[1] = result.at<Vec3b>(j + current, i)[1];
						check[2] = result.at<Vec3b>(j + current, i)[2];
						break;
					}
					else if (i - current >= 0 && !(result.at<Vec3b>(j, i - current)[0] == 0 && result.at<Vec3b>(j, i - current)[1] == 0 && result.at<Vec3b>(j, i - current)[2] == 0)) {
						check[0] = result.at<Vec3b>(j, i - current)[0];
						check[1] = result.at<Vec3b>(j, i - current)[1];
						check[2] = result.at<Vec3b>(j, i - current)[2];
						break;
					}
					else if (i + current < result.size().width && !(result.at<Vec3b>(j, i + current)[0] == 0 && result.at<Vec3b>(j, i + current)[1] == 0 && result.at<Vec3b>(j, i + current)[2] == 0)) {
						check[0] = result.at<Vec3b>(j, i + current)[0];
						check[1] = result.at<Vec3b>(j, i + current)[1];
						check[2] = result.at<Vec3b>(j, i + current)[2];
						break;
					}
					else if (i - current >= 0 && j - current >= 0 && !(result.at<Vec3b>(j - current, i - current)[0] == 0 && result.at<Vec3b>(j - current, i - current)[1] == 0 && result.at<Vec3b>(j - current, i - current)[2] == 0)) {
						check[0] = result.at<Vec3b>(j - current, i - current)[0];
						check[1] = result.at<Vec3b>(j - current, i - current)[1];
						check[2] = result.at<Vec3b>(j - current, i - current)[2];
						break;
					}
					else if (i + current < result.size().width && j + current < result.size().height && !(result.at<Vec3b>(j + current, i + current)[0] == 0 && result.at<Vec3b>(j + current, i + current)[1] == 0 && result.at<Vec3b>(j + current, i + current)[2] == 0)) {
						check[0] = result.at<Vec3b>(j + current, i + current)[0];
						check[1] = result.at<Vec3b>(j + current, i + current)[1];
						check[2] = result.at<Vec3b>(j + current, i + current)[2];
						break;
					}
					else if (i - current >= 0 && j + current < result.size().height && !(result.at<Vec3b>(j + current, i - current)[0] == 0 && result.at<Vec3b>(j + current, i - current)[1] == 0 && result.at<Vec3b>(j + current, i - current)[2] == 0)) {
						check[0] = result.at<Vec3b>(j + current, i - current)[0];
						check[1] = result.at<Vec3b>(j + current, i - current)[1];
						check[2] = result.at<Vec3b>(j + current, i - current)[2];
						break;
					}
					else if (i + current < result.size().width && j - current >= 0 && !(result.at<Vec3b>(j - current, i + current)[0] == 0 && result.at<Vec3b>(j - current, i + current)[1] == 0 && result.at<Vec3b>(j - current, i + current)[2] == 0)) {
						check[0] = result.at<Vec3b>(j - current, i + current)[0];
						check[1] = result.at<Vec3b>(j - current, i + current)[1];
						check[2] = result.at<Vec3b>(j - current, i + current)[2];
						break;
					}
					current++;
				}
				result.at<Vec3b>(j, i)[0] = check[0];
				result.at<Vec3b>(j, i)[1] = check[1];
				result.at<Vec3b>(j, i)[2] = check[2];
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
