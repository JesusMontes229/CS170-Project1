CMAKE_MINIMUM_REQUIRED(VERSION 3.2)
project(HeuristicSearch)
ADD_SUBDIRECTORY(googletest)

ADD_EXECUTABLE(runAllTests
    test.cpp
    ../src/main.cpp
)

TARGET_LINK_LIBRARIES(runAllTests gtest)

TARGET_COMPILE_DEFINITIONS(runAllTests PRIVATE gtest_disable_pthreads=ON)