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

TEST_F(ModelTestFixture, test_size_zero_after_save_and_delete) {
    Mock object = Mock();
    object.save();
    ASSERT_EQ(Mock::all().size(), 1);
    object.remove();
    ASSERT_EQ(Mock::all().size(), 0);
}

TEST_F(ModelTestFixture, test_size_one_with_save) {
    Mock object = Mock();
    object.save();
    ASSERT_EQ(Mock::all().size(), 1);
}
