/*
    GROUP MEMBERS
    FIRAOL GULA
    KALEB DEREJE
    FIRAOL BESHADA
    FIKREMARIAM DEBELA
    FITSUM MULUGETA
    ESROM TADESSE
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;
int admin, preset = 1234;
int auth(int admin, int preset)
{
    cout << "This operation requires admin authorisation.\n please enter ur admin password: ";
    cin >> admin;
    while (admin != preset)
    {
        cout << "incorrect pasword password pls try again or press 0 to exit: ";
        cin >> admin;
        if (admin == 0)
        {
            return 0;
            break;
        }
    }
    if (admin == preset)
    {
        return 1;
    }
}

void reg()
{
    if (auth(admin, preset) == 0)
    {
        cout << "Sorry, you are not allowed.";
    }
    else
    {
        int sec;
        string section;
        cout << "choose section:\n1.section-A\n2.section-B\n>>> ";
        cin >> sec;
        switch (sec)
        {
        case 1:
            section = "section-A.csv";
            break;
        case 2:
            section = "section-B.csv";
            break;
        }
        string status[] = {"id", "password", "name", "father's name", "age", "sex"};
        int length = sizeof(status) / sizeof(string), password;
        string taker;
        fstream file(section, ios::app);
        file << endl;
        for (int i = 0; i < length; ++i)
        {
            if (i == 1)
            {
                srand(time(NULL));
                password = (rand() % 9000) + 1000;
                file << password << ",";
                continue;
            }
            else
            {
                cout << status[i] << " : ";
                cin >> taker;

                file
                    << taker << ",";
            }
        }
        cout << "Registration complete successfully! your password to access ur info is " << password << endl
             << endl;
    }
}

int main()
{
    bool running = true;
    // to make the program run infinitely untill the user exits.
    while (running == true)
    {
        int choice;
        // options of different operationns
        cout << "welcome aboard enter the number specified for a required operation." << endl;
        cout << "1. Register a new student" << endl;
        cout << "2. enter marks and calculate SGPA using ID" << endl;
        cout << "3. Show Grade by section" << endl;
        cout << "4. Show student info" << endl;
        cout << "5. Exit" << endl;
        cout << ">>>";
        cin >> choice;

        // calling functions for the chosen operations
        switch (choice)
        {
        case 1:
            reg();
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            running = false;
            break;
        default:
            break;
        }
    }
}