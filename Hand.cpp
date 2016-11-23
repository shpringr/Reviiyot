#include "Card.h"
#include "Hand.h"
#include <iostream>
#include <algorithm>

using namespace std;

bool Hand::addCard(Card &card) {
    hand.push_back(&card);
}

bool Hand::removeCard(Card &card) {
    hand.remove(&card);
}

int Hand::getNumberOfCards() {
    return hand.size();
}

int Hand::getNumberOfSamePref(Card *card) {
    int count = 0;

    for (Card *c : hand) {
        if (c->isSamePrefix(card)) {
            count++;
        }
    }
    return count;
}

vector<Card *> Hand::getCardsWithSamePref(Card *card) {
    vector<Card *> cards;
    for (Card *c : hand) {
        if (c->isSamePrefix(card)) {
            cards.push_back(c);
        }
    }

    return cards;
}


bool compare(Card *c1, Card *c2) { return (c1->compare(c2) < 0); }


void Hand::discardSet(Card *currCard) {
    for (Card *card : getCardsWithSamePref(currCard)) {
        removeCard(*card);
        delete card;
    }
}

string Hand::toString() {

    string s;
 //   hand.sort(compare);

    for (Card *c : hand) {
        s += c->toString() + " ";
    }

    return s;
}

//TO DELETE
Card *Hand::getFirstCard() {
    for (Card *c : hand) {
        return c;
    }
    return nullptr;
}
