#include "ScoreManager.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <iomanip>

ScoreManager::ScoreManager(const std::string& file)
    : filename(file) {}

void ScoreManager::addScore(const std::string& nickname, int mistakes) {
    std::ofstream file(filename, std::ios::app); // dopisujemy do pliku

    if (file.is_open()) {
        file << nickname << " " << mistakes << "\n";
        file.close();
    }
    else {
        std::cerr << "Nie mozna zapisaæ wyniku do pliku " << filename << "\n";
    }
}

std::vector<ScoreEntry> ScoreManager::loadScores() const {
    std::vector<ScoreEntry> scores;
    std::ifstream file(filename);

    if (!file.is_open()) return scores;

    ScoreEntry entry;
    while (file >> entry.nickname >> entry.mistakes) {
        scores.push_back(entry);
    }

    file.close();
    return scores;
}

void ScoreManager::displayRanking() const {
    std::vector<ScoreEntry> scores = loadScores();

    if (scores.empty()) {
        std::cout << "Brak wynikow w rankingu.\n";
        return;
    }

    std::cout << "\n--- Ranking graczy ---\n";
    std::cout << std::left << std::setw(15) << "Nick" << "Bledy\n";
    std::cout << "----------------------------\n";

    for (const auto& entry : scores) {
        std::cout << std::left << std::setw(15) << entry.nickname << entry.mistakes << "\n";
    }

    std::cout << "----------------------------\n";
}
