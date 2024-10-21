CMAKE_MINIMUM_REQUIRED(VERSION 3.0)
project(HeuristicSearch)
ADD_SUBDIRECTORY(googletest)

ADD_EXECUTABLE(runAllTests
    test.cpp
)

TARGET_LINK_LIBRARIES(runAllTests gtest)
target_link_libraries(runAllTests gmock gtest gtest_main)
TARGET_COMPILE_DEFINITIONS(runAllTests PRIVATE gtest_disable_pthreads=ON)