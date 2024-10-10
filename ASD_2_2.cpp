#include <iostream>

using namespace std;

const int MAX_SIZE = 101;

int** StworzGrafMJ(int przystanki, int polaczenia) {
    int** graf = new int*[przystanki];
    for (int i = 0; i < przystanki; i++) {
        graf[i] = new int[polaczenia]{0};
    }
    return graf;
}

int** PomnozPolaczenia(int** grafMJ, int rozmiar) {
    int** marszrutyZPrzesiadka = StworzGrafMJ(rozmiar, rozmiar);

    for (int i = 0; i < rozmiar; i++) {
        for (int j = 0; j < rozmiar; j++) {
            for (int k = 0; k < rozmiar; k++) {
                marszrutyZPrzesiadka[i][j] += grafMJ[i][k] * grafMJ[k][j];
            }
        }
    }
    return marszrutyZPrzesiadka;
}

void WyswietlGrafMJ(int** graf, int przystanki, int polaczenia) {
    for (int i = 0; i < przystanki; i++) {
        for (int j = 0; j < polaczenia; j++) {
            cout << graf[i][j] << " ";
        }
        cout << "\n";
    }
}

bool CzyBedzieWycieczka(int** grafMJ, int** marszrutyZPrzesiadka, int rozmiar) {
    for (int i = 0; i < rozmiar; i++) {
        for (int j = 0; j < rozmiar; j++) {
            if (marszrutyZPrzesiadka[i][j] > 0 && grafMJ[i][j] == 0) {
                return false;
            }
        }
    }
    return true;
}


int main() {
    int najwiekszyPrzystanek = 0, i, j;
    int** grafMJ = StworzGrafMJ(MAX_SIZE, MAX_SIZE);

    while (cin >> i >> j) {
        grafMJ[i][j] = 1;
        najwiekszyPrzystanek = max(najwiekszyPrzystanek, max(i, j));
    }

    int** marszrutyZPrzesiadka = PomnozPolaczenia(grafMJ, najwiekszyPrzystanek + 1);
    cout << (CzyBedzieWycieczka(grafMJ, marszrutyZPrzesiadka, najwiekszyPrzystanek + 1) ? "TAK" : "NIE") << endl;

    return 0;
}
