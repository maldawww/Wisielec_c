#pragma once
#include "AbstractPlayer.h"

// Klasa reprezentująca gracza sterowanego przez człowieka
class HumanPlayer : public AbstractPlayer {
public:
    HumanPlayer();           // Konstruktor
    virtual ~HumanPlayer();  // Destruktor

    virtual char getGuess() override; // Pobiera literę od użytkownika
};
