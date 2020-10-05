#include <opencv2/imgcodecs.hpp> //imread
#include <opencv2/highgui.hpp> //imshow
#include <opencv2/imgproc.hpp> //Canny

using namespace cv;

Mat img, canny;
/*
void sliderOnChange(int size, void*) {
	Canny(img, canny, (double)size, 500);
	imshow("window", canny);
};
*/
int main() {
	img = imread("gogh.jpg");
	imshow("window", img);

	// ラムダ函数で代用
	auto sliderOnChange = [](int size, void*) {
		Canny(img, canny, 30, (double)size);
		imshow("window", canny);
	};

	createTrackbar("slider1", "window", 0, 300, sliderOnChange);
	waitKey(0);

	return 0;
}
	
