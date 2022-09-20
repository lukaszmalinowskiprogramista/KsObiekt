#ifndef METODYPOMOCNICZE_H
#define METODYPOMOCNICZE_H

#include <iostream>
#include <sstream>
#include <algorithm>
#include <fstream>

using namespace std;

class MetodyPomocnicze
{
    public:
        static string konwerjsaIntNaString(int liczba);
        static int konwersjaStringNaInt(string liczba);
        static string wczytajLinie();
        static string zamienPierwszaLitereNaDuzaAPozostaleNaMale(string tekst);
        static bool czyPlikJestPusty(fstream& plikTekstowy);
        static string pobierzLiczbe(string tekst, int pozycjaZnaku);
};
#endif
