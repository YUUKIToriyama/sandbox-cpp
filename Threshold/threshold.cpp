#include <iostream>
#include <string>
#include <opencv2/imgproc.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>

using namespace cv;
using namespace std;

int threshold_value = 200;
int threshold_type = 3;

int main(int argc, char** argv) {
	String imageName;
	if (argc > 1) {
		imageName = argv[1];
	}
	cin >> threshold_value;
	Mat src = imread(samples::findFile(imageName), IMREAD_COLOR);
	if (src.empty()) {
		cout << "Cannot read the image: " << imageName << std::endl;
		return -1;
	}

	Mat src_gray;
	cvtColor(src, src_gray, COLOR_BGR2GRAY);
	namedWindow("image show", WINDOW_AUTOSIZE);
	
	Mat dst;
	threshold(src_gray, dst, threshold_value, 255, threshold_type);
	imshow("threshold", dst);
	waitKey();
	return 0;
}
