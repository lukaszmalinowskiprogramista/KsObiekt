#ifndef UZYTKOWNIK_H
#define UZYTKOWNIK_H

#include <iostream>

using namespace std;

class Uzytkownik
{
    int id;
    string login;
    string haslo;

public:
    void ustawId(int noweId);
    void ustawLogin(string nowyLogin);
    void ustawHaslo(string niweHaslo);

    int pobierzId();
    string pobierzLogin();
    string pobierzHaslo();
};

#endif
