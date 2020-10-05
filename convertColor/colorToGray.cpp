#include <opencv2/imgcodecs.hpp> //imread
#include <opencv2/highgui.hpp> //imshow
#include <opencv2/imgproc.hpp> //cvtColor

using namespace cv;
using namespace std;

int main() {
	Mat img = imread("gogh.jpg");
	Mat gray;
	cvtColor(img, gray, COLOR_BGR2GRAY);
	imshow("window", gray);
	waitKey(0);
}
