==============================
    GRA WISIELEC (C++)
==============================

Autor: Dawid Malec
Projekt semestralny z Programowania Obiektowego
Rok: 2025

------------------------------
1. Opis programu
------------------------------
Gra "Wisielec" to klasyczna gra słowna uruchamiana w konsoli.
Gracz ma za zadanie odgadnąć losowe słowo, podając litery.
Za każdą błędną literę gracz traci jedną z 6 szans.
Gra kończy się wygraną (odgadnięcie słowa) lub przegraną (wykorzystanie wszystkich prób).

------------------------------
2. Obsługa błędów
------------------------------
- Brak pliku `slowa.txt` powoduje przerwanie gry z komunikatem.
- Próba wczytania błędnego zapisu `save.txt` kończy się uruchomieniem nowej gry.

------------------------------
3. Pliki tekstowe
------------------------------
- slowa.txt – lista słów używanych w grze (jedno słowo na linię)
- save.txt – zapis stanu gry (tworzy się automatycznie po każdej turze)
- ranking.txt – zapis wyników graczy

------------------------------
4. Uruchomienie gry
------------------------------
1. Skopiuj wszystkie pliki `.exe`, `.txt` oraz bibliotek do jednego folderu.
2. Uruchom plik wykonywalny `Wisielec.exe` (lub uruchom `main.cpp` w Visual Studio).
3. Wybierz tryb gry:
   - Gracz vs Komputer (gracz zgaduje litery)
   - Komputer vs słowo (komputer sam zgaduje litery)
4. Program zapyta, czy chcesz kontynuować zapisaną grę.
5. Po zakończeniu gry podaj nick – wynik zostanie zapisany do rankingu.

------------------------------
5. Funkcje programu
------------------------------
- Gra jednoosobowa lub jako komputer
- Automatyczny zapis po każdej turze
- Wczytywanie zapisu przy ponownym uruchomieniu
- System rankingowy z możliwością wyświetlenia wyników

------------------------------
6. Kontrola danych
------------------------------
- Program weryfikuje, czy wprowadzona litera jest poprawna.
- Jeśli litera była już zgadywana, program o tym informuje.
- Litery są rozpoznawane bez rozróżniania wielkości (A = a).




========================================
SPECYFIKACJA DANYCH WEJŚCIOWYCH I WYJŚCIOWYCH
========================================


DANE WEJŚCIOWE
==============

Źródło:         slowa.txt
Format:         Plik tekstowy (UTF-8)
Opis:           Lista słów używanych w grze. Jedno słowo na linię, bez polskich znaków.
Przykład:       komputer
                algorytm
                tablica


Źródło:         Konsola (użytkownik)
Format:         Litera (char)
Opis:           Gracz podaje jedną literę w każdej turze.


Źródło:         Konsola (menu startowe)
Format:         Liczba całkowita (int)
Opis:           Wybór trybu gry:
                1 – gracz vs komputer
                2 – komputer vs słowo


Źródło:         Konsola (czy kontynuować grę)
Format:         Znak (t/n)
Opis:           Gracz wybiera, czy kontynuować grę z zapisu.


Źródło:         Konsola (nick)
Format:         Tekst (string)
Opis:           Gracz podaje swój nick po zakończeniu gry – zapisywany w rankingu.


DANE WYJŚCIOWE
==============

Miejsce:        Konsola
Format:         Tekst
Opis:           Informacje o stanie gry:
                - aktualne słowo (np. _ _ a _ _)
                - liczba błędów
                - komunikaty o wygranej/przegranej


Miejsce:        Konsola
Format:         Grafika ASCII
Opis:           Wisielec w formie rysunku zmieniający się przy każdym błędzie.


Plik:           ranking.txt
Format:         Plik tekstowy
Opis:           Lista wyników graczy w formacie: nick liczba_bledow


Plik:           save.txt
Format:         Plik tekstowy
Opis:           Stan zapisanej gry:
                - słowo do odgadnięcia
                - aktualna postać słowa
                - liczba błędów
                - litery już zgadnięte


Diagram klas:  diagram.png
Opis:           Plik diagramu klas lub obrazek zrzutu ekranu z Visual Studio.
                Dołączony do dokumentacji.


UWAGI
=====

- Program waliduje dane: nie przyjmuje cyfr, znaków specjalnych ani pustych wejść.
- Należy używać tylko znaków ASCII.
- Pliki `save.txt` i `ranking.txt` tworzą się automatycznie w katalogu projektu.

