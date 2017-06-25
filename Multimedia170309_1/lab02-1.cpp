/*
#include <opencv2/core/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui/highgui.hpp>

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
	Mat image2;
	float contrast, bias;
	
	std::cout << "contrast : ";
	std::cin >> contrast;
	std::cout << "cotrast is " << contrast;
	std::cout << "\nbias : ";
	std::cin >> bias;
	std::cout << "bias is " << bias;

	image = imread(imageName.c_str(), IMREAD_COLOR);
	image2 = imread(imageName.c_str(), IMREAD_COLOR);
	if (image.empty())
	{
		cout << "Could not open or find the image" << std::endl;
		return -1;
	}
	
	for (int i = 0; i < image2.size().width; i++) {
		for (int j = 0; j < image2.size().height; j++) {
			image2.at<Vec3b>(j, i)[0] = saturate_cast<uchar>(image2.at<Vec3b>(j, i)[0] * contrast + bias);
			image2.at<Vec3b>(j, i)[1] = saturate_cast<uchar>(image2.at<Vec3b>(j, i)[1] * contrast + bias);
			image2.at<Vec3b>(j, i)[2] = saturate_cast<uchar>(image2.at<Vec3b>(j, i)[2] * contrast + bias);
		}
	}
	//namedWindow("Display window : image 1", WINDOW_AUTOSIZE);
	imshow("DIsplay window : image 1", image);
	//namedWindow("Display window : image 2", WINDOW_AUTOSIZE);
	imshow("DIsplay window : image 2", image2);
	

	waitKey(0);
	return 0;
}
*/