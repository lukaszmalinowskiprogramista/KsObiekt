#include "UzytkownikMenedzer.h"

Uzytkownik UzytkownikMenedzer::podajDaneNowegoUzytkownika()
{
    Uzytkownik uzytkownik;

    uzytkownik.ustawId(pobierzIdNowegoUzytkownika());

    string login;
    do
    {
        cout << "Podaj login: ";
        cin>>login;
        uzytkownik.ustawLogin(login);
    } while (czyIstniejeLogin(uzytkownik.pobierzLogin()) == true);

    string haslo;
    cout << "Podaj haslo: ";
    cin>>haslo;
    uzytkownik.ustawHaslo(haslo);

    return uzytkownik;
}

int UzytkownikMenedzer::pobierzIdNowegoUzytkownika()
{
    if (uzytkownicy.empty() == true)
        return 1;
    else
        return uzytkownicy.back().pobierzId() + 1;
}

bool UzytkownikMenedzer::czyIstniejeLogin(string login)
{
    for (int i =0; i<uzytkownicy.size(); i++)
    {
        if (uzytkownicy[i].pobierzLogin()==login)
        {
            cout << endl << "Istnieje uzytkownik o takim loginie." << endl;
        return true;
        }
    }
    return false;

}

void UzytkownikMenedzer::rejestracjaUzytkownika()
{
    Uzytkownik uzytkownik = podajDaneNowegoUzytkownika();

    uzytkownicy.push_back(uzytkownik);
    plikZUzytkownikami.dopiszUzytkownikaDoPliku(uzytkownik);

    cout << "Konto zalozono pomyslnie" << endl << endl;
    system("pause");
}

void UzytkownikMenedzer::wypiszWszystkichUzytkownikow()
{
    for (int i =0; i<uzytkownicy.size(); i++)
    {
            cout << uzytkownicy[i].pobierzId() << endl;
            cout << uzytkownicy[i].pobierzLogin() << endl;
            cout << uzytkownicy[i].pobierzHaslo() << endl;
    }
}

void UzytkownikMenedzer::wczytajUzytkownikowZPliku()
{
    uzytkownicy = plikZUzytkownikami.wczytajUzytkownikowZPliku();
}

void UzytkownikMenedzer::logowanieUzytkownika()
{
    Uzytkownik uzytkownik;
    bool poprawnyLogin=false;
    idZalogowanegoUzytkownika=0;

    cout << endl << "Podaj login: ";
    uzytkownik.ustawLogin(MetodyPomocnicze::wczytajLinie());

    int i=0;
    while (i != uzytkownicy.size() && idZalogowanegoUzytkownika==0)
    {
        if (uzytkownicy[i].pobierzLogin() == uzytkownik.pobierzLogin())
        {
            poprawnyLogin=true;
            for (int iloscProb = 3; iloscProb > 0 && idZalogowanegoUzytkownika==0 ; iloscProb--)
            {
                cout << "Podaj haslo. Pozostalo prob: " << iloscProb << ": ";
                uzytkownik.ustawHaslo(MetodyPomocnicze::wczytajLinie());
                if (uzytkownicy[i].pobierzHaslo() == uzytkownik.pobierzHaslo())
                {
                    cout << endl << "Zalogowales sie." << endl << endl;
                    idZalogowanegoUzytkownika=uzytkownicy[i].pobierzId();
                }
            }
                if (idZalogowanegoUzytkownika==0)
                    cout << "Wprowadzono 3 razy bledne haslo." << endl;
        }
        i++;
    }
    if( poprawnyLogin==false)
        cout << "Nie ma uzytkownika z takim loginem" << endl << endl;
    system("pause");
}



void UzytkownikMenedzer::zmianaHaslaZalogowanegoUzytkownika()
{
   /* string noweHaslo = "";
    cout << "Podaj nowe haslo: ";
    noweHaslo = wczytajLinie();

    for (vector <Uzytkownik>::iterator itr = uzytkownicy.begin(); itr != uzytkownicy.end(); itr++)
    {
        if (itr -> id == idZalogowanegoUzytkownika)
        {
            itr -> haslo = noweHaslo;
            cout << "Haslo zostalo zmienione." << endl << endl;
            system("pause");
        }
    }
    zapiszWszystkichUzytkownikowDoPliku(uzytkownicy);

    */
}

/*
void zapiszWszystkichUzytkownikowDoPliku(vector <Uzytkownik> &uzytkownicy)
{
    fstream plikTekstowy;
    string liniaZDanymiUzytkownika = "";
    vector <Uzytkownik>::iterator itrKoniec = --uzytkownicy.end();

    plikTekstowy.open(nazwaPlikuZUzytkownikami.c_str(), ios::out);

    if (plikTekstowy.good() == true)
    {
        for (vector <Uzytkownik>::iterator itr = uzytkownicy.begin(); itr != uzytkownicy.end(); itr++)
        {
            liniaZDanymiUzytkownika = zamienDaneUzytkownikaNaLinieZDanymiOddzielonaPionowymiKreskami(*itr);

            if (itr == itrKoniec)
            {
               plikTekstowy << liniaZDanymiUzytkownika;
            }
            else
            {
                plikTekstowy << liniaZDanymiUzytkownika << endl;
            }
            liniaZDanymiUzytkownika = "";
        }
    }
    else
    {
        cout << "Nie mozna otworzyc pliku " << nazwaPlikuZUzytkownikami << endl;
    }
    plikTekstowy.close();
}

//////////////////////////////////////////////////
// Wylogowywanie
case '8':
                idZalogowanegoUzytkownika = 0;
                adresaci.clear();

*/
