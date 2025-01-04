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
    // to authenticate specific operations e.g registration and grading
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
    return 1;
}
void reg()
{
    // registera new comers
    if (auth(admin, preset) == 0)
    {
        cout << "Sorry, you are not allowed." << endl;
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

        // ask the informations needed to be registered.

        string status[] = {"id", "password", "name", "father's name", "age", "sex"};
        int length = sizeof(status) / sizeof(string), password;
        string taker;
        fstream file(section, ios::app);
        file << endl;
        for (int i = 0; i < length; ++i)
        {
            if (i == 1)
            {
                // generate a 4 digit PIN by which a student can access its grade(other infos as well)
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
int result()
{
    // ask their section and direct them
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
    string id, pass, jub;
    getline(cin, jub);

    // ask id and password to authenticate
    cout << "id: ";
    getline(cin, id);
    cout << "passsword: ";
    getline(cin, pass);
    ifstream file;
    file.open(section);

    // while there is something to read from the csv file.....
    while (file.good())
    {

        string ch;
        getline(file, ch, ',');
        if (ch == id || ch == "\n" + id)
        {
            string pas;
            getline(file, pas, ',');
            if (pas == pass)
            {
                // if the password entered was indeed right show their status
                string arr[] = {"name", "father's name", "age", "sex", "Fop", "intro", "discrete", "history", "global trend", "p&s", "SGPA"};
                int length = sizeof(arr) / sizeof(string);
                for (int i = 0; i < length; ++i)
                {
                    cout << arr[i] << "  ";
                    if (i == 0)
                    {
                        cout << "         ";
                    }
                }
                cout << endl;
                for (int i = 0; i < 11; i++)
                {
                    string chs;
                    getline(file, chs, ',');
                    int len = chs.size();
                    int size = arr[i].size();
                    cout << chs;
                    if (i == 0)
                    {
                        for (int k = 0; k < 15 - len; ++k)
                        {
                            cout << " ";
                        }
                    }
                    else
                    {
                        for (int j = 0; j < size - len + 2; ++j)
                        {
                            cout << " ";
                        }
                    }
                }
                cout << endl
                     << endl;
            }
            else
            {
                cout << "the password u entered was incorrect. try to contact the admin." << endl
                     << endl;
            }
        }
    }
    return 0;
}
string grading()
{
    string section;
    // ask for admin authorisation using the auth function
    if (auth(admin, preset) == 0)
    {
        cout << "Sorry you are not allowed." << endl
             << endl;
    }
    else
    {
        int sec;
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
        string id, jub;
        getline(cin, jub);

        cout << "enter the id of the student u want to grade : ";
        getline(cin, id);
        ifstream file;
        file.open(section);
        fstream work("working.csv", ios::app);
        while (file.good())
        {
            string ch;
            getline(file, ch, ',');
            if (ch.size() != 0)
            {
                work << ch << ',';
            }
            if (ch == id || ch == "\n" + id)
            {
                for (int i = 0; i < 11; ++i)
                {
                    string chs;
                    getline(file, chs, ',');
                    work << chs << ',';
                    if (i > 3)
                    {
                        int assesment, final, total;
                        float mark, sum = 0, sgpa, chrs = 18;
                        string grade;
                        cout << "enter the result of of final and assesment in order to be graded" << endl;
                        string courses[] = {"Fop", "intro", "discrete", "history", "global trend", "p&s"};
                        int len = sizeof(courses) / sizeof(string);
                        for (int i = 0; i < len; ++i)
                        {
                            cout << courses[i] << endl;
                            cout << "final(50%) : ";
                            cin >> final;
                            cout
                                << "assesment(50%) : ";
                            cin >> assesment;
                            total = final + assesment;

                            // automatic F if a student scored less than 20 in his/her final

                            if (final < 20)
                            {
                                grade = "F";
                                mark = 0;
                            }

                            // else convert the mark to letter grade.
                            else
                            {
                                if (total >= 90)
                                {
                                    grade = "A+";
                                    mark = 4;
                                }
                                else if (total >= 85)
                                {
                                    grade = "A";
                                    mark = 4;
                                }
                                else if (total >= 80)
                                {
                                    grade = "A-";
                                    mark = 3.75;
                                }
                                else if (total >= 75)
                                {
                                    grade = "B+";
                                    mark = 3.5;
                                }
                                else if (total >= 70)
                                {
                                    grade = "B";
                                    mark = 3;
                                }
                                else if (total >= 65)
                                {
                                    grade = "B-";
                                    mark = 2.75;
                                }
                                else if (total >= 60)
                                {
                                    grade = "C+";
                                    mark = 2.5;
                                }
                                else if (total >= 50)
                                {
                                    grade = "C";
                                    mark = 2;
                                }
                                else
                                {
                                    grade = "F";
                                    mark = 0;
                                }
                            }

                            // write the converted letter grade to the working.csv file

                            work << grade << ',';
                            if (i == 1)
                            {
                                sum += 4 * mark;
                            }
                            else if (i == 4)
                            {
                                sum += 2 * mark;
                            }
                            else
                            {
                                sum += 3 * mark;
                            }
                        }
                        // calculate SGPA
                        sgpa = sum / chrs;
                        work << sgpa << ',';
                        cout << "Graded successfully!!" << endl
                             << endl;
                        break;
                    }
                }
            }
        }
    }
    return section;
}
int replacer(string section)
{

    // replace the old file with the new(working.csv) by first emptying it then writing working.csv on it
    ofstream empty(section, ios::trunc);
    empty.close();
    ifstream newer;
    newer.open("working.csv");
    ofstream updated(section, ios::app);
    string checker = "";
    while (newer.good())
    {
        string line;
        if (checker.size() != 0)
        {
            updated << endl;
        }
        getline(newer, line);
        updated << line;
        checker = line;
    }
    ofstream working("working.csv", ios::trunc);
    working.close();
    return 0;
}
void showBySection()
{
    // shows the grade of all students in a section
    // requirs admin aythirisation i.e FOR TEACHERS ONLY
    if (auth(admin, preset) == 0)
    {
        cout << "Sorry you are not eligible for this operation.";
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
        string ch;
        ifstream file;
        file.open(section);
        int cnt = 0;
        while (file.good())
        {
            getline(file, ch, ',');
            if (cnt == 2 || cnt == 3)
            {
                cout << ch;
                for (int i = 0; i < 20 - ch.size(); ++i)
                {
                    cout << " ";
                }
            }
            else if (cnt == 12)
            {
                cout << ch << endl;
            }
            cnt++;
            if (cnt == 13)
            {
                cnt = 0;
            }
        }
    }
}
int main()
{
    cout << "welcome aboard enter the number specified for a required operation." << endl;
    bool running = true;
    // to make the program run infinitely untill the user exits.
    while (running == true)
    {
        int choice;
        // options of different operationns
        cout << endl;
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
            replacer(grading());
            break;
        case 3:
            showBySection();
            break;
        case 4:
            result();
            break;
        case 5:
            running = false;
            break;
        default:
            break;
        }
    }
}