#include <iostream>
#include <string>
#include "Game.h"
#include "HumanPlayer.h"
#include "ComputerPlayer.h"
#include "ScoreManager.h"
#include "SaveManager.h"

int main() {
    std::cout << "=== WISIELEC ===\n";

    // Wybór trybu gry
    std::cout << "Wybierz tryb gry:\n";
    std::cout << "1. Gracz vs Komputer\n";
    std::cout << "2. Komputer vs Slowo\n";
    int choice;
    std::cin >> choice;

    AbstractPlayer* player = nullptr;

    if (choice == 1)
        player = new HumanPlayer();
    else
        player = new ComputerPlayer();

    Game game(player);

    std::cout << "Czy chcesz kontynuowac zapisana gre? (t/n): ";
    char kont;
    std::cin >> kont;

    if (kont == 't' || kont == 'T') {
        SaveManager save("save.txt");
        std::string word, revealed;
        std::set<char> guessed;
        int mistakes;

        if (save.loadGame(word, revealed, guessed, mistakes)) {
            std::cout << "Wczytano zapis gry.\n";
            game.loadState(word, revealed, guessed, mistakes); 
        }
        else {
            std::cout << "Nie udalo siê wczytac gry. Zaczynamy od nowa.\n";
        }
    }

    game.run();

    // Po zakoñczeniu gry – pytanie o nick i zapis wyniku
    std::cout << "Podaj swoj nick: ";
    std::string nick;
    std::cin >> nick;

    ScoreManager sm("ranking.txt");
    sm.addScore(nick, player->getMistakes());

    std::cout << "\nCzy chcesz zobaczyc ranking? (t/n): ";
    char r;
    std::cin >> r;

    if (r == 't' || r == 'T') {
        sm.displayRanking();
    }

    std::cout << "\nDziekujemy za gre!\n";
    return 0;
}
