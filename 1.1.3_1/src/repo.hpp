/*
 * Nachos-Console
 * Copyright (C) 2024 Andrew Stekolnikov <honakac@r2squad.ru>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#pragma once
#include <fstream>
#include <vector>
#include <string>
#include "json.hpp"
using json = nlohmann::json;

class Repo {
public:
    std::vector<std::string> repos;
    json settings;
    
    Repo(std::string inputFile) {
        std::ifstream file(inputFile);
        settings = json::parse(file);
    }
    void downloadPackage(std::string package);
};