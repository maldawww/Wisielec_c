#pragma once
#include <set>
#include <string>

// Klasa bazowa dla gracza (cz³owieka lub komputera)
class AbstractPlayer {
protected:
    std::set<char> guessedLetters; // Litery, które ju¿ zosta³y podane
    int mistakes;                  // Liczba b³êdów

public:
    AbstractPlayer(); // Konstruktor

    virtual ~AbstractPlayer() = default; // Wirtualny destruktor

    virtual char getGuess() = 0; // Metoda czysto wirtualna - zgadniêcie litery

    bool hasGuessed(char letter) const;       // Czy litera ju¿ by³a podana
    void addGuessedLetter(char letter);       // Dodaj literê do u¿ytych
    void addMistake();                        // Dodaj b³¹d
    int getMistakes() const;                  // Pobierz liczbê b³êdów
    bool hasLost(int maxMistakes) const;      // Czy gracz przegra³
    const std::set<char>& getGuessedLetters() const; // Zwraca u¿yte litery
};
