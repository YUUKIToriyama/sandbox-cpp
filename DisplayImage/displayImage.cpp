#include <iostream>
#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;

int main(int argc, char** argv) {
	if (argc != 2) {
		cout << "usage: ./diplayImage <image_path>" << endl;
		return -1;
	}

	Mat image;
	image = imread(argv[1], 1);

	if (!image.data) {
		cout << "No image data" << endl;
		return -1;
	}

	namedWindow("DisplayImage", WINDOW_AUTOSIZE);
	imshow("DisplayImage", image);

	waitKey(0);
	return 0;
}
