#include <iostream>

using namespace std;

class Zwierze {
public:
    string gatunek;
    string imie;
    int wiek;

    void dodaj_zwierze() {
        cout << "Dodawanie nowego zwierzecia do bazy\n";
        cout << "Podaj gatunek: ";     cin >> gatunek;
        cout << "Podaj imie: ";        cin >> imie;
        cout << "Podaj wiek: ";        cin >> wiek;
        cout << endl;
    }

    void daj_glos() {
        if (gatunek == "kot")           cout << imie << " lat " << wiek << ": Miau!";
        else if (gatunek == "koza")     cout << imie << " lat " << wiek << ": Beee!";
        else if (gatunek == "krowa")    cout << imie << " lat " << wiek << ": Muuuu!";
        else                            cout << "Nieznany gatunek, kosmita?!";
    }
};



int main() {
    //Zwierze z1;
    //z1.dodaj_zwierze();
    //z1.daj_glos();

}
