#pragma once
#include "AbstractPlayer.h"

// Klasa reprezentuj�ca gracza sterowanego przez cz�owieka
class HumanPlayer : public AbstractPlayer {
public:
    HumanPlayer();           // Konstruktor
    virtual ~HumanPlayer();  // Destruktor

    virtual char getGuess() override; // Pobiera liter� od u�ytkownika
};
