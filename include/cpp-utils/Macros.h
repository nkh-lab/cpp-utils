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

#pragma once

//
// Suppress unused variable error
//
#define UNUSED(x) static_cast<void>(x)

//
// Get array size at compile time
//
// int ints[] = {1, 2, 3, 4, 5}; ARRAY_SIZE(ints) --> 5
//
template <typename T, size_t N>
constexpr size_t ARRAY_SIZE(T (&)[N])
{
    return N;
}