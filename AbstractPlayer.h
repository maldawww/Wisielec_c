#pragma once
#include <set>
#include <string>

// Klasa bazowa dla gracza (cz�owieka lub komputera)
class AbstractPlayer {
protected:
    std::set<char> guessedLetters; // Litery, kt�re ju� zosta�y podane
    int mistakes;                  // Liczba b��d�w

public:
    AbstractPlayer(); // Konstruktor

    virtual ~AbstractPlayer() = default; // Wirtualny destruktor

    virtual char getGuess() = 0; // Metoda czysto wirtualna - zgadni�cie litery

    bool hasGuessed(char letter) const;       // Czy litera ju� by�a podana
    void addGuessedLetter(char letter);       // Dodaj liter� do u�ytych
    void addMistake();                        // Dodaj b��d
    int getMistakes() const;                  // Pobierz liczb� b��d�w
    bool hasLost(int maxMistakes) const;      // Czy gracz przegra�
    const std::set<char>& getGuessedLetters() const; // Zwraca u�yte litery
};
