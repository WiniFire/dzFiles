#include <iostream>
#include <fstream>
#include <Windows.h>
#include <string>
#include <vector>
using namespace std;

//Завдання №1
struct People {
    string Prizv;
    string phone;
};

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    //Завдання №1
    cout << "Завдання №1\n";

    
    ofstream file("abonent.txt");
    if (!file) {
        cout << "File not find\n";
        return 0;
    }
    int ans, count = 1;
    People Abonents[5];
    do {
        cout << "Input" << count << "abonent: ";
        getline(cin, Abonents->Prizv);
        getline(cin, Abonents->phone);
        file << count << ") " << Abonents->Prizv << ' ' << Abonents->phone << endl;
        cout << "Do you have abonents Yes [1] | No [2]: ";
        cin >> ans;
        count++;
        cin.ignore();
    } while (ans == 1);

    file.close();

    ifstream fileR("abonent.txt");

    string userChoice;
    cout << "Виберіть що вивести: 1 - список прізвищ абонентів та їх телефонів, 2 - лише прізвище та номер телефону необхідного абонента: ";
    getline(cin, userChoice);

    string line1 = "";

    if (userChoice == "1")
    {
        while (getline(fileR, line1)) {
            cout << line1 << endl;
        }
    }
    else
    {
        short peopleChoice;
        cout << "Ввеідть номер людини дані котрої хочете вивести: ";
        cin >> peopleChoice;
        short indexCount = 1;
        while (getline(fileR, line1)) {
            if (indexCount == peopleChoice) { cout << line1; break; }
            else indexCount++;
        }
    }

    cout << endl << endl << endl;


    //Завдання №2
    cout << "Завдання №2\n";

    ifstream file21("File2.1.txt");
    ofstream file22("File2.2.txt");

    if (file21.is_open())
    {
        cout << "Файл №1 успішно відкрито!\n";
    }
    else
    {
        cout << "Файл №1 не вдалось відкрити!";
        return 0;
    }
    if (file22.is_open())
    {
        cout << "Файл №2 успішно відкрито!\n";
    }
    else
    {
        cout << "Файл №2 не вдалось відкрити!";
        return 0;
    }

    string line = "";

    while (getline(file21, line)) {
        file22 << line << "\n";
    }

    cout << "\nДані успішно записані!";

    file21.close();
    file22.close();

    cout << endl << endl << endl;


    //Завдання №3
    cout << "Завдання №3\n";

    ifstream file31("File3.1.txt");
    ofstream file32("File3.2.txt");

    if (file31.is_open())
    {
        cout << "Файл №1 успішно відкрито!\n";
    }
    else
    {
        cout << "Файл №1 не вдалось відкрити!";
        return 0;
    }
    if (file32.is_open())
    {
        cout << "Файл №2 успішно відкрито!\n";
    }
    else
    {
        cout << "Файл №2 не вдалось відкрити!";
        return 0;
    }

    vector <string> lines3;
    short indexCount3 = 0;
  
    string line3 = "";

    while (getline(file31, line3)) {
        line3 += "\n";
        indexCount3++;
        lines3.push_back(line3);
    }

    for (short i = indexCount3 - 1; i >= 0; i--) file32 << lines3[i];

    cout << "\nДані успішно записані!";

    file31.close();
    file32.close();

    cout << endl << endl << endl;


    //Завдання №4
    cout << "Завдання №4\n";

    ifstream file4("File4.txt");

    if (file4.is_open())
    {
        cout << "Файл №1 успішно відкрито!\n";
    }
    else
    {
        cout << "Файл №1 не вдалось відкрити!";
        return 0;
    }

    vector <string> lines4;
    short indexCount4 = 0;

    string line4 = "";

    while (getline(file4, line4)) {
        indexCount4++;
        lines4.push_back(line4);
    }

    bool foundCheck = false;
    short indexString = 0;
    for (short i = indexCount4 - 1; i >= 0; i--) {
        short strSize = lines4[i].size();
        for (short j = 0; j < strSize; j++) {
            if (lines4[i][j] == ' ')
            {
                indexString = i;
                foundCheck = true;
                break;
            }
        }
        if (foundCheck) break;
    }

    cout << endl << "Дані успішно зчитано!" << endl << endl;

    file4.close();

    ofstream file41("File4.txt");

    if (file41.is_open())
    {
        cout << "Файл для перезапису успішно відкрито!\n";
    }
    else
    {
        cout << "Файл для перезапису не вдалось відкрити!";
        return 0;
    }

    if (foundCheck == false)
    {
        for (short i = 0; i < indexCount4; i++) {
            file41 << lines4[i] << "\n" << "------------" << "\n";
        }
    }
    else
    {
        for (short i = 0; i < indexCount4; i++) {
            file41 << lines4[i] << "\n";
            if (i == indexString) file41 << "------------" << "\n";
        }
    }

    cout << endl << "Дані успішно перезаписано!";

    file4.close();

    cout << endl << endl << endl;

    return 0;
}
