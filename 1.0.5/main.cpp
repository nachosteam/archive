#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>
#include <sstream>
#include <functional>
#include "json.hpp"
#include "repo.hpp"

#define CNAME "NachosConsole"
#define ver "1.0.5"
using namespace std;
using json = nlohmann::json;

string user()
{
	string username;
	ifstream i("settings.json");
	json data = json::parse(i);
	string userFromFile = data["username"];
	username = userFromFile;
	i.close();
	return username;
}

void create_file()
{
	ofstream out;
    out.open("settings.json");
    if (out.is_open())
    {
        out << "{" << endl << "\t\"username\": \"null\"," << endl << "\t\"repos\": [\"https://forgejo.r2squad.ru/eraserteam/nc-repo\"]" << endl << "}";
		out.close();
    }
	out.open("password");
    if (out.is_open())
    {
        out.close();
    }
}

int main()
{
	if (!filesystem::exists("./pkg"))
		system("mkdir pkg");

	if (!filesystem::exists("./settings.json"))
	{
		create_file();

		cout << "No users!" << endl <<
		"Creating a new one: " << endl << "" << endl;
		string login_new;
		cout << "\t|Login: ";
		getline(cin, login_new);
		ifstream i("settings.json");
		json data;
		i >> data;
		string input_new_username = data["username"];
		data["username"] = login_new;
		ofstream output("settings.json");
		output << data.dump(4);
		cout << endl;
		
		string pass_new;
		cout << "\t|Password: ";
		getline(cin, pass_new);
		hash<string> hasher;
		size_t hashValue = hasher(pass_new);
		ofstream out;
        out.open("password");
        if (out.is_open())
        {
            out << hashValue << endl;
        }
        out.close();
		cout << endl;
	}
	else
	{
		string login_back;
		while(true)
		{
			cout << "\t|login: ";
			getline(cin, login_back);
			ifstream i ("settings.json");
			json data;
			i >> data;
			string login_exists = data["username"];
			i.close();
			if (login_back == login_exists)
				break;
			else
			{
				cout << "Incorrect login. Try again." << endl;
			}
		}
		string passwd_back;
		while(true)
		{
			cout << "\t|password: ";
			getline(cin, passwd_back);
			ifstream i ("password");
			hash<string> hasher;
			size_t hashValue = hasher(passwd_back);
			string passwd_exists;
			ifstream in("password");
			getline(in, passwd_exists);
			in.close();
			if (to_string(hashValue) == passwd_exists)
				break;
			else
			{
				cout << "Incorrect password. Try again." << endl;
			}
		}
	}

	Repo repos("./settings.json");
	
	string action;
	filesystem::path currentDir = filesystem::current_path();
	string pathIn = currentDir.string();
    while(true)
    {
        string term_input;
		string parameter;
        cout << user() << "@pc~$ ";
        getline(cin, term_input);
		istringstream iss(term_input);
		iss >> term_input;
        if(term_input == "help")
        {
            cout << "about						about " CNAME << endl <<
            "passwd						change in-app password" << endl <<
            "clear						clear console" << endl <<
			"pkg [parameter] [package]			get/remove pkg" << endl <<
			"exit						close " CNAME << endl;
            cout << endl;
        }
        else if(term_input == "about")
        {
            cout << "...................." << endl <<
                    "....######.######...\t" CNAME << endl <<
                    "....#........#......\t" ver << endl <<
                    "....#........#......\tBy EraserTeam" << endl <<
                    "....####.....#......\t2024" << endl <<
                    "....#........#......" << endl <<
                    "....#........#......\thttps://forgejo.r2squad.ru/eraserteam/nachos-console" << endl <<
                    "....##########......" << endl <<
                    "...................." << endl;
		}
        else if(term_input == "exit")
            return 0;
        else if(term_input == "passwd")
        {
            string new_passwd;
            cout << "Enter a new password: " << endl;
            getline(cin, new_passwd);
            hash<string> hasher;
			size_t hashValue = hasher(new_passwd);
			ofstream out;
			out.open("password");
			if (out.is_open())
			{
				out << hashValue << endl;
			}
			out.close();
        }
        else if(term_input == "clear")
		{
			#ifdef _WIN32
				system("cls");
			#elif __unix__
				system("clear");
			#endif
		}
		else if (term_input == "pkg")
		{
			iss >> parameter;
        
			if (parameter == "-s" or parameter == "--sync")
			{
				iss >> action;
				string passwd_back;
				cout << "\t|password: ";
				getline(cin, passwd_back);
				ifstream i ("password");
				hash<string> hasher;
				size_t hashValue = hasher(passwd_back);
				string passwd_exists;
				ifstream in("password");
				getline(in, passwd_exists);
				in.close();
				if (to_string(hashValue) == passwd_exists)
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
				ifstream i ("password");
				hash<string> hasher;
				size_t hashValue = hasher(passwd_back);
				string passwd_exists;
				ifstream in("password");
				getline(in, passwd_exists);
				in.close();
				if (to_string(hashValue) == passwd_exists)
				{
					#ifdef _WIN32
    					ifstream file("./pkg/" + action + ".exe");
						if (file)
						{
							file.close();
							string del1 = "del .\\pkg\\" + action + ".exe";
							string del2 = "del .\\pkg\\" + action + ".json";
							system(del1.c_str());
							system(del2.c_str());
							cout << "Deleted successfully." << endl;
						}
						else
						{
							file.close();
							cout << "The package is not installed. Nothing has been deleted." << endl;
						}
					#elif __unix__
						ifstream file("./pkg/" + action);
						if (file)
						{
							file.close();
							string del1 = "rm ./pkg/" + action;
							string del2 = "rm ./pkg/" + action + ".json";
							system(del1.c_str());
							system(del2.c_str());
							cout << "Deleted successfully." << endl;
						}
						else
						{
							file.close();
							cout << "The package is not installed. Nothing has been deleted." << endl;
						}
					#endif
				}
				else
					cout << "Invalid password. Aborted." << endl;
			}
			else if (parameter == "-h" or parameter == "--help")
			{
				iss >> action;
				cout << "-h|--help\tget list of avalible parameters" << endl
				<< "-s|--sync\tsync pkg" << endl
				<< "-r|--remove\tremove pkg" << endl;
			}
			else
			{
				cout << "Unknown parameter. Type 'pkg --help'" << endl;
			}
		}
		else
		{
			#ifdef _WIN32
				if (filesystem::exists(pathIn + "\\pkg\\" + term_input + ".exe"))
				{
					string app_launch = pathIn + "\\pkg\\" + term_input + ".exe";
					system(app_launch.c_str());
				}
				else
				{
					cout << "Unknown command: " << term_input << endl;
				}
			#elif __unix__
				if (filesystem::exists("./pkg/" + term_input))
				{
					string app_launch = "./pkg/" + term_input;
					system(app_launch.c_str());
				}
				else
					cout << "Unknown command: " << term_input << endl;
			#endif
		}
    }
}