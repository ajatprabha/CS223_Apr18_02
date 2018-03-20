//
// Created by ajatprabha on 20/3/18.
//

#include "gtest/gtest.h"
#include "../../src/base/models.h"


class Mock : public Model<Mock> {

};


class ModelTestFixture : public ::testing::Test {
protected:
    void TearDown() override {}

    void SetUp() override {}

public:
    ModelTestFixture() : Test() {}
};

TEST_F(ModelTestFixture, test_size_zero_without_save) {
    Mock object = Mock();
    ASSERT_EQ(Mock::all().size(), 0);
}

TEST(BASIC_CHECK, test_eq) {
    ASSERT_EQ(1, 1);
}
