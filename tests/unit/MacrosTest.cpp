/*
 * Copyright (C) 2023 https://github.com/nkh-lab
 *
 * This is free software. You can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * version 3 as published by the Free Software Foundation.
 *
 * This software is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY.
 */

#include <gtest/gtest.h>

#include "cpputils/Macros.h"
#include "cpputils/StringHelper.h"

using namespace nkhlab::cpputils;

TEST(MacrosTest, ByteArraySize)
{
    uint8_t bytes[] = {0x00, 0x12, 0x34, 0x56, 0x78, 0x9A, 0xBC, 0xDE, 0xFF};

    EXPECT_EQ(9, ARRAY_SIZE(bytes));
}

TEST(MacrosTest, IntArraySize)
{
    int ints[] = {1, 2, 3, 4, 5};

    EXPECT_EQ(5, ARRAY_SIZE(ints));
}

struct MyType
{
    int i;
    char c;
    std::string s;
};

TEST(MacrosTest, CustomTypeArraySize)
{
    MyType my_array[] = {
        {1, 'a', "s1"}, {2, 'b', "s2"}, {3, 'c', "s3"}, {4, 'd', "s4"}, {5, 'e', "s5"}};

    EXPECT_EQ(5, ARRAY_SIZE(my_array));
}