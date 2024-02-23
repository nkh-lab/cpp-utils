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

#include <thread>

#include <gtest/gtest.h>

#include "cpp-utils/Synchronized.h"

using namespace nkhlab::cpputils;

constexpr int kOneRunSize = 100000;

void IncrementNotSynchronizedSharedCounter(int& shared_counter)
{
    for (int i = 0; i < kOneRunSize; ++i)
    {
        ++shared_counter;
    }
}

void IncrementSynchronizedSharedCounter(Synchronized<int>& shared_counter)
{
    for (int i = 0; i < kOneRunSize; ++i)
    {
        auto l = shared_counter.GetLock();
        ++shared_counter.Get();
    }
}

//
// Comment out if it fails as it could theoretically fail
//
// TEST(SynchronizedTest, NotSynchronizedSharedCounter)
// {
//     int i = 0;
//
//     std::thread t1(IncrementNotSynchronizedSharedCounter, std::ref(i));
//     std::thread t2(IncrementNotSynchronizedSharedCounter, std::ref(i));
//
//     t1.join();
//     t2.join();
//
//     EXPECT_NE(i, kOneRunSize * 2);
// }
//

TEST(SynchronizedTest, SynchronizedSharedCounter)
{
    Synchronized<int> i(int{0});

    std::thread t1(IncrementSynchronizedSharedCounter, std::ref(i));
    std::thread t2(IncrementSynchronizedSharedCounter, std::ref(i));

    t1.join();
    t2.join();

    EXPECT_EQ(i.Get(), kOneRunSize * 2);
}