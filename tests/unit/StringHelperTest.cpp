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

TEST(StringHelperTest, BytesToStrWithDefaultSettings)
{
    uint8_t bytes[] = {0x00, 0x12, 0x34, 0x56, 0x78, 0x9A, 0xBC, 0xDE, 0xFF};

    std::string s = StringHelper::BytesToStr(bytes, ARRAY_SIZE(bytes));

    EXPECT_STREQ(s.c_str(), "00 12 34 56 78 9a bc de ff");
}

TEST(StringHelperTest, BytesToStrNoDelimiter)
{
    uint8_t bytes[] = {0x00, 0x12, 0x34, 0x56, 0x78, 0x9A, 0xBC, 0xDE, 0xFF};

    std::string s = StringHelper::BytesToStr(bytes, ARRAY_SIZE(bytes), "");

    EXPECT_STREQ(s.c_str(), "00123456789abcdeff");
}

TEST(StringHelperTest, BytesToStrCustomDelimiter)
{
    uint8_t bytes[] = {0x00, 0x12, 0x34, 0x56, 0x78, 0x9A, 0xBC, 0xDE, 0xFF};

    std::string s = StringHelper::BytesToStr(bytes, ARRAY_SIZE(bytes), "--");

    EXPECT_STREQ(s.c_str(), "00--12--34--56--78--9a--bc--de--ff");
}

TEST(StringHelperTest, BytesToStrWithAllCustomSettings)
{
    uint8_t bytes[] = {0x00, 0x12, 0x34, 0x56, 0x78, 0x9A, 0xBC, 0xDE, 0xFF};

    std::string s = StringHelper::BytesToStr(bytes, ARRAY_SIZE(bytes), "--", true, true);

    EXPECT_STREQ(s.c_str(), "0x00--0x12--0x34--0x56--0x78--0x9A--0xBC--0xDE--0xFF");
}