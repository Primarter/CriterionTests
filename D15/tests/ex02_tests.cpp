/*
** EPITECH PROJECT, 2020
** B-CPP-300-MPL-3-1-CPPD15-alec.ferrari
** File description:
** ex02_tests.cpp
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <cassert>
#include <assert.h>
#include <iostream>
#include "../ex02/ex02.hpp"

Test(min_template, should_return_a)
{
    cr_assert(min<char>('a', 'z') == 'a', "min<char>('a', 'z') isn't 'a'");
}

Test(min_template, should_return_b)
{
    cr_assert(min<char>('y', 'b') == 'b', "min<char>('y', 'b') isn't 'b'");
}

Test(min_not_template, should_return_one)
{
    cr_assert(min(1, 3) == 1, "min(1, 3) isn't 1");
}

Test(min_not_template, should_return_2)
{
    cr_assert(min(3, 2) == 2, "min(3, 2) isn't 2");
}

Test(templateMin_tab, should_return_zero)
{
    int tab[2] = {4, 0};
    cr_assert(templateMin<int>(tab, 2) == 0, "templateMin<int>(tab, 2) isn't 0");
}

Test(nonTemplateMin_tab, should_return_zero)
{
    int tab[2] = {4, 0};
    cr_assert(nonTemplateMin(tab, 2) == 0, "templateMin<int>(tab, 2) isn't 0");
}