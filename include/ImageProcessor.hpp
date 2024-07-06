#ifndef IMAGEPROCESSOR_HPP
#define IMAGEPROCESSOR_HPP

#include <opencv2/opencv.hpp>

class ImageProcessor {
public:
    static cv::Mat computeDifference(const cv::Mat& img1, const cv::Mat& img2);
    static cv::Mat applyErosion(const cv::Mat& img, int erosionSize = 2);
};

#endif // IMAGEPROCESSOR_HPP