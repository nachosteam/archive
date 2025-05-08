#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>
#include <sstream>
#include "json.hpp"
#define CNAME "NachosConsole"
#define ver "0.7.4"
using namespace std;
using json = nlohmann::json;

string user()
{
    string username;
    ifstream in("user.txt");
    getline(in, username);
    return username;
}

int main()
{
	string action;
	if (!filesystem::exists("./pkg/"))
		system("mkdir pkg");
	else
		cout << "";
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
            "changename					change in-console user name" << endl <<
            "clear						clear console" << endl <<
			"exit						close " CNAME << endl <<
			"pkg [parameter] [package]			get/remove pkg" << endl;
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
                    "....#........#......\thttps://gitea.r2squad.ru/eraserteam/nachos-console" << endl <<
                    "....##########......" << endl <<
                    "...................." << endl;
		}
        else if(term_input == "exit")
            return 0;
        else if(term_input == "changename")
        {
            string newname;
            cout << "Enter a new user name: " << endl;
            getline(cin, newname);
            ofstream out;
            out.open("user.txt");
            if (out.is_open())
            {
                out << newname << endl;
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
				#ifdef _WIN32
					if (!filesystem::exists("./pkg/" + action + ".json"))
					{
						cout << "Trying to get file: https://gitea.r2squad.ru/eraserteam/nc-repo/raw/branch/main/win32/" << action << "/" << action << ".json" << endl;
						string info = "curl -s https://gitea.r2squad.ru/eraserteam/nc-repo/raw/branch/main/win32/" + action + "/" + action + ".json -o " + "./pkg/" + action + ".json";
						system(info.c_str());

    					ifstream file("./pkg/" + action + ".json");
    					if (file)
    					{
    					    string content;
    					    getline(file, content);

    					    if (content == "Not found.")
    					    {
    					        file.close();
								remove(("./pkg/" + action + ".json").c_str());
    					        cout << "Error: package not found." << endl;
    					    }
							else if (content == "")
							{
								file.close();
								remove(("./pkg/" + action + ".json").c_str());
    					        cout << "Error: connection problem." << endl;
							}
    					    else
    					    {
								ifstream i("./pkg/" + action + ".json");
								json data = json::parse(i);
								string pkg_name = data["pkg_name"];
								string pkg_ver = data["pkg_ver"];
								string pkg_weight = data["pkg_weight"];
								string pkg_creator = data["pkg_creator"];
								string pkg_link = data["pkg_link"];
								cout << "\tPackage: " << pkg_name << endl
								<< "\tVersion: " << pkg_ver << endl
								<< "\tWeight: " << pkg_weight << endl
								<< "\tBy: " << pkg_creator << endl
								<< "\tOriginal: " << pkg_link << endl;
								i.close();
								string confirm;
								cout << "Are you sure? [y/n] ";
								getline(cin, confirm);
								if (confirm == "y" or confirm == "yes")
								{
									cout << "Trying to get file: https://gitea.r2squad.ru/eraserteam/nc-repo/raw/branch/main/win32/" << action << "/" << action << ".exe" << endl;
									string compiled = "curl -s https://gitea.r2squad.ru/eraserteam/nc-repo/raw/branch/main/win32/" + action + "/" + action + ".exe -o " + "./pkg/" + action + ".exe";
    								system(compiled.c_str());
									cout << "The package is installed. Enjoy!" << endl;
								}
								else
								{
									file.close();
									remove(("./pkg/" + action + ".json").c_str());
									cout << "Operation aborted." << endl;
								}
    					    }
						}
					}
					else
					{
						ifstream file("./pkg/" + action + ".json");
    					if (file)
						{
							ifstream i("./pkg/" + action + ".json");
							json old_data = json::parse(i);
							string pkg_name = old_data["pkg_name"];
							string old_pkg_ver = old_data["pkg_ver"];

							string new_file = "curl -s https://gitea.r2squad.ru/eraserteam/nc-repo/raw/branch/main/win32/" + action + "/" + action + ".json -o " + "./pkg/new_" + action + ".json";
							system(new_file.c_str());
							ifstream l("./pkg/new_" + action + ".json");
							json new_data = json::parse(l);
							string new_pkg_ver = new_data["pkg_ver"];
							l.close();
							if (old_pkg_ver != new_pkg_ver)
							{
								string renm_new = "del .\\pkg\\new_" + action + ".json";
								string info_dl_new = "curl -s https://gitea.r2squad.ru/eraserteam/nc-repo/raw/branch/main/win32/" + action + "/" + action + ".json -o " + "./pkg/" + action + ".json";
								string pkg_dl_new = "curl -s https://gitea.r2squad.ru/eraserteam/nc-repo/raw/branch/main/win32/" + action + "/" + action + ".exe -o " + "./pkg/" + action + ".exe";
								system(renm_new.c_str());
								system(pkg_dl_new.c_str());
								system(info_dl_new.c_str());
								cout << "Package " << pkg_name << " updated." << endl;
							}
							else
							{
								file.close();
								l.close();
								string rm_new = "del .\\pkg\\new_" + action + ".json";
								system(rm_new.c_str());
								cout << "Package is up to date. Nothing updated." << endl;
							}
						}
					}
				#elif __unix__
					if (!filesystem::exists("./pkg/" + action + ".json"))
					{
						cout << "Trying to get file: https://gitea.r2squad.ru/eraserteam/nc-repo/raw/branch/main/unix/" << action << "/" << action << ".json" << endl;
						string info = "curl -s https://gitea.r2squad.ru/eraserteam/nc-repo/raw/branch/main/unix/" + action + "/" + action + ".json -o " + "./pkg/" + action + ".json";
						system(info.c_str());

    					ifstream file("./pkg/" + action + ".json");
    					if (file)
    					{
    					    string content;
    					    getline(file, content);

    					    if (content == "Not found.")
    					    {
    					        file.close();
								remove(("./pkg/" + action + ".json").c_str());
    					        cout << "Error: package not found." << endl;
    					    }
							else if (content == "")
							{
								file.close();
								remove(("./pkg/" + action + ".json").c_str());
    					        cout << "Error: connection problem." << endl;
							}
    					    else
    					    {
								ifstream i("./pkg/" + action + ".json");
								json data = json::parse(i);
								string pkg_name = data["pkg_name"];
								string pkg_ver = data["pkg_ver"];
								string pkg_weight = data["pkg_weight"];
								string pkg_creator = data["pkg_creator"];
								string pkg_link = data["pkg_link"];
								cout << "\tPackage: " << pkg_name << endl
								<< "\tVersion: " << pkg_ver << endl
								<< "\tWeight: " << pkg_weight << endl
								<< "\tBy: " << pkg_creator << endl
								<< "\tOriginal: " << pkg_link << endl;
								i.close();
								string confirm;
								cout << "Are you sure? [y/n] ";
								getline(cin, confirm);
								if (confirm == "y" or confirm == "yes")
								{
									cout << "Trying to get file: https://gitea.r2squad.ru/eraserteam/nc-repo/raw/branch/main/unix/" << action << "/" << action << endl;
									string compiled = "curl -s https://gitea.r2squad.ru/eraserteam/nc-repo/raw/branch/main/unix/" + action + "/" + action + " -o " + "./pkg/" + action;
									string comlipe_unix = "chmod +x ./pkg/" + action;
    								system(compiled.c_str());
									system(comlipe_unix.c_str());
									cout << "The package is installed. Enjoy!" << endl;
								}
								else
								{
									file.close();
									remove(("./pkg/" + action + ".json").c_str());
									cout << "Operation aborted." << endl;
								}
    					    }
						}
					}
					else
					{
						ifstream file("./pkg/" + action + ".json");
    					if (file)
						{
							ifstream i("./pkg/" + action + ".json");
							json old_data = json::parse(i);
							string pkg_name = old_data["pkg_name"];
							string old_pkg_ver = old_data["pkg_ver"];

							string new_file = "curl -s https://gitea.r2squad.ru/eraserteam/nc-repo/raw/branch/main/unix/" + action + "/" + action + ".json -o " + "./pkg/new_" + action + ".json";
							system(new_file.c_str());
							ifstream l("./pkg/new_" + action + ".json");
							json new_data = json::parse(l);
							string new_pkg_ver = new_data["pkg_ver"];
							l.close();
							if (old_pkg_ver != new_pkg_ver)
							{
								string renm_new = "rm ./pkg/new_" + action + ".json";
								string info_dl_new = "curl -s https://gitea.r2squad.ru/eraserteam/nc-repo/raw/branch/main/unix/" + action + "/" + action + ".json -o " + "./pkg/" + action + ".json";
								string pkg_dl_new = "curl -s https://gitea.r2squad.ru/eraserteam/nc-repo/raw/branch/main/unix/" + action + "/" + action + " -o " + "./pkg/" + action;
								string comlipe_unix = "chmod +x ./pkg/" + action;
								system(comlipe_unix.c_str());
								system(renm_new.c_str());
								system(pkg_dl_new.c_str());
								system(info_dl_new.c_str());
								cout << "Package " << pkg_name << " updated." << endl;
							}
							else
							{
								file.close();
								l.close();
								string rm_new = "rm ./pkg/new_" + action + ".json";
								system(rm_new.c_str());
								cout << "Package is up to date. Nothing updated." << endl;
							}
						}
					}
				#endif
			}
			else if (parameter == "-r" or parameter == "--remove")
			{
				iss >> action;
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