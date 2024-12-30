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