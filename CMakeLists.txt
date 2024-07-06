cmake_minimum_required(VERSION 3.30)
project(HRC)

set(CMAKE_CXX_STANDARD 17)
# Manually specify OpenCV paths if not found automatically
set(OpenCV_DIR "C:/opencv/build")
set(OpenCV_INCLUDE_DIRS "C:/opencv/build/include")
set(OpenCV_LIB_DIR "C:/opencv/build/x64/vc16/lib")

find_package( OpenCV REQUIRED )

include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(HRC src/main.cpp src/ImageProcessor.cpp)
target_link_libraries(HRC ${OpenCV_LIBS})
