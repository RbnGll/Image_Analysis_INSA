cmake_minimum_required(VERSION 3.14)
project(Projet_OpenCV_CMake)


set(CMAKE_CXX_STANDARD 14)
find_package(OpenCV REQUIRED)

include_directories(include ${OpenCV_INCLUDE_DIRS})
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")

add_executable(Projet_OpenCV_CMake
        include/histogram.hpp
        src/histogram.cpp
        src/main_test_opencv.cpp
        src/thresholding.cpp include/thresholding.h
        src/matcher.cpp include/matcher.h
        src/SquareExtractor.cpp include/SquareExtractor.h
        
        src/cross_detector.cpp include/cross_detector.h
        src/reformat_image.cpp include/reformat_image.h)

target_link_libraries(Projet_OpenCV_CMake ${OpenCV_LIBS})

