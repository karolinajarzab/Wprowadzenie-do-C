//zad1
#include <iostream>
int main() {
    std::cout << "Hello World!" << std::endl;
    return 0;
}

//zad2
#include <iostream>
#include <string>
using namespace std;

int main() {
    int num1=7;
    float num2=7.5;
    char letter='A';
    cout << "Numer1: " << num1 << endl;
    cout << "Numer2: " << num2 << endl;
    cout << "Letter: " << letter << endl;
    return 0;
}

//zad3
#include <iostream>
#include <string>
using namespace std;

int main() {
    int three=3;
    int eleven=11;
    cout << "Sum: " << (three + eleven) << endl;
    return 0;
}

//zad4
#include <iostream>
#include <string>
using namespace std;

int main() {
    float x=12;
    float y=7;
    x=x/y;
    cout << x << endl;
    return 0;
}

//zad5
#include <iostream>
#include <string>
using namespace std;

int main() {
    char name[] = "Karolina";
    char lastname[] = "Jarzab";
    cout << name << endl;
    cout << lastname << endl;
    return 0;
}

//petle

//zad1
#include <iostream>
#include <string>
using namespace std;

int main() {
    string dna = "ATGCGATATCGGATCGA";
    int A = 0;
    int T = 0;
    int G = 0;
    int C = 0;
    for (int i = 0; i < dna.length(); ++i) {
        if (dna[i] == 'A') A++;
        else if (dna[i] == 'T') T++;
        else if (dna[i] == 'G') G++;
        else if (dna[i] == 'C') C++;
    }

    cout << "A: " << A << endl;
    cout << "T: " << T << endl;
    cout << "G: " << G << endl;
    cout << "C: " << C << endl;

    return 0;
}

//zad2
#include <iostream>
#include <string>
using namespace std;

int main() {
    string dna_seq = "ATGCGATATCGGATCGAe";
    int i=0;
    while(i < dna_seq.length() && dna_seq[i] != 'e') {
        cout << dna_seq[i] << endl;
        i++;
    }
    cout << "Wystapil symbol STOP" << endl;
    return 0;
}

//zad3
#include <iostream>
#include <string>
using namespace std;

int main() {
    string input;
    cout << "Enter a string: ";
    cin >> input;
    int len = 0;
    int i=0;
    do {
        input.length();
        ++len;    
        ++i;
    }
    while(i < input.length());
    cout << "Dlugosc sekwencji: " << len << endl;
    return 0;
}

//cwiczenia 3 - 13.03.2026

//zad4
#include <iostream>
#include <string>
using namespace std;

int main() {
    string input;
    cout << "Enter a string: ";
    cin >> input;
    int g = 0;
    int c = 0;
    float s = 0;
    for (int i = 0; i < input.length(); ++i) {
        if (input[i] == 'G') g++;
        else if (input[i] == 'C') c++;
        ++s;
    }
    cout << "Liczba G: " << g << endl;
    cout << "Liczba C: " << c << endl;
    cout << "Zawartosc GC w sekwencji: " << (g + c) / s * 100 << "%" << endl;
    return 0;
}

//funkcje

//zad 1
#include <iostream>
#include <string>
using namespace std;

int main() {
    char input;
    cout << "Enter a letter: " << endl;
    cin >> input;
    for (char input = 'A'; input <= 'Z';) {
        input++;
    }
    cout << ++input << endl;
    return 0;
}

//zad 2
#include <iostream>
#include <string>
using namespace std;

string love() {
    return "I love C++!";
}
int main() {
    string output = love();
    cout << output << endl;
    return 0;
}

//zad 3
#include <iostream>
#include <string>
using namespace std;

int mnozenie(int a, int b) {
    return a * b;
}

int main() {
    int a = 0;
    int b = 0;
    cout << "Podaj dwie liczby: " << endl;
    cin >> a  >> b;
    int output = mnozenie(a, b); cout << "Wynik mnozenia: " << output << endl;
    return 0;
}

//zad 4
#include <iostream>
#include <string>
using namespace std;

string x = "True"
int b = 0;
int liczba(int a) {
    if(a / 4 = 0) {
        cout << "x" << x << endl;
        //return x; 
    }
}

int main() {
    cout << "Podaj liczbe: " << endl;
    
    cin >> b >> endl;
    int output = liczba(b); cout << "Czy liczba podzielna przez 4: " << output << endl;
    return 0;
}
