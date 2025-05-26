#include "SaveManager.h"
#include <fstream>
#include <iostream>
#include <sstream>

SaveManager::SaveManager(const std::string& file)
    : filename(file) {}

void SaveManager::saveGame(const std::string& wordToGuess,
    const std::string& revealedWord,
    const std::set<char>& guessedLetters,
    int mistakes) {
    std::ofstream file(filename);

    if (!file.is_open()) {
        std::cerr << "Nie mozna zapisac gry do pliku " << filename << "\n";
        return;
    }

    file << wordToGuess << "\n";
    file << revealedWord << "\n";
    file << mistakes << "\n";

    for (char c : guessedLetters) {
        file << c;
    }
    file << "\n";

    file.close();

	std::cout << "Gra zostala zapisana do pliku " << filename << "\n";
}

bool SaveManager::loadGame(std::string& wordToGuess,
    std::string& revealedWord,
    std::set<char>& guessedLetters,
    int& mistakes) {
    std::ifstream file(filename);

    if (!file.is_open()) {
        std::cerr << "Nie mo¿na otworzyæ pliku zapisu.\n";
        return false;
    }


    std::string line;

    // Wczytaj kolejno dane
    if (!std::getline(file, wordToGuess)) return false;
    if (!std::getline(file, revealedWord)) return false;
    if (!std::getline(file, line)) return false;

    std::istringstream iss(line);
    if (!(iss >> mistakes)) return false;

    if (!std::getline(file, line)) return false;
    guessedLetters.clear();
    for (char c : line) {
        guessedLetters.insert(c);
    }

    file.close();
	std::cout << "Gra zostala wczytana z pliku " << filename << "\n";
    return true;
}
