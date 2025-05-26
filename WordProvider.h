#pragma once
#include <vector>
#include <string>

// Klasa odpowiedzialna za wczytywanie s��w i losowanie jednego z nich
class WordProvider {
private:
    std::vector<std::string> words; // Lista s��w

public:
    WordProvider();  // Konstruktor

    // Wczytuje s�owa z pliku tekstowego
    bool loadFromFile(const std::string& filename);

    // Zwraca losowe s�owo z listy
    std::string getRandomWord() const;

    // Zwraca liczb� wczytanych s��w
    int getWordCount() const;
};
