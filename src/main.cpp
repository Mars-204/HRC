#include <opencv2/opencv.hpp>
#include <iostream>
#include <filesystem>
#include "ImageProcessor.hpp"

namespace fs = std::filesystem;

int main(int argc, char** argv) {
    if (argc != 3) {
        std::cerr << "Usage: ./DepthImageDifference <depth_image1> <depth_image2>" << std::endl;
        return -1;
    }

    fs::path imagePath1 = argv[1];
    fs::path imagePath2 = argv[2];

    if (!fs::exists(imagePath1) || !fs::exists(imagePath2)) {
        std::cerr << "One or both image files do not exist!" << std::endl;
        return -1;
    }

    cv::Mat depthImage1 = cv::imread(imagePath1.string(), cv::IMREAD_UNCHANGED);
    cv::Mat depthImage2 = cv::imread(imagePath2.string(), cv::IMREAD_UNCHANGED);

    if (depthImage1.empty() || depthImage2.empty()) {
        std::cerr << "Error loading images!" << std::endl;
        return -1;
    }

    if (depthImage1.size() != depthImage2.size()) {
        std::cerr << "Images must be of the same size!" << std::endl;
        return -1;
    }

    cv::Mat differenceImage = ImageProcessor::computeDifference(depthImage1, depthImage2);
    cv::Mat erodedImage = ImageProcessor::applyErosion(differenceImage);

    cv::imshow("Depth Image 1", depthImage1);
    cv::imshow("Depth Image 2", depthImage2);
    cv::imshow("Difference Image", differenceImage);
    cv::imshow("Eroded Image", erodedImage);

    cv::waitKey(0);

    return 0;
}
