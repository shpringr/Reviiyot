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
    void clearHand();
    Card* getCardWIthHighestAmount();
    Card * getCardWithHighestValue();
    Card * getCardWithLowestValue();
    Card* getCardWithLowestAmount();
public:
    Hand();
    Hand(const Hand &hand_);
    vector<Card *>  copyHand() const;
    bool addCard(Card &card);
    bool removeCard(Card &card);
    int getNumberOfCardsWithSamePrefix(string prefix);
    int getNumberOfCards();
    string toString();
    vector<Card *> searchCardsWithSamePrefix(string prefix);
    void discardSet(string prefix);
    bool isCardInHand(Card &card);
    Card* searchCardInHand(Card & card);
    virtual ~Hand() = 0;
};

#endif