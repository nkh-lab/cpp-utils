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

#include <string>

namespace nkhlab {
namespace cpputils {

class StringHelper
{
public:
    StringHelper() = delete;

    //
    // Convert uint8_t bytes[] = {0x00, 0x12, 0x34, 0x56, 0x78, 0x9A, 0xBC, 0xDE, 0xFF} to:
    // "00 12 34 56 78 9a bc de ff"
    // "00123456789abcdeff"
    // "00--12--34--56--78--9a--bc--de--ff"
    static std::string BytesToStr(
        uint8_t* bytes,
        size_t size,
        const char* delimiter = " ",
        bool uppercase = false,
        bool showbase = false);
    static std::string GetStrFromBytes(uint8_t* bytes, size_t size);
    static std::string PwstrToStr(wchar_t* pwstr);
    static std::string Sprintf(const char* fmt, ...);
};

} // namespace cpputils
} // namespace nkhlab