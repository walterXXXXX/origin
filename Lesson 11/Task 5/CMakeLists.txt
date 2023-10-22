cmake_minimum_required(VERSION 3.22.0)
project(Figures)
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON) 
add_library(FiguresLib SHARED Figures/equilateralTriangle.h Figures/equilateralTriangle.cpp
Figures/figure.h Figures/figure.cpp Figures/isoscelesTriangle.h Figures/isoscelesTriangle.cpp
Figures/parallelogram.h Figures/parallelogram.cpp Figures/quadrangle.h Figures/quadrangle.cpp
Figures/rectangle.h Figures/rectangle.cpp Figures/rectangularTriangle.h Figures/rectangularTriangle.cpp
Figures/rhomb.h Figures/rhomb.cpp Figures/square.h Figures/square.cpp Figures/triangle.h Figures/triangle.cpp)
add_executable(Figures main.cpp)
target_link_libraries(Figures FiguresLib)