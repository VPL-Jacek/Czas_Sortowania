# Badacz Wydajnosci C++

Projekt w jezyku C++ przeznaczony do testowania i porownywania wydajnosci roznych struktur danych oraz algorytmow sortowania. Program zrealizowany jest w pelni w oparciu o programowanie obiektowe (klasy i metody) z wykorzystaniem precyzyjnych pomiarow czasu za pomoca biblioteki `std::chrono` (w mikrosekundach).

## Glowne funkcjonalnosci
- **Inicjalizacja bazowa:** Generowanie i zapobieganie zerowym pomiarom dzieki uzyciu generatora liczb losowych (`std::mt19937`) oraz mikrosekundowej precyzji.
- **Zwykle tablice dynamiczne:** Testy zapisu, realokacji (powiekszenia o kolejne 100 000 elementow) oraz sortowania.
- **Wektory (`std::vector`):** Testy tworzenia, dodawania nowych elementow i sortowania wbudowanego.
- **Algorytmy i struktury specjalne:** Pomiar czasu dla sortowania babelkowego, a także struktur LIFO (stos) oraz FIFO (kolejka).
- **Czytelny interfejs konsolowy:** Wyniki podzielone na sekcje, oddzielone liniami znakow `-` z zachowaniem czytelnych przerw (`std::endl`).
