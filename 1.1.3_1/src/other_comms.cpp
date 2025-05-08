/*
 * Nachos-Console
 * Copyright (C) 2024 Nikita Belov <nikita2010belov@gmail.com>
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
#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>
#include <sstream>
#include <functional>
#include "json.hpp"

void passwd_change()
{
	std::string new_passwd;
    std::cout << "Enter a new password: " << std::endl;
    std::getline(std::cin, new_passwd);
    std::hash<std::string> hasher;
	std::size_t hashValue = hasher(new_passwd);
	std::ofstream out;
	out.open("password");
	if (out.is_open())
	{
		out << hashValue << std::endl;
	}
	out.close();
}