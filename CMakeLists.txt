cmake_minimum_required(VERSION 3.10)

# Set the project name
project(ChecksumGenerator)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)

# Add the executable target (including both main.cpp and checksum.cpp)
add_executable(checksum src/main.cpp src/checksum.cpp)

# Include the headers from the "include" directory
target_include_directories(checksum PUBLIC include)

# Add unit tests (if any)
#enable_testing
