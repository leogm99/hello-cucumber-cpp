cmake_minimum_required(VERSION 3.16)

set(CMAKE_CXX_STANDARD 20)

project(hello_cucumber_cpp)

find_package(GTest)
find_package(Boost COMPONENTS thread unit_test_framework system regex date_time program_options filesystem REQUIRED)

include_directories(~/Escritorio/aninfo/cucumber/cucumber-cpp/include/)
include_directories(~/Escritorio/aninfo/cucumber/cucumber-cpp/build/src/)

add_executable(GTestCalculatorSteps features/step_definitions/GTestSetOperatorSteps.cpp)
target_link_libraries(GTestCalculatorSteps PRIVATE libcucumber-cpp.a Boost::unit_test_framework Boost::regex Boost::system Boost::filesystem Boost::program_options libcucumber-cpp.a GTest::GTest)

