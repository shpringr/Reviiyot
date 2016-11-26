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

public:
    Hand();
    Hand(const Hand &hand_);

    bool addCard(Card &card);
    bool removeCard(Card &card);
    Card* getHighestAmount();
    vector<Card *> getHand() const;
    vector<Card *> getHand();
    int getNumberOfSamePrefix(Card &card);
    Card* getHighestAmount();
    int getNumberOfCards();
    Card * getTheHighestValue();
    Card * getTheLowestValue();
    string toString();
    vector<Card *> searchCardsWithSamePrefix(Card& card);
    void discardSet(Card* currCard);
    Card* getLowestAmount();
    virtual ~Hand() = 0;
//    Hand *clone();
//    vector<Card *> copyHand() const;
};

#endif