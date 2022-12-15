cmake_minimum_required(VERSION 3.5)
project(Figures)
include_directories(../FigureDynamicLib/)
file(GLOB FIGURE_LIB_SOURCES "../FigureDynamicLib/*.cpp"
)
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON) 
add_library(FigureLib SHARED ../FigureDynamicLib/Figure.cpp ../FigureDynamicLib/Triangle.cpp ../FigureDynamicLib/AllFiguresInterface.cpp )
add_executable(Figures Figures.cpp)
target_link_libraries(Figures FigureLib)