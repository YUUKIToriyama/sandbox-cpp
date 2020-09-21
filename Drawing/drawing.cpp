#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>

using namespace std;
using namespace cv;

Mat image = Mat::zeros(500, 500, CV_8UC3);

void mouseEventCallback(int event, int x, int y, int flag, void* userdata) {
	cout << "Position: " << x << ", " << y << endl;
	circle(image, Point(x,y), 10, cv::Scalar(255,255,255), 2, cv::LINE_8);
	imshow("myWindow", image);
}

int main(void) {
	line(image, Point(100,100), Point(400,400), Scalar(255,255,255), 2, LINE_8);
	circle(image, Point(250,250), 100, Scalar(255,255,0), 2, LINE_8);
	rectangle(image, Point(125,125), Point(375,375), Scalar(255,0,255), 2, LINE_8);
	namedWindow("myWindow", WINDOW_AUTOSIZE);
	setMouseCallback("myWindow", mouseEventCallback, NULL);
	imshow("myWindow", image);

	waitKey(0);
	return 0;
}
