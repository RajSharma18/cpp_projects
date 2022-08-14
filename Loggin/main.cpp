#include <iostream>
#include <fstream>
#include <string>
using namespace std;

bool IsLoggedIN()
{
    string username, password, un, pw;
    cout << "Enter username" << endl;
    cin >> username;
    cout << "Enter password" << endl;
    cin >> password;

    ifstream read("C:\\Users\\Raj sharma\\OneDrive\\Desktop\\PROJECT_CPP\\" + username + ".txt");
    getline(read, un);
    getline(read, pw);

    if (un == username && pw == password)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    int choice;

    cout << "1: Register\n2: Your Choice\n"
         << endl;
    cin >> choice;

    if (choice == 1)
    {
        string username, password;

        cout << "Select a username" << endl;
        cin >> username;
        cout << "Select a password" << endl;
        cin >> password;

        ofstream file;
        file.open("C:\\Users\\Raj sharma\\OneDrive\\Desktop\\PROJECT_CPP\\" + username + ".txt");
        file << username << endl
             << password;
        file.close();

        main();
    }
    else if (choice == 2)
    {
        bool status = IsLoggedIN();
        if (!status)
        {
            cout << "False login" << endl;
            system("Pause");
            return 0;
        }
        else
        {
            cout << "sucesfully logged in" << endl;
            system("Pause");
            return 1;
        }
    }
    return 0;
}