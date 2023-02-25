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

#include <cstdio>

#include <gtest/gtest.h>

#include "cpp-utils/FileHelper.h"

using namespace nkhlab::cpputils;

namespace {
constexpr char kFileForTest[] = "./file.txt";
}

class FileHelperTest : public ::testing::Test
{
protected:
    void SetUp() override { std::remove(kFileForTest); }

    void TearDown() override { std::remove(kFileForTest); }
};

TEST_F(FileHelperTest, CheckFileExistence)
{
    EXPECT_FALSE(FileHelper::ExistFile(kFileForTest));

    FileHelper::WriteFile(kFileForTest, "");

    EXPECT_TRUE(FileHelper::ExistFile(kFileForTest));
}

TEST_F(FileHelperTest, ReadNonExistentFile)
{
    EXPECT_TRUE(FileHelper::ReadFile(kFileForTest).str().empty());
}

TEST_F(FileHelperTest, WriteReadFile)
{
    constexpr char c_str[] = "Hello World!";

    FileHelper::WriteFile(kFileForTest, c_str);

    EXPECT_STREQ(c_str, FileHelper::ReadFile(kFileForTest).str().c_str());
}

TEST_F(FileHelperTest, OverwriteFile)
{
    constexpr char c_str[] = "Hello World!";

    FileHelper::WriteFile(kFileForTest, c_str);

    EXPECT_STREQ(c_str, FileHelper::ReadFile(kFileForTest).str().c_str());

    constexpr char c_str_new[] = "New content";

    FileHelper::WriteFile(kFileForTest, c_str_new);

    EXPECT_STREQ(c_str_new, FileHelper::ReadFile(kFileForTest).str().c_str());
}