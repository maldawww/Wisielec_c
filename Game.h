#pragma once
#include "WordProvider.h"
#include "AbstractPlayer.h"

// Klasa zarz�dzaj�ca logik� gry Wisielec
class Game {
private:
    WordProvider provider;         // Slowa
    AbstractPlayer* player;        // Wska�nik do gracza (cz�owiek/komputer)
    std::string wordToGuess;       // Pe�ne s�owo
    std::string revealedWord;      // Ods�oni�ta cz�� s�owa (np. "_ _ a _ _")
    const int maxMistakes = 6;     // Maksymalna liczba b��d�w
    bool fromSave = false; // czy gra zosta�a za�adowana z pliku


public:
    Game(AbstractPlayer* p);       // Konstruktor przyjmuj�cy gracza
    ~Game();                       // Destruktor

    void run();                    // Uruchamia p�tl� gry
    bool isGameWon() const;       // Czy gra zosta�a wygrana
    void displayState() const;    // Wy�wietla aktualny stan gry


    void loadState(const std::string& word,
        const std::string& revealed,
        const std::set<char>& guessedLetters,
		int mistakes); // �adowanie stanu gry
};
