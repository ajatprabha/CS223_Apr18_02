project(CBS_Tests)

include_directories(../code/base)
link_directories(../code/base)

include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
add_executable(TESTS base_tests/ModelTests.cpp base_tests/FormTests.cpp)
target_link_libraries(TESTS gtest gtest_main BaseLib)