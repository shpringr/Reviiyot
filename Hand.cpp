#include "Card.h"
#include "Hand.h"

using namespace std;

Hand::Hand():hand(){}
bool Hand::addCard(Card &card)
{
    hand.push_back(&card);
    return true;
}

bool Hand::removeCard(Card &card) {
    hand.remove(&card);
    return false;
}

int Hand::getNumberOfCards() {
    return hand.size();
}

int Hand::getNumberOfSamePrefix(Card* card)
{
    int count = 0;

    for (Card *c : hand) {
        if (c->isSamePrefix(card))
        {
            count++;
        }
    }

    return count;
}


vector<Card *> Hand::searchCardsWithSamePref(Card *card) {
    vector<Card *> cards;
    for (Card *c : hand) {
        if (c->isSamePrefix(card)) {
            cards.push_back(c);
        }
    }

    return cards;
}

void Hand::discardSet(Card *currCard) {
    for (Card *card : searchCardsWithSamePref(currCard)) {
        removeCard(*card);
        delete card;
    }
}

bool compare(Card *c1, Card *c2) { return (c1->compare(c2) < 0); }

string Hand::toString() {

    string s;
    hand.sort(compare);

    for (Card *c : hand) {
        s += c->toString() + " ";
    }

    return s;
}

/*
Card* Hand::getHighestAmount(){
    auto it = hand.begin();
    auto nx = next(it,1);

    hand.sort(compare);
    int tempCounter;
    int higherCounter;
    int count = 0;
    Card * temp;

    for (Card *c : hand) {

        if (c->isSamePrefix(card))
        {
            count++;
        }
    }

    return count;




}*/



Card * Hand::getTheHighestValue()
{
    hand.sort(compare);
    return hand.back();
}


Card * Hand::getTheLowestValue()
{
    hand.sort(compare);
    return hand.front();
}


Hand::~Hand(){}

//TO DELETE
Card *Hand::getFirstCard() {
    for (Card *c : hand) {
        return c;
    }
    return nullptr;
}
