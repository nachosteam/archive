/*
	MIT License

	Copyright (c) 2024 NachosTeam https://github.com/nachosteam

	Permission is hereby granted, free of charge, to any person obtaining a copy
	of this software and associated documentation files (the "Software"), to deal
	in the Software without restriction, including without limitation the rights
	to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
	copies of the Software, and to permit persons to whom the Software is
	furnished to do so, subject to the following conditions:

	The above copyright notice and this permission notice shall be included in all
	copies or substantial portions of the Software.

	THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
	IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
	FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
	AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
	LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
	OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
	SOFTWARE.
*/

#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>
#include <sstream>
#include <functional>
#include "json.hpp"
#ifdef _WIN32
	#define PATH_TO_PKG "nc-bin\\" + action
	#define DIR_DEL "rmdir /s /q nc-bin\\" + action
#elif __linux__
	#define PATH_TO_PKG "nc-bin/" + action
	#define DIR_DEL "rm -rf nc-bin/" + action
#endif

void remove(std::string action)
{
	if (std::filesystem::exists(PATH_TO_PKG))
	{
		std::string confirm;
		std::cout << "Are you sure? [Y/n]";
		std::getline(std::cin, confirm);
		if (confirm == "yes" || confirm == "y" || confirm.empty())
		{
			std::string del = DIR_DEL;
			system(del.c_str());
			std::cout << "Deleted successfully." << std::endl;
		}
		else if (confirm == "no" || confirm == "n")
			std::cout << "Aborted by user." << std::endl;
	}
	else
		std::cout << "The package is not installed." << std::endl;
}