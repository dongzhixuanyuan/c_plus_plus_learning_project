cmake_minimum_required(VERSION 3.17)
project(practice_project)

set(CMAKE_CXX_STANDARD 14)

add_executable(practice_project json.hh main.cpp OperateRecord.cpp OperateRecord.h NegativeFeedbackController.cpp NegativeFeedbackController.h util/Util.cpp util/Util.h)