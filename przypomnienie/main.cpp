#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <time.h>
#include <iomanip>
#include <conio.h>
#include <fstream>
#include <algorithm>
#include <string>
#include <time.h>
#include <cmath>

using namespace std;

int main() {
    cout << "Hello, World!" << endl;
    /*
        Sleep(1000);                   // funkcja z windows.h
        system("cls");                 // funkcja z cstdlib
        srand(time(NULL);              // pobiera z systemu liczbe sekund i daje do rand
        liczba = rand() % 100 + 1;     // losowa liczba od 1 do 100, biblioteka cstdlib
        system("pause");
        getchar();
        cout << setprecision(10000) od teraz cout wypisze do 10 000 cyfr liczby

        switch(wybor)
        {
        case 1:
        {
            cout << "";
        }
        break;
        default: cout << "nie ma takiej opjci";
        }

        wybor=getch(); bierze znak bez enera

        int nr_miesiaca
        if (!cin(cin >> nr_miesiaca)) {      // sprawdza poprawnosc wejscia
            cerr << "To nie jest liczba!"
            exit(0);                         // #include <cstdlib>
        }


        fstream plik;           // zmienna plikowa
        plik.open("wizytowka.txt", ios::out);                   // do zapisu
        plik.open("wizytowka.txt", ios::out | ios::app);        // do dopisu
        plik << imie;
        plik.close;

        fstream plik;
        plik.open("wizytowka.txt", ios::in);        // do odczytu
        if (plik.good() == false)
            cout << "nie ma takiego pliku";

        string line;
        getline(plik, line)         // zwraca falsz jak linie sie wyczerpaly, prawde jak sa linie

        int nr_tel = atoi(linia.c_str());       // string na inta
        int float_liczba = atof(linia.c_str());       // string na float'a
        transform(line.begin(), line.end(), line.begin, ::tolower)      // zmienia litery na male
        plik.eof()          zwraca prawde jasli skonczy sie plik

        // size_t to unsigned int z tym, ze jest rozmiaru wystarczajaco dlugiego aby pomiescic rozmiar w bitach kazdego obiektu

        string napis = "ala ma kota";
        string szukaj = "kot";

        size_t pozycja = napis.find(szukaj);

        if (pozycja != string::npos)
            cout << "znaleziony na pozycji: " << pozycja;
        else
            cout << " nie ma ";


        napis.erase(5,10); od 5 10 znakow
        napis.insert(11, "filemona"); dodanie od pozycji w strungu napisu argument
        napis.replace(4, 2, "nie ma");          od ktorego, ile znakow, na co

        getline(cin, napis);        z wejscia do napisu cale zdanie


        int ile = 10;
        int * tablica;
        tablica = new int [ile];                // rezerwuje 10 intow, typ wazne zeby komp wiedzial ze tablica + 1 to adres drugiej komorki, bo int
                                                // ma 4 bajty, float 8 => ta jedynka nie jest jednoznaczna i w zaleznosci od typu zmienia swoja 'wartosc'
        delete [] tablica

        clock_t start, stop;
        double czas;

        start = clock();            // czas rusza
        ...
        ...
        stop = clock();
        czas = (double)(stop - start) / CLOCKS_PER_SEC;     // do zliczenia czasu

        int xd = 10;
        &xd;            // adres xd

        float funkcja(int &x) {}        // przekazanie przez adres
        funkcja(xd);


        abs(x,y)        <- modul z intow
        fabs(x,y)       <- modul z flotow
        pow(liczba,wykladnik)

        int x;
        sizeof(x); zwraca bajty na typ

        sqrt(liczba);
        pow(liczba, 1/2);
        round(-2.9); przyblizenie

        ceil(3.14);     //sufit
        floor(3.14);    // podloga
        trunc(3.14);    // obcina cyfry po przecinku
        M_PI            // to jest pi
        M_E             // liczba e

        sin(kat w radianach)
        sin(stopnie * M_PI/180.0)
        cos()
        tan()
        1/tan()



    */

    return 0;
}
