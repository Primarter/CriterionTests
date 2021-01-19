/*
** EPITECH PROJECT, 2020
** B-CPP-300-MPL-3-1-CPPD13-alec.ferrari
** File description:
** Picture_tests.cpp
*/

#include "criterion/criterion.h"
#include "criterion/redirect.h"
#include <cassert>
#include <assert.h>
#include <iostream>
#include "../ex05/Picture.hpp"

Test(init_picture, test_default_constructor)
{
    Picture pic;
    cr_assert_str_empty(pic.data.c_str(), "Data of picture isn't empty after default construction");
}

Test(init_picture, test_copy_constructor)
{
    Picture pic;
    pic.data = "AZERTY";
    Picture copy(pic);
    cr_assert_str_eq(copy.data.c_str(), "AZERTY", "Data of picture isn't AZERTY after copy construction");
}

Test(init_picture, test_file_constructor)
{
    Picture pic("./tests/test.txt");

    cr_assert_str_eq(pic.data.c_str(), "TEST ASCII\n", "Data of picture is different from the file");
}


Test(init_picture, test_error_constructor)
{
    Picture pic("unknown");

    cr_assert_str_eq(pic.data.c_str(), "ERROR", "Error message not correct");
}

Test(assign_picture, test_assignment_operator)
{
    Picture pic;
    Picture filled("./tests/test.txt");

    pic = filled;
    cr_assert_str_eq(pic.data.c_str(), "TEST ASCII\n", "Data of picture is different from the assigned:\n assigned: [%s], [TEST ASCII]", pic.data.c_str());
}

Test(assign_picture, test_getPictureFromFile)
{
    Picture pic;

    pic.getPictureFromFile("./tests/test.txt");
    cr_assert_str_eq(pic.data.c_str(), "TEST ASCII\n", "Data of picture was not assigned");
}