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

TEST_F(ModelTestFixture, testSizeZeroWithoutSave) {
    Mock object = Mock();
    ASSERT_EQ(Mock::all().size(), 0);
}

TEST_F(ModelTestFixture, testSizeZeroAfterSaveAndDelete) {
    Mock object = Mock();
    object.save();
    ASSERT_EQ(Mock::all().size(), 1);
    object.remove();
    ASSERT_EQ(Mock::all().size(), 0);
}

TEST_F(ModelTestFixture, testSizeOneWithSave) {
    Mock object = Mock();
    object.save();
    ASSERT_EQ(Mock::all().size(), 1);
}

TEST_F(ModelTestFixture, testFindById){
    Mock object = Mock();
    object.save();
    ASSERT_EQ(object, *Mock::findById(1));
}

