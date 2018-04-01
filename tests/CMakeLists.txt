project(CBS_Tests)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
add_executable(TESTS base_tests/ModelTests.cpp base_tests/FormTests.cpp ../src/base/forms.cpp ../src/base/forms.h ../src/users/models.cpp ../src/users/models.h)
target_link_libraries(TESTS gtest gtest_main)