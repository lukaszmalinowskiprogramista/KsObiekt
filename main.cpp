#include <iostream>

#include "KsiazkaAdresowa.h"

using namespace std;

int main()
{
    KsiazkaAdresowa ksiazkaAdresowa("Uzytkownicy.txt", "Adresaci.txt");

    ksiazkaAdresowa.wypiszWszystkichUzytkownikow();
    ksiazkaAdresowa.rejestracjaUzytkownika();
    ksiazkaAdresowa.logowanieUzytkownika();
    ksiazkaAdresowa.wyswietlWszystkichAdresatow();
    ksiazkaAdresowa.dodajAdresata();
    ksiazkaAdresowa.wylogowanieUzytkownika();
    return 0;
}

/*
DOSTÊPNE METODY:
rejestracjaUzytkownika();
wypiszWszystkichUzytkownikow();
logowanieUzytkownika();
zmianaHaslaZalogowanegoUzytkownika();
wylogowanieUzytkownika();
wyswietlWszystkichAdresatow();
dodajAdresata();
*/
