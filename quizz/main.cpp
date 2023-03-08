#include <iostream>
#include "pytanie.h"

using namespace std;

int main() {
    Pytanie p1;
    p1.nr_pytania = 1;
    p1.wczytaj();
    p1.zadaj();
    p1.sprawdz();
    return 0;
}
