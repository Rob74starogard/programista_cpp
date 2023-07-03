#include <iostream>
#include "Person.h"
#include <fstream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

void menu_print()
{
    cout << endl;
    cout << "------------------------------------" << endl;
    cout << "           Options:                 " << endl;
    cout << "------------------------------------" << endl;
    cout << "1. View all elements (with all data)" << endl;
    cout << "2. Full view of one person " << endl;
    cout << "3. Search people by first name" << endl;
    cout << "4. Search people by last name" << endl;
    cout << "5. Remove person from databook" << endl;
    cout << "6. Add person to databook" << endl;
    cout << "7. Modify person's data" << endl;
    cout << "--Other choice end's program--" << endl;
    cout << "____________________________________" << endl;
    cout << "What we do?" << endl;
}

void person_add()
{
    string imie, nazwisko, telefon, email, adres_poczt;
    Person temp;
    cout << "Enter first name" << endl;
    cin.sync();
    getline(cin, imie);
    temp.input_fname(imie);

    cout << "Enter last name" << endl;
    getline(cin, nazwisko);
    temp.input_lname(nazwisko);

    cout << "Enter phone no" << endl;
    getline(cin, telefon);
    temp.input_phone(telefon);

    cout << "Enter e-mail" << endl;
    getline(cin, email);
    temp.input_email(email);

    cout << "Enter adress" << endl;
    getline(cin, adres_poczt);
    temp.input_adress(adres_poczt);

    temp.person_write();
    temp.show();
}

void person_modify(Person *persons, int id, int number_persons)
{
    string imie, nazwisko, telefon, email, adres_poczt, wskaznik;
    Person temp;
    cout << persons[id].f_name << endl;
    cout << "Change[y/n]?" << endl;
    cin >> wskaznik;
    if (wskaznik == "y")
    {
        cout << "Enter new value" << endl;
        cin.sync();
        getline(cin, imie);
        temp.f_name = imie;
    }
    else
    {
        temp.f_name = persons[id].f_name;
    }
    cout << persons[id].l_name << endl;
    cout << "Change[y/n]?" << endl;
    cin >> wskaznik;
    if (wskaznik == "y")
    {
        cout << "Enter new value" << endl;
        cin.sync();
        getline(cin, nazwisko);
        temp.l_name = nazwisko;
    }
    else
    {
        temp.l_name = persons[id].l_name;
    }
    cout << persons[id].phone_no << endl;
    cout << "Change[y/n]?" << endl;
    cin >> wskaznik;
    if (wskaznik == "y")
    {
        cout << "Enter new value" << endl;
        cin.sync();
        getline(cin, telefon);
        temp.phone_no = telefon;
    }
    else
    {
        temp.phone_no = persons[id].phone_no;
    }
    cout << persons[id].mail << endl;
    cout << "Change[y/n]?" << endl;
    cin >> wskaznik;
    if (wskaznik == "y")
    {
        cout << "Enter new value" << endl;
        cin.sync();
        getline(cin, email);
        temp.mail = email;
    }
    else
    {
        temp.mail = persons[id].mail;
    }
    cout << persons[id].adress << endl;
    cout << "Change[y/n]?" << endl;
    cin >> wskaznik;
    if (wskaznik == "y")
    {
        cout << "Enter new value" << endl;
        cin.sync();
        getline(cin, adres_poczt);
        temp.adress = adres_poczt;
    }
    else
    {
        temp.adress = persons[id].adress;
    }

    persons[id].person_remove();
    remove("contacts.txt");
    for (int i = 1; i < number_persons + 1; i++)
    {
        persons[i].person_write();
    }
    temp.person_write();
}

void search(Person *persons, string fn_search, int no_persons, bool pointer)
{
    for (int i = 1; i < no_persons + 1; i++)
    {
        if (persons[i].person_search(fn_search, pointer == true))
        {
            persons[i].show();
        }
    }
}

int file_size()
{
    fstream file;
    string line;
    file.open("contacts.txt");
    int i = 1;

    while (file)
    {
        getline(file, line);
        i++;
    }
    return i / 6;
}

int main()
{
    string name;
    string imie, nazwisko, telefon, email, adres_poczt;
    int control = 3;
    while (control == 3)
    {
        int no_persons = file_size();
        Person *persons;
        persons = new Person[no_persons + 1];

        int driver, id;

        system("cls");

        for (int i = 1; i < no_persons + 1; i++)
        {
            persons[i].load_file(i);
            persons[i].show_short();
        }

        menu_print();

        cin >> driver;

        switch (driver)
        {
        case 1:
        {
            for (int i = 1; i < no_persons + 1; i++)
            {
                persons[i].show();
            }
            system("pause");
            break;
        case 2:
        {
            cout << endl;
            cout << "Enter person's ID:" << endl;
            cin >> id;
            persons[id].show();
            system("pause");
            break;
        }
        case 3:
        {
            cout << endl;
            cout << " Enter first name of person You are looking for..." << endl;
            cin >> name;
            search(persons, name, no_persons, true);
            system("pause");
            break;
        }
        case 4:
        {
            cout << endl;
            cout << " Enter last name of person You are looking for..." << endl;
            cin >> name;
            search(persons, name, no_persons, false);
            system("pause");
            break;
        }
        case 5:
        {
            cout << endl;
            cout << " Enter ID of person You want to remove from address book. " << endl;
            cin >> id;
            persons[id].show_short();
            cout << "Removed from list" << endl;
            persons[id].person_remove();
            remove("contacts.txt");
            for (int i = 1; i < no_persons + 1; i++)
            {
                persons[i].person_write();
            }

            system("pause");
            break;
        }
        case 6:
        {
            person_add();
            system("pause");
            break;
        }
        case 7:
        {
            cout << endl;
            cout << "Enter person's ID:";
            cin >> id;
            person_modify(persons, id, no_persons);
            break;
        }
        default:
            delete[] persons;
            exit(0);
        }
        }
    }
    return 0;
}