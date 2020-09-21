#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <opencv2/opencv.hpp>

int main(int argc, char **argv) {
	if (argc < 4) {
		std::cout << "Usage: ./rotateImage [input_file] [angle] [output_file]" << std::endl;
		return -1;
	} else {
		std::string inputFileName = argv[1];
		float angle = atof(argv[2]); // 回転の角度
		std::string outputFileName = argv[3];

		cv::Mat inputImage = cv::imread(inputFileName);
		cv::Mat outputImage = cv::Mat::zeros(inputImage.size(), inputImage.type());

		cv::Point center = cv::Point(inputImage.cols / 2, inputImage.rows / 2); // 座標変換の中心設定
		float scale = 1; // 拡大縮小率

		cv::Mat affineMatrix = cv::getRotationMatrix2D(center, angle, scale);
		cv::warpAffine(inputImage, outputImage, affineMatrix, outputImage.size());

		cv::imwrite(outputFileName, outputImage);

		return 0;
	}

}
