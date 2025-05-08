#include <iostream>
#include <fstream>
#include <windows.h>
#include <string>
#define CNAME "NachosConsole"
#define ver "0.5"
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
    cout << "Welcome to the " CNAME << endl;
    while(true)
    {
        string term_input;
        cout << user() << "@pc~$ ";
        getline(cin, term_input);
        if(term_input == "взломать анчоуса локалхост 123")
        {
            cout << "взлом..." << endl;
            Sleep(2000);
            cout << "localhost ping" << endl;
            Sleep(500);
            for (int i = 0; i < 7; i++)
            {
                cout << "wget localhost(pkg version 1.4.88) https://developerlox.pizdec   90328573245 ms(0 pkg)" << endl;
                Sleep(800);
            }
            Sleep(4000);
            cout << "downloading C:\\*" << endl;
            Sleep(3000);
            cout << "failed pizdec :(" << endl;
        }
        else if(term_input == "help")
        {
            cout << "взломать анчоуса локалхост 123         just not a funny joke" << endl;
            cout << "about                                  about " CNAME << endl;
            cout << "exit                                   close " CNAME << endl;
            cout << "changename                             change in-console user name" << endl;
            cout << "clear                                  clear console" << endl;
            cout << endl;
        }
        else if(term_input == "about")
        {
            cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << endl << 
                    "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << endl << 
                    "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << endl << 
                    "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << endl << 
                    "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << endl << 
                    "@@@@@@@@@@@@@@@@@@@@@    =@@@@@@@@@@@@@@@" << endl << 
                    "@@@@@@@@@@@@@@:  =@@@      +@@@@@@@@@@@@@" << endl << 
                    "@@@@@@@@@@@@@     +@@       *@@@@@@@@@@@@" << endl << 
                    "@@@@@@@@@@@@-     +@@        @@@@@@@@@@@@" << endl << 
                    "@@@@@@@@@@@@.     +@@        @@@@@@@@@@@@" << endl << 
                    "@@@@@@@@@@@@.     +@@.       @@@@@@@@@@@@\t" CNAME << endl <<
                    "@@@@@@@@@@@@.       @@=      @@@@@@@@@@@@\t" ver << endl << 
                    "@@@@@@@@@@@@:       @@=      @@@@@@@@@@@@" << endl << 
                    "@@@@@@@@@@@@=       @@=      @@@@@@@@@@@@" << endl << 
                    "@@@@@@@@@@@@@       @@+     *@@@@@@@@@@@@" << endl << 
                    "@@@@@@@@@@@@@#      @@@+  .%@@@@@@@@@@@@@" << endl << 
                    "@@@@@@@@@@@@@@@*.   @@@@@@@@@@@@@@@@@@@@@" << endl << 
                    "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << endl << 
                    "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << endl << 
                    "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << endl << 
                    "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << endl << 
                    "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << endl;
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
            system("clear");
        }
        else
            cout << "Unknown command" << endl;
    }
}