#check cmake version
cmake_minimum_required(VERSION 2.8)

set(HEADER_FILES csstats/csstats.cpp)
add_executable(example example.cpp ${HEADER_FILES})
