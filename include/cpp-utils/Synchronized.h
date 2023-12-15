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

#pragma once

#include <fstream>
#include <mutex>

namespace nkhlab {
namespace cpputils {

template <typename T>
class Synchronized
{
public:
    Synchronized()
        : obj_{}
    {
    }
    explicit Synchronized(T&& obj)
        : obj_{std::move(obj)}
    {
    }
    ~Synchronized() = default;

    //
    // !!! Do not forget about locking scope, use a local variable for this, e.g.:
    // {
    //     auto l = shared_counter.GetLock();   <-- 'l' is locked
    //     ++shared_counter.Get();
    // }                                        <-- 'l' will be unlocked here
    //
    std::unique_lock<std::mutex> GetLock() { return std::unique_lock<std::mutex>(mutex_); }

    // e.g. to lock several resource then in one time, e.g. std::lock(lk_b, lk_c);
    std::unique_lock<std::mutex> GetDeferredLock()
    {
        return std::unique_lock<std::mutex>(mutex_, std::defer_lock);
    }
    T& Get() { return obj_; }

private:
    T obj_;
    std::mutex mutex_;
};

} // namespace cpputils
} // namespace nkhlab