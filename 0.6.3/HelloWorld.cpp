#include <stdio.h>
#include <iostream>
#include <fstream>

#ifdef _WIN32
    #include <windows.h>
#elif __unix__
    #include <unistd.h>
#endif

#include <string>
#define CNAME "NachosConsole"
#define ver "0.6.3"
using namespace std;

string user()
{
    string username;
    ifstream in("user.txt");
    getline(in, username);
    return username;
}

int main()
{
    while(true)
    {
        string term_input;
        cout << user() << "@pc~$ ";
        getline(cin, term_input);
        if(term_input == "help")
        {
            cout << "about                                  about " CNAME << endl;
            cout << "changename                             change in-console user name" << endl;
            cout << "clear                                  clear console" << endl;
			cout << "exit                                   close " CNAME << endl;
            cout << endl;
        }
        else if(term_input == "about")
        {
            cout << "....................." << endl <<
                    "....................." << endl <<
                    "....######.######...." << endl <<
                    "....#........#......." << endl <<
                    "....#........#.......\t" CNAME << endl <<
                    "....####.....#.......\t" ver << endl <<
                    "....#........#......." << endl <<
                    "....#........#......." << endl <<
                    "....##########......." << endl <<
                    "....................." << endl;
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
			    system("cls");
            /*#ifdef _WIN32
				
			#elif __unix__
				system("clear");
			#endif*/
        }
        else
            cout << "Unknown command: " << term_input << endl;
    }
}