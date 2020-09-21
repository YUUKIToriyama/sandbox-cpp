#include <iostream>
#include <string>
#include <vector>
#include <opencv2/opencv.hpp>

const int WIDTH = 500;
const int HEIGHT = 500;

int main(int argc, char **argv) {
	if (argc < 2) {
		std::cout << "Usage: " << std::endl;
		return -1;
	} else {
		std::string inputFileName = argv[1];
		std::string outputFileName = argv[2];

		cv::Mat inputImage = cv::imread(inputFileName);
		cv::Mat outputImage = cv::Mat::zeros(WIDTH, HEIGHT, 5);

		std::vector<cv::Point2f> pointsBefore = {
			cv::Point2f(401, 1202),
			cv::Point2f(1681, 1113),
			cv::Point2f(1778, 2534),
			cv::Point2f(645, 2394)
		};
		std::vector<cv::Point2f> pointsAfter = {
			cv::Point2f(0,0),
			cv::Point2f(WIDTH, 0),
			cv::Point2f(WIDTH, HEIGHT),
			cv::Point2f(0, HEIGHT)
		};

		cv::Mat homographyMatrix = cv::getPerspectiveTransform(pointsBefore, pointsAfter);
		cv::warpPerspective(inputImage, outputImage, homographyMatrix, outputImage.size());

		cv::imwrite(outputFileName, outputImage);
		return 0;
	}
}
