// ===================== ZADANIE 4 =====================

double* oblicz_isi(double* czasy_wyladowan, int n)
{
    // tworzenie nowej tablicy na wyniki
    double* isi = new double[n - 1];

    // obliczanie roznic czasu
    for(int i = 1; i < n; i++)
    {
        isi[i - 1] = czasy_wyladowan[i] - czasy_wyladowan[i - 1];
    }

    // zwrot nowej tablicy
    return isi;
}

// ===================== ZADANIE 5 =====================

struct WynikTestu8x8
{
    double dane[8][8];
};

WynikTestu8x8 oblicz_przezywalnosc(double plytka[8][8])
{
    // struktura na wynik
    WynikTestu8x8 wynik;

    // przechodzenie po kolumnach
    for(int j = 0; j < 8; j++)
    {
        // wartosc kontrolna z pierwszego wiersza
        double kontrola = plytka[0][j];

        // liczenie procentu przezywalnosci
        for(int i = 0; i < 8; i++)
        {
            wynik.dane[i][j] = (plytka[i][j] / kontrola) * 100.0;
        }
    }

    return wynik;
}

// ===================== ZADANIE 6 =====================

struct Obraz10x10
{
    int dane[10][10];
};

Obraz10x10 wyostrz_komorki(int obraz[10][10])
{
    // struktura wynikowa
    Obraz10x10 wynik;

    // wyzerowanie calej tablicy
    for(int i = 0; i < 10; i++)
    {
        for(int j = 0; j < 10; j++)
        {
            wynik.dane[i][j] = 0;
        }
    }

    // filtr laplace'a bez brzegow
    for(int i = 1; i < 9; i++)
    {
        for(int j = 1; j < 9; j++)
        {
            int nowy = 4 * obraz[i][j]
                     - obraz[i-1][j]
                     - obraz[i+1][j]
                     - obraz[i][j-1]
                     - obraz[i][j+1];

            // usuwanie wartosci ujemnych
            if(nowy < 0)
            {
                nowy = 0;
            }

            wynik.dane[i][j] = nowy;
        }
    }

    return wynik;
}

// ===================== ZADANIE 7 =====================

double** centruj_geny(double** ekspresja, int geny, int pacjenci)
{
    // alokacja nowej macierzy
    double** znormalizowana = new double*[geny];

    for(int i = 0; i < geny; i++)
    {
        znormalizowana[i] = new double[pacjenci];
    }

    // przechodzenie po genach
    for(int i = 0; i < geny; i++)
    {
        double suma = 0;

        // liczenie sredniej
        for(int j = 0; j < pacjenci; j++)
        {
            suma += ekspresja[i][j];
        }

        double srednia = suma / pacjenci;

        // odejmowanie sredniej
        for(int j = 0; j < pacjenci; j++)
        {
            znormalizowana[i][j] = ekspresja[i][j] - srednia;
        }
    }

    return znormalizowana;
}

// ===================== ZADANIE 8 =====================

int** symuluj_dzien_epidemii(int** populacja, int w, int k)
{
    // alokacja nowej planszy
    int** nowy_stan = new int*[w];

    for(int i = 0; i < w; i++)
    {
        nowy_stan[i] = new int[k];
    }

    // przechodzenie po planszy
    for(int i = 0; i < w; i++)
    {
        for(int j = 0; j < k; j++)
        {
            // zakazony staje sie ozdrowiencem
            if(populacja[i][j] == 1)
            {
                nowy_stan[i][j] = 2;
            }

            // ozdrowieniec zostaje bez zmian
            else if(populacja[i][j] == 2)
            {
                nowy_stan[i][j] = 2;
            }

            // podatny
            else
            {
                int zarazony = 0;

                // sprawdzanie sasiedztwa
                for(int a = -1; a <= 1; a++)
                {
                    for(int b = -1; b <= 1; b++)
                    {
                        int ni = i + a;
                        int nj = j + b;

                        // sprawdzanie granic
                        if(ni >= 0 && ni < w && nj >= 0 && nj < k)
                        {
                            if(populacja[ni][nj] == 1)
                            {
                                zarazony = 1;
                            }
                        }
                    }
                }

                // zmiana stanu
                if(zarazony)
                {
                    nowy_stan[i][j] = 1;
                }
                else
                {
                    nowy_stan[i][j] = 0;
                }
            }
        }
    }

    return nowy_stan;
}

// ===================== ZADANIE 9 =====================

int*** segmentuj_kosci(double*** skan_ct, int x, int y, int z)
{
    // alokacja tablicy 3D
    int*** maska = new int**[x];

    for(int i = 0; i < x; i++)
    {
        maska[i] = new int*[y];

        for(int j = 0; j < y; j++)
        {
            maska[i][j] = new int[z];
        }
    }

    // tworzenie maski kosci
    for(int i = 0; i < x; i++)
    {
        for(int j = 0; j < y; j++)
        {
            for(int k = 0; k < z; k++)
            {
                if(skan_ct[i][j][k] > 400)
                {
                    maska[i][j][k] = 1;
                }
                else
                {
                    maska[i][j][k] = 0;
                }
            }
        }
    }

    return maska;
}

// ===================== ZADANIE 10 =====================

int*** naswietlaj_uv(int*** biofilm, int szer, int wys, int gleb)
{
    // alokacja nowej tablicy 3D
    int*** nowy = new int**[szer];

    for(int i = 0; i < szer; i++)
    {
        nowy[i] = new int*[wys];

        for(int j = 0; j < wys; j++)
        {
            nowy[i][j] = new int[gleb];
        }
    }

    // przechodzenie po warstwach
    for(int i = 0; i < szer; i++)
    {
        for(int j = 0; j < wys; j++)
        {
            int strata = 50;

            // od gornej warstwy do dolnej
            for(int k = wys - 1; k >= 0; k--)
            {
                for(int l = 0; l < gleb; l++)
                {
                    // zmniejszanie zdrowia
                    nowy[i][k][l] = biofilm[i][k][l] - strata;

                    // minimum 0
                    if(nowy[i][k][l] < 0)
                    {
                        nowy[i][k][l] = 0;
                    }
                }

                // kolejne warstwy traca mniej
                strata = strata / 2;

                if(strata < 1)
                {
                    strata = 1;
                }
            }
        }
    }

    return nowy;
}
