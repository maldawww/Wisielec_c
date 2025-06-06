#pragma once
#include <string>
#include <vector>

// Struktura przechowująca pojedynczy wpis w rankingu
struct ScoreEntry {
    std::string nickname;
    int mistakes;
};

// Klasa odpowiedzialna za zapis i odczyt wyników graczy
class ScoreManager {
private:
    std::string filename; // Nazwa pliku z wynikami

public:
    ScoreManager(const std::string& file); // Konstruktor

    // Dodaje wynik gracza do pliku
    void addScore(const std::string& nickname, int mistakes);

    // Wczytuje i zwraca ranking graczy
    std::vector<ScoreEntry> loadScores() const;

    // Wyświetla ranking na ekranie
    void displayRanking() const;


};
