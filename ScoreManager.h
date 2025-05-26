#pragma once
#include <string>
#include <vector>

// Struktura przechowuj�ca pojedynczy wpis w rankingu
struct ScoreEntry {
    std::string nickname;
    int mistakes;
};

// Klasa odpowiedzialna za zapis i odczyt wynik�w graczy
class ScoreManager {
private:
    std::string filename; // Nazwa pliku z wynikami

public:
    ScoreManager(const std::string& file); // Konstruktor

    // Dodaje wynik gracza do pliku
    void addScore(const std::string& nickname, int mistakes);

    // Wczytuje i zwraca ranking graczy
    std::vector<ScoreEntry> loadScores() const;

    // Wy�wietla ranking na ekranie
    void displayRanking() const;


};
