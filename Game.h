#ifndef GAME_H_
#define GAME_H_

#include "Player.h"
#include "Deck.h"
#include <iostream>
#include <vector>

using namespace std;

class Game {
private:
    vector<Player *> players;
    Deck deck;
    bool isVerbalOn;
    int N;

    void readConfigFile(char *configurationFile);
    void dummyConfig1();
    void dummyConfig2();
    void dummyConfig3();
    int numberOfTurns = 0;

    void addCardAndDiscardIfNeeded(Player *player, Card *card);
    void increaseNumberOfTurns();
    bool isThereAWinner();

public:
    Game(char *configurationFile);
    Game(const Game& game);
    void init();
    void play();
    void printState();
    void printWinner();
    void printNumberOfTurns();
};

#endif