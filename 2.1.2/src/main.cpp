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

#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>
#include <sstream>
#include <functional>
#include <locale>
#include "json.hpp"
#include "sha256.h"
#include "account.hpp"
#include "systems.hpp"
#include "sync.hpp"
#include "remove.hpp"
#include "update.hpp"

#define CNAME "NachosConsole"
#define ver "2.1.2"
#ifdef _WIN32
	#include <windows.h>
	#define DIR_COMM "dir "
	#define PATH_TO_PROG "nc-bin\\" + term_input
	#define WIN_UTF8 SetConsoleOutputCP(CP_UTF8)
	#define WIN_UTF8_2 system("chcp 60001")
	#if defined(_WIN32) && defined(_WIN64)
		#define HOST_OS " for Win64"
	#else
		#define HOST_OS " for Win32"
	#endif
#elif __linux__
	#include <unistd.h>
	#define DIR_COMM "ls "
	#define PATH_TO_PROG "nc-bin/" + term_input
	#define WIN_UTF8
	#define HOST_OS " for Linux"
#endif
using namespace std;
using json = nlohmann::json;

int main()
{
	setlocale(LC_ALL, "en_US.utf8");
	WIN_UTF8;
	WIN_UTF8_2;
	
	login();
	clear();
	Repo repos("nc-bin/settings.json");

    while(true)
    {
		string passwd_back;
		string term_input;
		string parameter;
		string action;
		string fullcom;
		cout << prompt();
		getline(cin, term_input);
		fullcom = term_input;
		istringstream iss(term_input);
		iss >> term_input;
		if (term_input == "help")
			help_com("default");
		else if (term_input == "about")
		{
			std::cout << ".................." << std::endl <<
				"..#.....#..######.\t" CNAME << HOST_OS << std::endl <<
				"..##....#....#....\t" ver << std::endl <<
				"..#.#...#....#....\tBy \x1B[33mNachosTeam\033[0m 2024" << std::endl <<
				"..#..#..#....#....\thttps://github.com/nachosteam/nachos-console" << std::endl <<
				"..#...#.#....#...." << std::endl <<
				"..#....##....#....\t\x1B[36mUnder MIT License\033[0m" << std::endl <<
				"..#.....#....#...." << std::endl <<
				".................." << std::endl;
		}
		else if (term_input == "exit")
			exit(42);
		else if (term_input == "passwd")
			passwd_change();
		else if (term_input == "clear" or term_input == "cls")
			clear();
		else if (term_input == "ls" or term_input == "dir")
		{
			iss >> parameter;
			string dir_cmd = DIR_COMM + parameter;
			system(dir_cmd.c_str());
		}
		else if (term_input == "echo") {
			string args = fullcom;
			args.erase(0, args.find(" ") + 1);
			std::cout << args << std::endl;
		}
		// pkg manager
		else if (term_input == "npkg")
		{
			iss >> parameter;
        
			if (parameter == "-s" or parameter == "--sync")
			{
				iss >> action;
				
				string passwd_back;
				cout << "\t|password: ";
				getline(cin, passwd_back);
				ifstream i ("nc-bin/settings.json");
				json data;
				i >> data;
				string passwd_exists = data["password"];
				string pb_hash = SHA256::hashString(passwd_back);
				if (pb_hash == passwd_exists)
				{
					repos.downloadPackage(action);
				}
				else
					cout << "Invalid password. Aborted." << endl;
			}
			else if (parameter == "-r" or parameter == "--remove")
			{
				iss >> action;
				
				string passwd_back;
				cout << "\t|password: ";
				getline(cin, passwd_back);
				ifstream i ("nc-bin/settings.json");
				json data;
				i >> data;
				string passwd_exists = data["password"];
				string pb_hash = SHA256::hashString(passwd_back);
				if (pb_hash == passwd_exists)
				{
					remove(action);
				}
				else
					cout << "Invalid password. Aborted." << endl;
			}
			else if (parameter == "-u" || parameter == "--update")
			{
				iss >> action;
				
				string passwd_back;
				cout << "\t|password: ";
				getline(cin, passwd_back);
				ifstream i ("nc-bin/settings.json");
				json data;
				i >> data;
				string passwd_exists = data["password"];
				string pb_hash = SHA256::hashString(passwd_back);
				if (pb_hash == passwd_exists)
				{
					update();
				}
				else
					cout << "Invalid password. Aborted." << endl;
			}
			else if (parameter == "-h" or parameter == "--help")
				help_com("pkg");
			else
				cout << "Unknown parameter. Type 'pkg --help'" << endl;
		}
		else
		{
			if (!term_input.empty())
			{
				if (filesystem::exists(PATH_TO_PROG))
				{
					run_pkg(term_input, fullcom);
					/*string app_launch = PROG_FULL;
					system(app_launch.c_str());*/
				}
				else
					cout << "Unknown command: " << term_input << endl;
			}
		}
	}
}
