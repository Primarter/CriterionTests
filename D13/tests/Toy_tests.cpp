/*
** EPITECH PROJECT, 2020
** B-CPP-300-MPL-3-1-CPPD13-alec.ferrari
** File description:
** Toy_tests.cpp
*/

#include "criterion/criterion.h"
#include "criterion/redirect.h"
#include <cassert>
#include <assert.h>
#include <iostream>
#include "../ex05/Toy.hpp"

Test(init_toy, test_default_constructor)
{
    Toy toy;
    cr_assert_str_eq(toy.getName().c_str(), "toy", "Default name is wrong");
    cr_assert_str_empty(toy.getAscii().c_str(), "Default Ascii isn't empty");
    cr_assert(toy.getType() == Toy::BASIC_TOY, "toy isn't BASIC_TOY");
    Toy::Error err = toy.getLastError();
    cr_assert_str_empty(err.what().c_str(), "Default Ascii isn't empty");
    cr_assert_str_empty(err.where().c_str(), "Default Ascii isn't empty");
    cr_assert(err.type == Toy::Error::UNKNOWN, "Default Error type doesn't match");
}

Test(init_toy, test_normal_constructor)
{
    Toy toy(Toy::ALIEN, "ET", "./tests/test.txt");
    cr_assert_str_eq(toy.getName().c_str(), "ET", "Name is wrong");
    cr_assert_str_eq(toy.getAscii().c_str(), "TEST ASCII\n", "Ascii is wrong");
    cr_assert(toy.getType() == Toy::ALIEN, "toy isn't ALIEN");
    Toy::Error err = toy.getLastError();
    cr_assert_str_empty(err.what().c_str(), "Default error what isn't empty");
    cr_assert_str_empty(err.where().c_str(), "Default error where isn't empty");
    cr_assert(err.type == Toy::Error::UNKNOWN, "Default Error type doesn't match");
}

Test(init_toy, test_error_constructor)
{
    Toy toy(Toy::ALIEN, "ET", "unknown");
    cr_assert_str_eq(toy.getName().c_str(), "ET", "Name is wrong");
    cr_assert_str_eq(toy.getAscii().c_str(), "ERROR", "Ascii isn't ERROR");
    cr_assert(toy.getType() == Toy::ALIEN, "toy isn't ALIEN");
}

// Test(init_toy, test_copy_constructor)
// {
//     Picture pic;
//     pic.data = "AZERTY";
//     Picture copy(pic);
//     cr_assert_str_eq(copy.data.c_str(), "AZERTY", "Data of picture isn't AZERTY after copy construction");
// }

// Test(init_toy, test_file_constructor)
// {
//     Picture pic("./tests/test.txt");

//     cr_assert_str_eq(pic.data.c_str(), "TEST ASCII\n", "Data of picture is different from the file");
// }

// Test(assign_picture, test_assignment_operator)
// {
//     Picture pic;
//     Picture filled("./tests/test.txt");

//     pic = filled;
//     cr_assert_str_eq(pic.data.c_str(), "TEST ASCII\n", "Data of picture is different from the assigned:\n assigned: [%s], [TEST ASCII]", pic.data.c_str());
// }

// Test(assign_picture, test_getPictureFromFile)
// {
//     Picture pic;

//     pic.getPictureFromFile("./tests/test.txt");
//     cr_assert_str_eq(pic.data.c_str(), "TEST ASCII\n", "Data of picture was not assigned");
// }