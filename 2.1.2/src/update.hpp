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
    #define REPO_LINK std::string("/main/win/")
	#define SET_FILE "nc-bin\\settings.json"
#elif __linux__
    #define REPO_LINK std::string("/main/linux/")
	#define SET_FILE "nc-bin/settings.json"
#endif

void update()
{
	/*std::ifstream i(SET_FILE);
	nlohmann::json data = nlohmann::json::parse(i);
	std::string repo = data["repos"];
	std::cout << repo << endl;
	std::string get_json = "";*/
}