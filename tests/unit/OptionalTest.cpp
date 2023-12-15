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

#include <string>

#include <gtest/gtest.h>

#include "cpp-utils/Optional.h"

using namespace nkhlab::cpputils;

struct CustomType
{
    bool b;
    int i;
    std::string s;
};

template <typename T>
void TestPrimitives(T value_to_test)
{
    Optional<T> op1, op2, op3;

    EXPECT_FALSE(op1);
    EXPECT_FALSE(op2);
    EXPECT_FALSE(op3);

    op2 = value_to_test;

    EXPECT_TRUE(op2);
    EXPECT_EQ(op2.Value(), value_to_test);

    op1 = op2;

    EXPECT_TRUE(op1);
    EXPECT_EQ(op1.Value(), value_to_test);

    op1 = op3;
    EXPECT_FALSE(op1);

    op2 = Optional<T>{};
    EXPECT_FALSE(op2);
}

template <typename T, typename ComparePredicate>
void TestCustomType(T value_to_test, ComparePredicate p)
{
    Optional<T> op1, op2, op3;

    EXPECT_FALSE(op1);
    EXPECT_FALSE(op2);
    EXPECT_FALSE(op3);

    op2 = value_to_test;

    EXPECT_TRUE(op2);
    EXPECT_TRUE(p(op2.Value(), value_to_test));

    op1 = op2;

    EXPECT_TRUE(op1);
    EXPECT_TRUE(p(op1.Value(), value_to_test));

    op1 = op3;
    EXPECT_FALSE(op1);

    op2 = Optional<T>{};
    EXPECT_FALSE(op2);
}

TEST(UtilsOptionalTest, BoolTest)
{
    TestPrimitives(true);
}

TEST(UtilsOptionalTest, IntTest)
{
    TestPrimitives(123);
}

TEST(UtilsOptionalTest, StringTest)
{
    TestPrimitives("string");
}

TEST(UtilsOptionalTest, CustomTypeTest)
{
    TestCustomType(CustomType{true, 123, "string"}, [](const CustomType& v1, const CustomType& v2) {
        return v1.b == v2.b && v1.i == v2.i && v1.s == v2.s;
    });
}

TEST(UtilsOptionalTest, ResetTest)
{
    Optional<int> opi;

    EXPECT_FALSE(opi);
    opi = 123;
    EXPECT_TRUE(opi);
    opi.Reset();
    EXPECT_FALSE(opi);
}