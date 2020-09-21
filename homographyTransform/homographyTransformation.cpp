#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>


cv::Mat image;
std::vector<cv::Point2f> points;
int i = 0;
int WIDTH = 500;
int HEIGHT = 500;

cv::Mat homographyTransformation(std::vector<cv::Point2f> v, cv::Mat img) {
	std::vector<cv::Point2f> projectionPoint2fs = {
		cv::Point2f(0,0),
		cv::Point2f(WIDTH, 0),
		cv::Point2f(WIDTH, HEIGHT),
		cv::Point2f(0,  HEIGHT)
	};

	cv::Mat homographyMatrix = cv::getPerspectiveTransform(v, projectionPoint2fs);
	cv::Mat outputImage = cv::Mat::zeros(WIDTH, HEIGHT, 8);
	cv::warpPerspective(img, outputImage, homographyMatrix, outputImage.size());

	return outputImage;
}


void eventCallback(int event, int x, int y, int flags, void* userdata) {
	if (event == cv::EVENT_LBUTTONDOWN) {
		std::cout << "position: " << x << "," << y << std::endl;
		cv::circle(image, cv::Point2f(x,y), 10, cv::Scalar(255,255,255), 2, cv::LINE_8);
		points.push_back(cv::Point2f(x,y));
		if (4 > i && i > 0) {
			cv::line(image, points[i-1], points[i], cv::Scalar(0,255,255), 2);
			if (i == 3) {
				cv::line(image, points[3], points[0], cv::Scalar(255,255,0), 2);
				cv::Mat output = homographyTransformation(points, image);
				cv::imshow("result", output);
				cv::waitKey(0);
				cv::imwrite("aaa.png", output);
			}
		}
		i++;
		
		if (points.size() == 4) {
			std::cout << points << std::endl;
		}
	}
}

int main(int argc, char **argv) {
	if (argc < 2) {
		std::cout << "Usage: ./command [input_file]" << std::endl;
		return -1;
	} else {
		std::string inputFileName = argv[1];
		image = cv::imread(inputFileName, cv::IMREAD_COLOR);
	}

	cv::namedWindow("myWindow", cv::WINDOW_AUTOSIZE);
	while (true) {
		cv::imshow("myWindow", image);
		cv::setMouseCallback("myWindow", eventCallback, NULL);
		int key = cv::waitKey(1);
		if (key != -1) {
			break;
		}
	}
	return 0;
}
