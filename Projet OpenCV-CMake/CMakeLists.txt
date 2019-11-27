cmake_minimum_required(VERSION 3.14)
project(Projet_OpenCV_CMake)


set(CMAKE_CXX_STANDARD 14)
find_package(OpenCV REQUIRED)

include_directories(include ${OpenCV_INCLUDE_DIRS})


add_executable(Projet_OpenCV_CMake
        include/histogram.hpp
        src/histogram.cpp
<<<<<<< HEAD
        src/connected.cpp
        include/connected.h)
=======
        src/main_test_opencv.cpp src/thresholding.cpp include/thresholding.h)
>>>>>>> refs/remotes/origin/master

target_link_libraries(Projet_OpenCV_CMake ${OpenCV_LIBS})

