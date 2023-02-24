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

#include <sstream>
#include <string>

namespace nkhlab {
namespace cpputils {

class FileHelper
{
public:
    FileHelper() = delete;

    //
    // Check if the file exists
    //
    static bool ExistFile(const std::string& file);

    //
    // Read file to std::stringstream
    //
    static std::stringstream ReadFile(const std::string& file);

    //
    // Write std::string to file
    //
    // If the file does not exist, it will be created.
    //
    static void WriteFile(const std::string& file, const std::string& data);

    static std::string GetDir(const std::string& file);
    static std::string GetFileName(const std::string& file);
    static std::string RemoveFileExtension(const std::string& file);
};

} // namespace cpputils
} // namespace nkhlab