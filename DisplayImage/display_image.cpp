#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>

int main() {
	std::string image_path;
	std::cin >> image_path;
	cv::Mat img = cv::imread(image_path, cv::IMREAD_GRAYSCALE);

	if (img.empty()) {
		std::cout << "Could not read the image: " << image_path << std::endl;
		return 1;
	}

	cv::imshow("Display window", img);
	int k = cv::waitKey(0);

	if (k == 's') {
		cv::imwrite("starry_night.png", img);
	}

	return 0;
}
