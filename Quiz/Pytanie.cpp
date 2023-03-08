//
// Created by kryst on 08/03/2023.
//

#include <iostream>
#include <fstream>
#include <cstdlib>
#include "pytanie.h"

void Pytanie::wczytaj() {
    fstream plik;
    plik.open("C:\\Users\\kryst\\OneDrive\\Pulpit\\prog\\pasjaInf\\Quiz\\quiz.txt", ios::in);

    if(plik.good() == false)  {
        cout << "Nie udalo sie otwrzyc pliku!";
        exit(0);
    }

    int nr_linii = (nr_pytania - 1) * 6 + 1;
    int aktualny_nr = 1;
    string linia;

    while(getline(plik, linia)) {
        if (aktualny_nr == nr_linii)            tresc = linia;
        else if (aktualny_nr == nr_linii + 1)   a = linia;
        else if (aktualny_nr == nr_linii + 2)   b = linia;
        else if (aktualny_nr == nr_linii + 3)   c = linia;
        else if (aktualny_nr == nr_linii + 4)   d = linia;
        else if (aktualny_nr == nr_linii + 5)   poprawna = linia;

        aktualny_nr++;
    }

    plik.close();
}

void Pytanie::zadaj() {
    cout << endl << tresc << endl;
    cout << "a)" << a << endl;
    cout << "b)" <<b << endl;
    cout << "c)" <<c << endl;
    cout << "d)" <<d << endl;
    cout << "-----------------" << endl;
    cout << endl << "Odpowiedz: "; cin >> odpowiedz;
}

void Pytanie::sprawdz() {
    if (odpowiedz == poprawna)
        punkt = 1;
    else punkt = 0;
}
