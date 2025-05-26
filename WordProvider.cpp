#include "WordProvider.h"
#include <fstream>
#include <iostream>
#include <ctime>
#include <cstdlib>

WordProvider::WordProvider() {
    // Inicjalizacja generatora losowego 
    std::srand(static_cast<unsigned>(std::time(nullptr)));
}

bool WordProvider::loadFromFile(const std::string& filename) {
    std::ifstream file(filename);

    if (!file.is_open()) {
        std::cerr << "Nie mozna otworzyc pliku: " << filename << std::endl;
        return false;
    }

    std::string word;
    while (file >> word) {
        words.push_back(word);
    }

    file.close();
    return !words.empty(); // sukces, jeœli przynajmniej jedno s³owo
}

std::string WordProvider::getRandomWord() const {
    if (words.empty()) return "";

    int index = std::rand() % words.size();
    return words[index];
}

int WordProvider::getWordCount() const {
    return static_cast<int>(words.size());
}
