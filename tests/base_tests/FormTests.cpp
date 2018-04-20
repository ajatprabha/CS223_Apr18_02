//
// Created by saksham on 2/4/18.
//

#include <base/models/BaseUser.h>
#include <base/forms/ModelForm.h>
#include <users/models/Admin.h>
#include <users/models/Professor.h>
#include "gtest/gtest.h"


class MockUserCreateForm : public ModelForm<BaseUser> {
public:
    MockUserCreateForm(const string &firstName, const string &lastName, const string &email, const string &password,
                       bool adminStatus);

    BaseUser &save() override;
    void clean() override;
private:
    string firstName, lastName, email, password;
    bool adminStatus;

};

void MockUserCreateForm::clean() {

    if (firstName.empty() || firstName.size() > 32) addError("invalid first name length");
    if (lastName.empty() || lastName.size() > 64) addError("invalid last name length");
    if (email.empty() || email.size() > 64) addError("invalid first name length");
    for (auto &it : BaseUser::all()) {
        if (it.second.getEmail() == email) addError("A user with this email already exists");
    }
    if (password.empty() || password.size() > 64) addError("invalid password length");
}



BaseUser &MockUserCreateForm::save(){

    BaseUser *temp;
    if (adminStatus) {
        temp = new Admin(firstName, lastName, email, password);
    } else {
        temp = new Professor(firstName, lastName, email, password);
    }
    temp->save();
    return *temp;
}


MockUserCreateForm::MockUserCreateForm(const string &firstName, const string &lastName, const string &email,
                                       const string &password, bool adminStatus) : firstName(firstName),
                                                                                   lastName(lastName), email(email),
                                                                                   password(password),
                                                                                   adminStatus(adminStatus) {}



class MockFormTestFixture : public ::testing::Test {
protected:
    void TearDown() override {}

    void SetUp() override {}

public:
    MockFormTestFixture() : Test() {}
};

TEST_F(MockFormTestFixture, testUserCreateForm) {
    MockUserCreateForm object("Saksham", "Banga", "admin2@admin.com", "password", true);
    if(object.isValid())
    {
        object.save();
        ASSERT_EQ(BaseUser::findByEmail("admin2@admin.com")->getFullName(),"Saksham Banga");
    }
    else
        ASSERT_EQ(1,0);//means test has certainly failed
}