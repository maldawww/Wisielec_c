#pragma once
#include <string>
#include <set>

// Klasa odpowiedzialna za zapis i odczyt stanu gry
class SaveManager {
private:
    std::string filename; // Nazwa pliku zapisu

public:
    SaveManager(const std::string& file); // Konstruktor

    // Zapisuje dane do pliku
    void saveGame(const std::string& wordToGuess,
        const std::string& revealedWord,
        const std::set<char>& guessedLetters,
        int mistakes);

    // Wczytuje dane z pliku, zwraca true jeœli sukces
    bool loadGame(std::string& wordToGuess,
        std::string& revealedWord,
        std::set<char>& guessedLetters,
        int& mistakes);
};
