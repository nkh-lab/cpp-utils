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
    // Convert raw bytes to string in hexadecimal presentation
    //
    // Convert {0x00, 0x12, 0x34, 0x56, 0x78, 0x9A, 0xBC, 0xDE, 0xFF} to:
    // "00 12 34 56 78 9a bc de ff"                   - default settings
    // "00123456789abcdeff"                           - without delimiter
    // "00-12-34-56-78-9a-bc-de-ff"                   - with custom delimiter
    // "0x00-0x12-0x34-0x56-0x78-0x9A-0xBC-0xDE-0xFF" - with custom delimiter, uppercase and showbase
    //
    static std::string BytesToStr(
        const uint8_t* bytes,
        size_t size,
        const char* delimiter = " ",
        bool uppercase = false,
        bool showbase = false);

    //
    // {0x12, 'a', 'b', 'c', 0x55, 0x00, 0x9A}       --> "abc" // GetStrFromBytes(&bytes[1], 3)
    // {0x12, 'a', 'b', 'c', 0x00, 0x00, 0x00, 0x00} --> "abc" // GetStrFromBytes(&bytes[1], 6)
    //
    static std::string GetStrFromBytes(const uint8_t* bytes, size_t size);

    //
    // Convert wide string to UTF-8
    //
    // L"Hello World!" --> "Hello World!"
    //
    static std::string WstrToStr(const wchar_t* wstr);

    //
    // Formatted string
    //
    template <typename... Args>
    static std::string Sprintf(const char* fmt, Args... args)
    {
        const int size = std::snprintf(nullptr, 0, fmt, args...) + 1;
        std::string buf(size, '\0');
        std::snprintf(&buf[0], size, fmt, args...);
        buf.resize(size - 1);
        return buf;
    }
};

} // namespace cpputils
} // namespace nkhlab