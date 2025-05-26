#pragma once
#include <vector>
#include <string>

// Klasa odpowiedzialna za wczytywanie s³ów i losowanie jednego z nich
class WordProvider {
private:
    std::vector<std::string> words; // Lista s³ów

public:
    WordProvider();  // Konstruktor

    // Wczytuje s³owa z pliku tekstowego
    bool loadFromFile(const std::string& filename);

    // Zwraca losowe s³owo z listy
    std::string getRandomWord() const;

    // Zwraca liczbê wczytanych s³ów
    int getWordCount() const;
};
