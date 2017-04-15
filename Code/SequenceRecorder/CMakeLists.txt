cmake_minimum_required(VERSION 3.6)
project(SequenceRecorder)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")



set(SOURCE_FILES
    Samples/click.h
    Samples/piano.h)

add_executable(SequenceRecorder ${SOURCE_FILES})