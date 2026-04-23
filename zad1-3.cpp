//zad 1

include <iostream>
using namespace std;

struct WynikTetna60 {
    int wynik[60];
}

WynikTetna60 analiza_tetna(int pomiary[60]) {
    WynikTetna60 w;

    for(int i=0; i<60; i++) {
        if(pomiary[i] > 100) {
            w.wynik[i] = 1;
        }
        else if(pomiary[i]<60) {
            w.wynik[i] = -1;
        }
        else {
            w.wynik[i] = 0;
        }
    }
    return w;
}

int main() {
    int dane[60];
    for(int i=0; i<60; i++) {
        dane[i] = 50 + i;
    }
    WynikTetna60 wynik = analiza_tetna(dane);
    for(int i=0; i<60; i++) {
        cout << wynik.wynik[i] << " ";
    }
    return 0;
}

//zad 2
#include <iostream>
using namespace std;

struct WynikNuc100 {
    char wynik[100];
};

WynikNuc100 transkrybuj_dna(char dna[100]) {
    WynikNuc100 w;

    for(int i = 0; i < 100; i++) {
        if(dna[i] == 'T') {
            w.wynik[i] = 'U';
        }
        else {
            w.wynik[i] = dna[i];
        }
    }

    return w;
}

int main() {
    char dna[100] = "ATGCTTAGCTA";

    WynikNuc100 rna = transkrybuj_dna(dna);

    for(int i = 0; i < 100; i++) {
        if(rna.wynik[i] == '\0') break; 
        cout << rna.wynik[i];
    }

    return 0;
}


//zad 3
#include <iostream>
using namespace std;

int* oznacz_artefakty(double* cisnienie, int n) {
    int* wynik = new int[n]; 

    for(int i = 0; i < n; i++) {
        if(cisnienie[i] < 40 || cisnienie[i] > 250) {
            wynik[i] = 0; 
        }
        else {
            wynik[i] = 1; 
        }
    }

    return wynik;
}

int main() {
    int n = 5;
    double dane[5] = {120, 300, 80, 35, 150};

    int* wynik = oznacz_artefakty(dane, n);

    for(int i = 0; i < n; i++) {
        cout << wynik[i] << " ";
    }

    delete[] wynik; 

    return 0;
}
