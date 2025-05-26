#pragma once
#include "AbstractPlayer.h"

// Klasa reprezentuj¹ca gracza sterowanego przez cz³owieka
class HumanPlayer : public AbstractPlayer {
public:
    HumanPlayer();           // Konstruktor
    virtual ~HumanPlayer();  // Destruktor

    virtual char getGuess() override; // Pobiera literê od u¿ytkownika
};
