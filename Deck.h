#ifndef DECK_H_
#define DECK_H_

#include "Card.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class Deck
{
private:
    vector<Card *> cards;
    void clearDeck();

public:
    Deck();
    Deck(const Deck &deck);
    vector<Card *> copyDeck() const;
    ~Deck();
    vector<Card *>& getCards();
    Card* fetchCard();
    int getNumberOfCards();
    string toString();
};

#endif