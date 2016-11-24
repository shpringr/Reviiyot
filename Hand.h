#ifndef HAND_H_
#define HAND_H_

#include "Card.h"
#include <iostream>
#include <list>
#include <vector>
#include <iterator>

using namespace std;

class Hand {
private:
    vector<Card *> hand;
protected:
    Hand();

public:
    bool addCard(Card &card);
    bool removeCard(Card &card);
    int getNumberOfSamePrefix(Card *card);
   Card* getHighestAmount();
    vector<Card *> getHand();
    int getNumberOfCards();
    Card * getTheHighestValue();
    Card * getTheLowestValue();
    string toString();
    vector<Card *> searchCardsWithSamePref(Card *card);
    void discardSet(Card *currCard);
    Card *getFirstCard();
    Card *getLowestAmount();
    virtual ~Hand() = 0;


};

#endif