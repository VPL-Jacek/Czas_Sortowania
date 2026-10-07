#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm>
#include <stack>
#include <queue>
#include <random>
#include <iomanip>

using namespace std;

// Nazwa klasy: BadaczWydajnosci
// Opis: Klasa odpowiedzialna za inicjalizacje danych bazowych oraz pomiar czasu wykonania
// operacji na zwyklych tablicach dynamicznych, wektorach oraz strukturach LIFO i FIFO.
class BadaczWydajnosci {
private:
    int* baza_tablica;
    int baza_rozmiar;

    // Metoda pomocnicza wypeniajaca tablice losowymi liczbami z zakresu 1-1000000
    void wypelnij_losowo(int* tab, int n) {
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> dis(1, 1000000);
        for (int i = 0; i < n; ++i) {
            tab[i] = dis(gen);
        }
    }

    // Metoda pomocnicza wyswietlajaca linie oddzielajaca sekcje w konsoli
    void wyswietl_linie() {
        cout << "------------------------------------------------------------\n";
    }

public:
    // Konstruktor: Alokuje pamiec dla bazy danych i generuje poczatkowe 100000 liczb
    BadaczWydajnosci() {
        baza_rozmiar = 100000;
        baza_tablica = new int[baza_rozmiar];
        wypelnij_losowo(baza_tablica, baza_rozmiar);
    }

    // Destruktor: Zwolnienie pamieci zaalokowanej dynamicznie dla bazy
    ~BadaczWydajnosci() {
        delete[] baza_tablica;
    }

    // Metoda mierzaca czas zapisu, dodawania i sortowania na zwyklych tablicach dynamicznych
    void mierz_tablice() {
        wyswietl_linie();
        cout << "OPERACJE NA TABLICY\n";
        wyswietl_linie();

        cout << "Zapis do tablicy (100000 liczb):\n";
        // Uzycie mikrosekund (chrono::micro) zamiast milisekund, aby uniknac wartosci zerowych
        auto start1 = chrono::high_resolution_clock::now();
        int* tab = new int[100000];
        for (int i = 0; i < 100000; ++i) {
            tab[i] = baza_tablica[i];
        }
        auto end1 = chrono::high_resolution_clock::now();
        chrono::duration<double, micro> czas1 = end1 - start1;
        cout << "Czas: " << fixed << setprecision(2) << czas1.count() << " us\n\n";

        cout << "Dodawanie kolejnych 100000 liczb do tablicy:\n";
        auto start2 = chrono::high_resolution_clock::now();
        int* pow_tab = new int[200000];
        for (int i = 0; i < 100000; ++i) {
            pow_tab[i] = tab[i];
        }
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> dis(1, 1000000);
        for (int i = 100000; i < 200000; ++i) {
            pow_tab[i] = dis(gen);
        }
        auto end2 = chrono::high_resolution_clock::now();
        chrono::duration<double, micro> czas2 = end2 - start2;
        cout << "Czas: " << czas2.count() << " us\n\n";

        cout << "Sortowanie tablicy:\n";
        auto start3 = chrono::high_resolution_clock::now();
        sort(pow_tab, pow_tab + 200000);
        auto end3 = chrono::high_resolution_clock::now();
        chrono::duration<double, micro> czas3 = end3 - start3;
        cout << "Czas: " << czas3.count() << " us\n";

        delete[] tab;
        delete[] pow_tab;
    }

    // Metoda mierzaca czas zapisu, dodawania i sortowania na wektorach (std::vector)
    void mierz_wektor() {
        wyswietl_linie();
        cout << "OPERACJE NA WEKTORZE\n";
        wyswietl_linie();

        cout << "Zapis do wektora (100000 liczb):\n";
        auto start1 = chrono::high_resolution_clock::now();
        vector<int> wektor;
        wektor.reserve(200000);
        for (int i = 0; i < 100000; ++i) {
            wektor.push_back(baza_tablica[i]);
        }
        auto end1 = chrono::high_resolution_clock::now();
        chrono::duration<double, micro> czas1 = end1 - start1;
        cout << "Czas: " << fixed << setprecision(2) << czas1.count() << " us\n\n";

        cout << "Dodawanie kolejnych 100000 liczb do wektora:\n";
        auto start2 = chrono::high_resolution_clock::now();
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> dis(1, 1000000);
        for (int i = 0; i < 100000; ++i) {
            wektor.push_back(dis(gen));
        }
        auto end2 = chrono::high_resolution_clock::now();
        chrono::duration<double, micro> czas2 = end2 - start2;
        cout << "Czas: " << czas2.count() << " us\n\n";

        cout << "Sortowanie wektora:\n";
        auto start3 = chrono::high_resolution_clock::now();
        sort(wektor.begin(), wektor.end());
        auto end3 = chrono::high_resolution_clock::now();
        chrono::duration<double, micro> czas3 = end3 - start3;
        cout << "Czas: " << czas3.count() << " us\n";
    }

    // Metoda mierzaca czas sortowania babelkowego oraz za pomoca struktur LIFO i FIFO
    void mierz_sortowania_specjalne() {
        vector<int> temp;
        temp.reserve(100000);
        for (int i = 0; i < 100000; ++i) {
            temp.push_back(baza_tablica[i]);
        }

        wyswietl_linie();
        cout << "SORTOWANIE BABELKOWE, LIFO I FIFO\n";
        wyswietl_linie();

        cout << "Sortowanie babelkowe:\n";
        auto start_b = chrono::high_resolution_clock::now();
        vector<int> tab_bubb = temp;
        int n = tab_bubb.size();
        for (int i = 0; i < n - 1; ++i) {
            for (int j = 0; j < n - i - 1; ++j) {
                if (tab_bubb[j] > tab_bubb[j + 1]) {
                    int bufor = tab_bubb[j];
                    tab_bubb[j] = tab_bubb[j + 1];
                    tab_bubb[j + 1] = bufor;
                }
            }
        }
        auto end_b = chrono::high_resolution_clock::now();
        chrono::duration<double, micro> czas_b = end_b - start_b;
        cout << "Czas: " << czas_b.count() << " us\n\n";

        cout << "Sortowanie LIFO (stos):\n";
        auto start_l = chrono::high_resolution_clock::now();
        stack<int> stos;
        for (int val : temp) {
            stos.push(val);
        }
        vector<int> pos_stos;
        while (!stos.empty()) {
            pos_stos.push_back(stos.top());
            stos.pop();
        }
        auto end_l = chrono::high_resolution_clock::now();
        chrono::duration<double, micro> czas_l = end_l - start_l;
        cout << "Czas: " << czas_l.count() << " us\n\n";

        cout << "Sortowanie FIFO (kolejka):\n";
        auto start_f = chrono::high_resolution_clock::now();
        queue<int> kolejka;
        for (int val : temp) {
            kolejka.push(val);
        }
        vector<int> pos_kolejka;
        while (!kolejka.empty()) {
            pos_kolejka.push_back(kolejka.front());
            kolejka.pop();
        }
        auto end_f = chrono::high_resolution_clock::now();
        chrono::duration<double, micro> czas_f = end_f - start_f;
        cout << "Czas: " << czas_f.count() << " us\n";
        wyswietl_linie();
    }
};

// Funkcja glowna programu inicjalizujaca obiekt testowy oraz uruchamiajaca pomiary
int main() {
    BadaczWydajnosci badacz;
    badacz.mierz_tablice();
    badacz.mierz_wektor();
    badacz.mierz_sortowania_specjalne();
    return 0;
}
