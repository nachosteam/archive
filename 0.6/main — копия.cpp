#include <iostream>
#include <fstream>
#include <unistd.h>
#include <string>
#define CNAME "NachosConsole"
#define ver "0.6"
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
        if(term_input == "hack")
        {
            cout << "hacking..." << endl;
            sleep(2);
            cout << "192.168.0.69 ping" << endl;
            sleep(2);
            for (int i = 0; i < 7; i++)
            {
                cout << "wget localhost(pkg version 1.4.88) 192.168.0.24   1 ms(0 pkg)" << endl;
                sleep(1);
            }
            sleep(4);
            cout << "downloading C:\\*" << endl;
            sleep(3);
            cout << "failed pizdec :(" << endl;
        }
        else if(term_input == "help")
        {
            cout << "hack                                   just not a funny joke" << endl;
            cout << "about                                  about " CNAME << endl;
            cout << "exit                                   close " CNAME << endl;
            cout << "changename                             change in-console user name" << endl;
            cout << "clear                                  clear console" << endl;
	    cout << "echo                                   output your inputed text" << endl;
            cout << endl;
        }
        else if(term_input == "about")
        {
            cout << "...................................................." << endl <<
                    "...................................................." << endl <<
                    "...................................................." << endl <<
                    "...................................................." << endl <<
                    "...................................................." << endl <<
                    "...................................................." << endl <<
                    ".....####################*:#######################.." << endl <<
                    "....:@@@@@@@@@@@@@@@@@@@@@:@@@@@@@@@@@@@@@@@@@@@@@.." << endl <<
                    "....:@@@@:::::::::::::::::.:::::::::@@@@*:::::::::.." << endl <<
                    "....:@@@@...........................@@@@+..........." << endl <<
                    "....:@@@@...........................@@@@+..........." << endl <<
                    "....:@@@@...........................@@@@+..........." << endl <<
                    "....:@@@@...........................@@@@+..........." << endl <<
                    "....:@@@@@@@@@@@@@@@@@..............@@@@+...........\t" CNAME << endl <<
                    "....:@@@@@@@@@@@@@@@@@..............@@@@+...........\t" ver << endl <<
                    "....:@@@@:::::::::::::..............@@@@+..........." << endl <<
                    "....:@@@@...........................@@@@+..........." << endl <<
                    "....:@@@@...........................@@@@+..........." << endl <<
                    "....:@@@@...........................@@@@+..........." << endl <<
                    "....:@@@@...........................@@@@+..........." << endl <<
                    "....:@@@@...........................@@@@+..........." << endl <<
                    "....:@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@+..........." << endl <<
                    "....:@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@=............" << endl <<
                    "...................................................." << endl <<
                    "...................................................." << endl <<
                    "...................................................." << endl <<
                    "...................................................." << endl <<
                    "...................................................." << endl;
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
	else if(term_input == "echo")
	{
	    string echotext = "1";
	    if(echotext == "" or " ")
	    {
		cout << "Echo is empty. Please, enter the text" << endl;
	    }
	    else
	    {
		cout << echotext << endl;
	    }
	}
	else if(term_input == "")
	{
	}
        else
            cout << "Unknown command" << endl;
    }
}
