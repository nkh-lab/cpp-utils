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

#include "cpp-utils/ChronoHelper.h"

using namespace nkhlab::cpputils;

TEST(UtilsChronoHelperTest, AllInOne)
{
    std::chrono::milliseconds ms{1};
    std::chrono::seconds s{1};
    std::chrono::minutes min{1};
    std::chrono::hours h{1};

    EXPECT_STREQ("ms", ChronoHelper::GetUnitType(ms));
    EXPECT_STREQ("s", ChronoHelper::GetUnitType(s));
    EXPECT_STREQ("min", ChronoHelper::GetUnitType(min));
    EXPECT_STREQ("h", ChronoHelper::GetUnitType(h));
}