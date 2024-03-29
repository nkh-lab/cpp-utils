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

#include "cpp-utils/StringHelper.h"

#include <codecvt>
#include <iomanip>
#include <locale>
#include <sstream>
#include <stdarg.h>

namespace nkhlab {
namespace cpputils {

std::string StringHelper::BytesToStr(
    const uint8_t* bytes,
    size_t size,
    const char* delimiter,
    bool uppercase,
    bool showbase)
{
    std::stringstream ss;

    ss << std::hex;

    for (size_t i = 0; i < size; ++i)
    {
        if (showbase) ss << "0x";
        ss << std::setfill('0') << std::setw(2);
        if (uppercase) ss << std::uppercase;
        ss << static_cast<int>(bytes[i]);
        if (i < size - 1) ss << delimiter;
    }

    return ss.str();
}

std::string StringHelper::GetStrFromBytes(const uint8_t* bytes, size_t size)
{
    size_t actual_str_size{size};

    for (size_t i = 0; i < size; ++i)
    {
        if (bytes[i] == 0)
        {
            actual_str_size = i;
            break;
        }
    }

    return std::string(std::string(reinterpret_cast<const char*>(&bytes[0]), actual_str_size));
}

std::string StringHelper::WstrToStr(const wchar_t* wstr)
{
    std::string str;

    if (wstr)
    {
        // wide to UTF-8
        std::wstring_convert<std::codecvt_utf8<wchar_t>> converter;
        str = converter.to_bytes(wstr);
    }

    return str;
}

//
// Split a string into strings by delimiter
//
std::vector<std::string> StringHelper::SplitStr(
    const std::string& input,
    const std::string& delimiter,
    bool skip_empty)
{
    std::vector<std::string> strings;
    size_t start = 0, end = 0;
    std::string sub_str;

    while ((end = input.find(delimiter, start)) != std::string::npos)
    {
        sub_str = input.substr(start, end - start);
        start = end + delimiter.length();

        (skip_empty && sub_str.size() == 0) ? void() : strings.push_back(sub_str);
    }

    // Add the last substring after the last delimiter
    sub_str = input.substr(start);
    (skip_empty && sub_str.size() == 0) ? void() : strings.push_back(sub_str);

    return strings;
}

} // namespace cpputils
} // namespace nkhlab
