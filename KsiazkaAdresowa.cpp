#include "KsiazkaAdresowa.h"

void KsiazkaAdresowa::rejestracjaUzytkownika() {
    uzytkownikMenedzer.rejestracjaUzytkownika();
}

void KsiazkaAdresowa::wypiszWszystkichUzytkownikow() {
    uzytkownikMenedzer.wypiszWszystkichUzytkownikow();
}

void KsiazkaAdresowa::logowanieUzytkownika() {
    uzytkownikMenedzer.logowanieUzytkownika();
    idZalogowanegoUzytkownika = uzytkownikMenedzer.przekazIdZalogowanegoUzytkownika();
    if(uzytkownikMenedzer.czyUzytkownikJestZalogowany()) {
        adresatMenedzer = new AdresatMenedzer(NAZWA_PLIKU_Z_ADRESATAMI, uzytkownikMenedzer.przekazIdZalogowanegoUzytkownika());
    }
}

void KsiazkaAdresowa::zmianaHaslaZalogowanegoUzytkownika() {
    uzytkownikMenedzer.zmianaHaslaZalogowanegoUzytkownika();
}

void KsiazkaAdresowa::wylogowanieUzytkownika() {
    uzytkownikMenedzer.wylogowanieUzytkownika();
    idZalogowanegoUzytkownika= uzytkownikMenedzer.przekazIdZalogowanegoUzytkownika();
    delete adresatMenedzer;
    adresatMenedzer = NULL;
}

void KsiazkaAdresowa::wyswietlWszystkichAdresatow() {
    adresatMenedzer->wyswietlWszystkichAdresatow();
}

void KsiazkaAdresowa::dodajAdresata() {
    adresatMenedzer->dodajAdresata();
}

void KsiazkaAdresowa::wyszukajAdresatowPoImieniu(){
    adresatMenedzer->wyszukajAdresatowPoImieniu();
}

void KsiazkaAdresowa::wyszukajAdresatowPoNazwisku(){
    adresatMenedzer->wyszukajAdresatowPoNazwisku();
}

bool KsiazkaAdresowa::czyUzytkownikJestZalogowany() {
    return uzytkownikMenedzer.czyUzytkownikJestZalogowany();
}
