#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>

using namespace cv;

int main(void) {
	Mat image = Mat::zeros(500, 500, CV_8UC3);
	line(image, Point(100,100), Point(400,400), Scalar(255,255,255), 2, LINE_8);
	circle(image, Point(250,250), 100, Scalar(255,255,0), 2, LINE_8);
	rectangle(image, Point(125,125), Point(375,375), Scalar(255,0,255), 2, LINE_8);
	imshow("drawing...", image);

	waitKey(0);
	return 0;
}
