#include "Person.h"
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <algorithm>

using namespace std;

bool Person::person_search(string per_iden, bool pointer)
{
    transform(f_name.begin(), f_name.end(), f_name.begin(), ::toupper);
    transform(per_iden.begin(), per_iden.end(), per_iden.begin(), ::toupper);
    transform(l_name.begin(), l_name.end(), l_name.begin(), ::toupper);
    if (pointer)
    {
        if (f_name == per_iden)
        {
            return true;
        }
        else
            return false;
    }
    else
    {
        if (l_name == per_iden)
        {
            return true;
        }
        else
            return false;
    }
}

void Person::show()
{
    if (flag)
    {
        cout << idx << endl;
        cout << "First name:   " << f_name << endl;
        cout << "Last name:    " << l_name << endl;
        cout << "Tel:          " << phone_no << endl;
        cout << "E-mail:       " << mail << endl;
        cout << "Address:        " << adress << endl;
    }
}
void Person::show_short()
{
    if (flag)
    {
        cout << "ID: " << idx << " " << f_name
             << " " << l_name << endl;
    }
}

void Person::input_fname(string imie)
{
    f_name = imie;
}

void Person::input_lname(string nazwisko)
{
    l_name = nazwisko;
}

void Person::input_phone(string telefon)
{
    phone_no = telefon;
}
void Person::input_email(string e_mail)
{
    mail = e_mail;
}
void Person::input_adress(string postadress)
{
    adress = postadress;
}
void Person::load_file(int no_person)
{
    string line;
    int i = 1;
    int nr_start = (no_person - 1) * 6 + 1;
    fstream persons;
    persons.open("contacts.txt");
    while (persons)
    {
        getline(persons, line);

        if (i == nr_start)
        {
            idx = no_person;
        }
        if (i == nr_start + 1)
        {
            f_name = line;
        }

        if (i == nr_start + 2)
        {
            l_name = line;
        }
        if (i == nr_start + 3)
        {
            phone_no = line;
        }
        if (i == nr_start + 4)
        {
            mail = line;
        }
        if (i == nr_start + 5)
        {
            adress = line;
        }

        i++;
    }
    persons.close();
}
void Person::person_remove()
{
    flag = false;
}
void Person::person_write()
{
    if (flag == true)
    {
        fstream per_write;
        per_write.open("contacts.txt", ios::out | ios::app);
        per_write << idx << endl;
        per_write << f_name << endl;
        per_write << l_name << endl;
        per_write << phone_no << endl;
        per_write << mail << endl;
        per_write << adress << endl;
        per_write.close();
    }
}

Person::Person(int nr_porz, string imie, string nazwisko, string e_adress, string tel, string adres, bool znacznik)

{
    idx = nr_porz;
    f_name = imie;
    l_name = nazwisko;
    mail = e_adress;
    phone_no = tel;
    adress = adres;
    flag = znacznik;
}

Person::~Person()
{
}