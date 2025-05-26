#pragma once
#include "WordProvider.h"
#include "AbstractPlayer.h"

// Klasa zarz¹dzaj¹ca logik¹ gry Wisielec
class Game {
private:
    WordProvider provider;         // Slowa
    AbstractPlayer* player;        // WskaŸnik do gracza (cz³owiek/komputer)
    std::string wordToGuess;       // Pe³ne s³owo
    std::string revealedWord;      // Ods³oniêta czêœæ s³owa (np. "_ _ a _ _")
    const int maxMistakes = 6;     // Maksymalna liczba b³êdów
    bool fromSave = false; // czy gra zosta³a za³adowana z pliku


public:
    Game(AbstractPlayer* p);       // Konstruktor przyjmuj¹cy gracza
    ~Game();                       // Destruktor

    void run();                    // Uruchamia pêtlê gry
    bool isGameWon() const;       // Czy gra zosta³a wygrana
    void displayState() const;    // Wyœwietla aktualny stan gry


    void loadState(const std::string& word,
        const std::string& revealed,
        const std::set<char>& guessedLetters,
		int mistakes); // £adowanie stanu gry
};
