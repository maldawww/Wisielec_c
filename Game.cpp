#include "Game.h"
#include "SaveManager.h"

#include <iostream>
#include <algorithm>
#include <cctype>

Game::Game(AbstractPlayer* p)
    : player(p) {}

Game::~Game() {
    delete player; // Zwolnij gracza jeœli by³ utworzony dynamicznie
}

void Game::run() {
    if (!provider.loadFromFile("slowa.txt")) {
        std::cerr << "Nie udalo siê wczytac pliku slowa.txt\n";
        return;
    }

    if (!fromSave) {
        wordToGuess = provider.getRandomWord();
        revealedWord = std::string(wordToGuess.length(), '_');
    }

    while (!player->hasLost(maxMistakes) && !isGameWon()) {
        displayState();

        char guess = player->getGuess();
        guess = std::tolower(guess);

        if (player->hasGuessed(guess)) {
            std::cout << "Ta litera juz byla.\n";
            continue;
        }

        player->addGuessedLetter(guess);

        bool correct = false;
        for (size_t i = 0; i < wordToGuess.length(); ++i) {
            if (std::tolower(wordToGuess[i]) == guess) {
                revealedWord[i] = wordToGuess[i];
                correct = true;
            }
        }

        if (!correct) {
            std::cout << "Bledna litera!\n";
            player->addMistake();
        }
		SaveManager save("save.txt");
		save.saveGame(wordToGuess, revealedWord, player->getGuessedLetters(), player->getMistakes()); // Zapisz stan gry


    }

    displayState();

    if (isGameWon()) {
        std::cout << "Gratulacje! Odgadles slowo: " << wordToGuess << "\n";
    }
    else {
        std::cout << "Przegrales. Prawidlowe slowo to: " << wordToGuess << "\n";
    }
}

bool Game::isGameWon() const {
    return revealedWord == wordToGuess;
}


void printHangman(int mistakes) {
    std::cout << "\n";
    std::cout << " +---+\n";
    std::cout << " |   |\n";

    if (mistakes >= 1) std::cout << " |   O\n";
    else               std::cout << " |\n";

    if (mistakes == 2) std::cout << " |   |\n";
    else if (mistakes == 3) std::cout << " |  /|\n";
    else if (mistakes >= 4) std::cout << " |  /|\\\n";
    else                    std::cout << " |\n";

    if (mistakes == 5) std::cout << " |  /\n";
    else if (mistakes >= 6) std::cout << " |  / \\\n";
    else                    std::cout << " |\n";

    std::cout << "-+-\n\n";
}

void Game::displayState() const {
    std::cout << "-------------------------------------- ";

    std::cout << "\nSlowo: " << revealedWord << "\n";
    std::cout << "Zgadywane litery: ";
    for (char c : player->getGuessedLetters()) {
        std::cout << c << ' ';

    }
    printHangman(player->getMistakes());

}

void Game::loadState(const std::string& word, const std::string& revealed, const std::set<char>& guessedLetters, int mistakes) {
    wordToGuess = word;
    revealedWord = revealed;

    // Wyczyœæ stare litery i ustaw nowe
    for (char c : guessedLetters) {
        player->addGuessedLetter(c);
    }

    // Ustaw liczbê b³êdów
    for (int i = 0; i < mistakes; ++i) {
        player->addMistake();
    }

    fromSave = true;

}


