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

#include <chrono>

namespace nkhlab {
namespace cpputils {

class ChronoHelper
{
public:
    ChronoHelper() = delete;

    // clang-format off
    inline static constexpr const char* GetUnitType(const std::chrono::milliseconds& /*time*/) { return "ms"; }
    inline static constexpr const char* GetUnitType(const std::chrono::seconds& /*time*/) { return "s"; }
    inline static constexpr const char* GetUnitType(const std::chrono::minutes& /*time*/) { return "min"; }
    inline static constexpr const char* GetUnitType(const std::chrono::hours& /*time*/) { return "h"; }
    // clang-format on
};

} // namespace cpputils
} // namespace nkhlab
