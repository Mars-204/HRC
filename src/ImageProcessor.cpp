#include "ImageProcessor.hpp"

cv::Mat ImageProcessor::computeDifference(const cv::Mat& img1, const cv::Mat& img2) {
    cv::Mat differenceImage;
    cv::absdiff(img1, img2, differenceImage);
    return differenceImage;
}

cv::Mat ImageProcessor::applyErosion(const cv::Mat& img, int erosionSize) {
    cv::Mat element = cv::getStructuringElement(cv::MORPH_RECT,
                                                cv::Size(2 * erosionSize + 1, 2 * erosionSize + 1),
                                                cv::Point(erosionSize, erosionSize));
    cv::Mat erodedImage;
    cv::erode(img, erodedImage, element);
    return erodedImage;
    
}
