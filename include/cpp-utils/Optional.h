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

#include <atomic>
#include <chrono>
#include <functional>
#include <thread>

namespace nkhlab {
namespace cpputils {

template <typename T>
class Optional
{
public:
    Optional()
        : has_value_{false}
        , value_{}
    {
    }
    explicit Optional(const T& value)
        : has_value_{true}
        , value_{value}
    {
    }

    operator bool() const { return has_value_; }

    T Value() const { return value_; }

    Optional<T>& operator=(const T& value)
    {
        has_value_ = true;
        value_ = value;
        return *this;
    }

    void Reset() { has_value_ = false; }

private:
    bool has_value_;
    T value_;
};

} // namespace cpputils
} // namespace nkhlab