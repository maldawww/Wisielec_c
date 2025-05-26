#include "AbstractPlayer.h"
#include <cctype>

AbstractPlayer::AbstractPlayer()
    : mistakes(0) // inicjalizacja liczby b³êdów
{}

bool AbstractPlayer::hasGuessed(char letter) const {
    return guessedLetters.find(std::tolower(letter)) != guessedLetters.end();
}

void AbstractPlayer::addGuessedLetter(char letter) {
    guessedLetters.insert(std::tolower(letter));
}

void AbstractPlayer::addMistake() {
    ++mistakes;
}

int AbstractPlayer::getMistakes() const {
    return mistakes;
}

bool AbstractPlayer::hasLost(int maxMistakes) const {
    return mistakes >= maxMistakes;
}

const std::set<char>& AbstractPlayer::getGuessedLetters() const {
    return guessedLetters;
}
