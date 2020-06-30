cmake_minimum_required(VERSION 3.15)

add_subdirectory(lib/googletest)
set(GTEST_SOURCE_DIR, ./lib/googletest)
include_directories(${GTEST_SOURCE_DIR}/include ${GTEST_SOURCE_DIR})

set(SOURCE_FILES
        mainTests.cpp
        TestImageProcessor.cpp
        TestExecutionTime.cpp
        TestPixelConversion.cpp
        TestCollision.cpp
        TestHero.cpp)

add_executable(runTests ${SOURCE_FILES})
target_link_libraries(runTests
        gtest gtest_main
        )