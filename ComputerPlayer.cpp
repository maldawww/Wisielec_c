#include "ComputerPlayer.h"
#include <ctime>
#include <iostream>
#include <thread>
#include <chrono>

ComputerPlayer::ComputerPlayer()
    : AbstractPlayer(), rng(static_cast<unsigned>(time(nullptr))) // inicjalizacja RNG
{}

ComputerPlayer::~ComputerPlayer() {}

char ComputerPlayer::getGuess() {
    std::this_thread::sleep_for(std::chrono::seconds(2)); // opóŸnienie 1 sekundy
    const std::string alphabet = "abcdefghijklmnopqrstuvwxyz";
    std::uniform_int_distribution<int> dist(0, static_cast<int>(alphabet.size() - 1));

    // Szukaj losowej litery, której jeszcze nie by³o
    char guess;
    do {
        guess = alphabet[dist(rng)];
    } while (hasGuessed(guess));

    std::cout << "Komputer zgaduje: " << guess << std::endl;
    return guess;
}
