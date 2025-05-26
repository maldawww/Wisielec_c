#pragma once
#include "AbstractPlayer.h"
#include <random>

// Klasa reprezentuj¹ca gracza komputerowego
class ComputerPlayer : public AbstractPlayer {
private:
    std::mt19937 rng; // Generator liczb losowych

public:
    ComputerPlayer();          // Konstruktor
    virtual ~ComputerPlayer(); // Destruktor

    virtual char getGuess() override; // Zwraca losow¹ literê, której jeszcze nie by³o
};


