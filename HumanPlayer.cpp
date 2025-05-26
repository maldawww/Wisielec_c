#include "HumanPlayer.h"
#include <iostream>
#include <limits>

HumanPlayer::HumanPlayer() : AbstractPlayer() {}

HumanPlayer::~HumanPlayer() {}

char HumanPlayer::getGuess() {
    char letter;

    // Pêtla a¿ do wprowadzenia poprawnej jednej litery
    while (true) {
        std::cout << "Podaj litere: ";
        std::cin >> letter;

        // Walidacja – sprawdzenie czy to jest litera
        if (!std::isalpha(letter)) {
            std::cout << "To nie jest litera. Sprobuj ponownie.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        // Zamiana na ma³¹ literê i zwrot
        return std::tolower(letter);
    }
}
