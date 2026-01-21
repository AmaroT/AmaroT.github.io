cmake_minimum_required(VERSION 3.10)
project(LinkedList)

# Set the C++ standard to C++11
set(CMAKE_CXX_STANDARD 11)

# Add the executable target
add_executable(LinkedList LinkedList.cpp CSVparser.cpp)

