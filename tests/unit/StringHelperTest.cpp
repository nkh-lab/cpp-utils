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

#include "cpp-utils/Macros.h"
#include "cpp-utils/StringHelper.h"

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

TEST(StringHelperTest, GetStrFromBytesWithRightSize)
{
    uint8_t bytes[] = {0x12, 'a', 'b', 'c', 0x55, 0x00, 0x9A};

    std::string s = StringHelper::GetStrFromBytes(&bytes[1], 3);

    EXPECT_STREQ(s.c_str(), "abc");
}

TEST(StringHelperTest, GetStrFromBytesNullTerminated)
{
    uint8_t bytes[] = {0x12, 'a', 'b', 'c', 0x00, 0x00, 0x00, 0x00};

    std::string s = StringHelper::GetStrFromBytes(&bytes[1], 6);

    EXPECT_STREQ(s.c_str(), "abc");
}

TEST(StringHelperTest, WstrToStrNormalUse)
{
    constexpr const wchar_t* ws = L"Hello World!";

    std::string s = StringHelper::WstrToStr(ws);

    EXPECT_STREQ(s.c_str(), "Hello World!");
}

TEST(StringHelperTest, WstrToStrNullptr)
{
    std::string s = StringHelper::WstrToStr(nullptr);

    EXPECT_TRUE(s.empty());
}

TEST(StringHelperTest, Sprintf)
{
    std::string s = StringHelper::Sprintf("bool: %d, int: %d, str: %s", true, 123, "Hello World!");

    EXPECT_STREQ(s.c_str(), "bool: 1, int: 123, str: Hello World!");
}

TEST(StringHelperTest, SprintfLimits)
{
    std::string fs(511, '0');
    fs.append("%d");
    std::string gs(511, '0');
    gs.append("1");

    std::string s = StringHelper::Sprintf(fs.c_str(), 1);

    EXPECT_STREQ(s.c_str(), gs.c_str());
}

TEST(StringHelperTest, SplitStr)
{
    std::string string_with_spaces("This is a string with spaces");
    std::string string_with_spaces_extra(" This  is a string     with spaces    ");
    std::string string_with_commas("This,is,a,string,with,commas");
    ;
    std::string string_with_commas_extra(",This,,,,is,,,,a,string,,,with,commas,");

    std::vector<std::string> strings;

    strings.clear();
    strings = StringHelper::SplitStr(string_with_spaces, " ");
    EXPECT_EQ(strings.size(), 6);
    EXPECT_STREQ(strings[0].c_str(), "This");
    EXPECT_STREQ(strings[1].c_str(), "is");
    EXPECT_STREQ(strings[2].c_str(), "a");
    EXPECT_STREQ(strings[3].c_str(), "string");
    EXPECT_STREQ(strings[4].c_str(), "with");
    EXPECT_STREQ(strings[5].c_str(), "spaces");

    strings.clear();
    strings = StringHelper::SplitStr(string_with_spaces, " ", false);
    EXPECT_EQ(strings.size(), 6);

    strings.clear();
    strings = StringHelper::SplitStr(string_with_spaces_extra, " ");
    EXPECT_EQ(strings.size(), 6);
    EXPECT_STREQ(strings[0].c_str(), "This");
    EXPECT_STREQ(strings[1].c_str(), "is");
    EXPECT_STREQ(strings[2].c_str(), "a");
    EXPECT_STREQ(strings[3].c_str(), "string");
    EXPECT_STREQ(strings[4].c_str(), "with");
    EXPECT_STREQ(strings[5].c_str(), "spaces");

    strings.clear();
    strings = StringHelper::SplitStr(string_with_spaces_extra, " ", false);
    EXPECT_EQ(strings.size(), 16);

    strings.clear();
    strings = StringHelper::SplitStr(string_with_commas, ",");
    EXPECT_EQ(strings.size(), 6);
    EXPECT_STREQ(strings[0].c_str(), "This");
    EXPECT_STREQ(strings[1].c_str(), "is");
    EXPECT_STREQ(strings[2].c_str(), "a");
    EXPECT_STREQ(strings[3].c_str(), "string");
    EXPECT_STREQ(strings[4].c_str(), "with");
    EXPECT_STREQ(strings[5].c_str(), "commas");

    strings.clear();
    strings = StringHelper::SplitStr(string_with_commas, ",", false);
    EXPECT_EQ(strings.size(), 6);

    strings.clear();
    strings = StringHelper::SplitStr(string_with_commas_extra, ",");
    EXPECT_EQ(strings.size(), 6);
    EXPECT_STREQ(strings[0].c_str(), "This");
    EXPECT_STREQ(strings[1].c_str(), "is");
    EXPECT_STREQ(strings[2].c_str(), "a");
    EXPECT_STREQ(strings[3].c_str(), "string");
    EXPECT_STREQ(strings[4].c_str(), "with");
    EXPECT_STREQ(strings[5].c_str(), "commas");

    strings.clear();
    strings = StringHelper::SplitStr(string_with_commas_extra, ",", false);
    EXPECT_EQ(strings.size(), 16);
}