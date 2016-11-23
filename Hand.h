#ifndef HAND_H_
#define HAND_H_

#include "Card.h"
#include <iostream>
#include <list>
#include <vector>

using namespace std;

class Hand {
private:
    list<Card *> hand;

public:
    bool addCard(Card &card);
    bool removeCard(Card &card);
    int getNumberOfSamePref(Card *card);
    int getNumberOfCards();
    string toString();
    vector<Card *> getCardsWithSamePref(Card *card);
    void discardSet(Card *currCard);
    Card *getFirstCard();
};

#endif