#include <iostream>
#include <string>
#include <opencv2/imgproc.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>

using namespace cv;
using namespace std;

struct Parameters {
	double thresh;
	double maxval;
	int type;
};

int main(int argc, char** argv) {
	String filename;
	if (argc > 1) {
		filename = argv[1];
	}
	Mat img = imread(filename, IMREAD_COLOR);
	if (img.empty()) {
		cout << "Cannot read the image: " << filename << endl;
		return -1;
	}

	Mat img_gray;
	cvtColor(img, img_gray, COLOR_BGR2GRAY);
	
	namedWindow("convert/threshold", WINDOW_NORMAL);

	auto p = Parameters{30,255,THRESH_BINARY};

	Mat img_contour;
	threshold(img_gray, img_contour, p.thresh, 255, p.type);
	imshow("convert/threshold", img_contour);
	waitKey(0);
	return 0;
}
