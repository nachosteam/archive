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
#ifdef _WIN32
	#define PATH_TO_PKG "./pkg/" + action + ".exe"
	#define DEL_EXE "del .\\pkg\\" + action + ".exe"
	#define DEL_JSON "del .\\pkg\\" + action + ".json"
#elif __unix__
	#define PATH_TO_PKG "./pkg/" + action
	#define DEL_EXE "rm ./pkg/" + action
	#define DEL_JSON "rm ./pkg/" + action + ".json"
#endif

void del_pkg(std::string action)
{
	std::string passwd_back;
	std::cout << "\t|password: ";
	std::getline(std::cin, passwd_back);
	std::ifstream i("password");
	std::hash<std::string> hasher;
	std::size_t hashValue = hasher(passwd_back);
	std::string passwd_exists;
	std::ifstream in("password");
	std::getline(in, passwd_exists);
	in.close();
	i.close();
	if (std::to_string(hashValue) == passwd_exists)
	{
    	std::ifstream file(PATH_TO_PKG);
		if (file)
		{
			file.close();
			std::string del1 = DEL_EXE;
			std::string del2 = DEL_JSON;
			system(del1.c_str());
			system(del2.c_str());
			std::cout << "Deleted successfully." << std::endl;
		}
		else
		{
			file.close();
			std::cout << "The package is not installed. Nothing has been deleted." << std::endl;
		}
	}
	else
		std::cout << "Invalid password. Aborted." << std::endl;
}