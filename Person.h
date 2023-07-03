#include <iostream>
using namespace std;

class Person
{
    int idx;
    bool flag;
    string f_name, l_name, mail, phone_no, adress;

public:
    Person(int nr_porz = 1, string imie = "First name", string nazwisko = "Last name ", string e_adress = "login@server.domain", string tel = "000000000", string adres = "somewere", bool flag = true);
    ~Person();

    void load();
    void show();
    void show_short();
    void input_fname(string imie);
    void input_lname(string nazwisko);
    void input_phone(string telefon);
    void input_email(string e_mail);
    void input_adress(string postadress);
    void load_file(int no_person);
    bool person_search(string per_iden, bool pointer);
    void person_remove();
    void person_write();
    friend void person_modify(Person *persons, int id, int number_persons);
};