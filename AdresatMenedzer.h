#ifndef ADRESATMENEDZER_H
#define ADRESATMENEDZER_H

#include <iostream>
#include <vector>
#include <windows.h>
#include <fstream>
#include <sstream>
#include <vector>

#include "Uzytkownik.h"
#include "PlikZAdresatami.h"
#include "MetodyPomocnicze.h"
#include "Adresat.h"
#include "UzytkownikMenedzer.h"

using namespace std;

class AdresatMenedzer
{
    vector <Adresat> adresaci;
    int idOstatniegoAdresata;
    PlikZAdresatami plikZAdresatami;

    void wyswietlDaneAdresata(Adresat adresat);
    Adresat podajDaneNowegoAdresata(int idZalogowanegoUzytkownika);

    public:
    AdresatMenedzer(){idOstatniegoAdresata=0;};
    void wyswietlWszystkichAdresatow();
    void dodajAdresata(int idZalogowanegoUzytkownika);

};
#endif
