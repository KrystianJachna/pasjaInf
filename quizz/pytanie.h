//
// Created by kryst on 08/03/2023.
//

#include <iostream>
#ifndef QUIZZ_PYTANIE_H
#define QUIZZ_PYTANIE_H

using namespace std;


class Pytanie {
public:
    string tresc;
    string a, b, c, d;
    int nr_pytania;
    string poprawna;
    string odpowiedz;
    int punkt;

    void wczytaj();
    /*
     * wczytuje pytania z pliku
     */
    void zadaj();
    /*
     * wyswietla pytania i czyta mozliwe odpowiedzi
     */
    void sprawdz();
    /*
     * czyta odpowiedz uzytkownika, porownuje z prawidlowa i dodaje/nie dodaje punkt
     */
};


#endif //QUIZZ_PYTANIE_H
