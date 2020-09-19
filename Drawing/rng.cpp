#include <iostream>
#include <random>
#include <opencv2/opencv.hpp>

int main() {
	std::random_device rnd;
	cv::RNG rng(rnd());
	std::cout << rng.uniform(0,10) << std::endl;
	return 0;
}
