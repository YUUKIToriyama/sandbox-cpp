#include <iostream>
#include <random>
#include <opencv2/opencv.hpp>
using namespace cv;

int drawingRandomLines(Mat image, RNG rng, int n) {
	Point pt1, pt2;
	Scalar color(255,255,255);
	for (int i = 0; i < n; i++) {
		pt1.x = rng.uniform(0,10) * 100;
		pt1.y = rng.uniform(0,10) * 100;
		pt2.x = rng.uniform(0,10) * 100;
		pt2.y = rng.uniform(0,10) * 100;
		line(image, pt1, pt2, color, 2, 8);
	}
	imshow("show image...", image);
	waitKey(0);
	return 0;
}

int main() {
	Mat image = Mat::zeros(1000, 1000, CV_8UC3);
	std::random_device rnd;
	RNG rng(rnd());
	drawingRandomLines(image, rng, 20);
	return 0;
}
