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

#include "cpp-utils/FileHelper.h"

using namespace nkhlab::cpputils;

TEST(FileHelperPathTest, AllInOneLinuxPath)
{
    constexpr char kFilePath[] = "/home/user/docs/file.txt";

    EXPECT_STREQ(FileHelper::GetDir(kFilePath).c_str(), "/home/user/docs/");
    EXPECT_STREQ(FileHelper::GetFileName(kFilePath).c_str(), "file.txt");
    EXPECT_STREQ(FileHelper::RemoveFileExtension(kFilePath).c_str(), "/home/user/docs/file");
}

TEST(FileHelperPathTest, AllInOneWindowsPath)
{
    constexpr char kFilePath[] = "c:\\user\\docs\\file.txt";

    EXPECT_STREQ(FileHelper::GetDir(kFilePath).c_str(), "c:\\user\\docs\\");
    EXPECT_STREQ(FileHelper::GetFileName(kFilePath).c_str(), "file.txt");
    EXPECT_STREQ(FileHelper::RemoveFileExtension(kFilePath).c_str(), "c:\\user\\docs\\file");
}