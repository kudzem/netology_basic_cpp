cmake_minimum_required(VERSION 3.10)
project(RaceGame)
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
set(VEHICLE_SOURCE_FILES "Vehicle.cpp" "Camel.cpp" "FastCamel.cpp" "Boots.cpp" "Centaur.cpp" "GroundVehicle.cpp" "CarpetPlane.cpp" "Eagle.cpp" "Broomstick.cpp")
add_library(RaceLib SHARED Race.cpp ${VEHICLE_SOURCE_FILES})
#add_compile_options(-std=c++17)
add_executable(RaceGame RaceGame.cpp)
target_link_libraries(RaceGame RaceLib)
