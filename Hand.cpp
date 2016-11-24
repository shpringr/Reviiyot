#include <algorithm>
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

    vector<Card *>::iterator it;
    for (it = hand.begin(); it != hand.end(); ++it){
        if ((*it)->compare(&card) == 0){
            hand.erase(it);
            return true;
        }
    }

    return false;
}

int Hand::getNumberOfCards() {
    return (int) hand.size();
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
    std::sort (hand.begin()+4, hand.end(), compare);

    for (Card *c : hand) {
        s += c->toString() + " ";
    }

    return s;
}

/*

Card* Hand::getHighestAmount()
{
    std::sort (hand.begin()+4, hand.end(), compare);

    auto it = hand.begin();
    auto nx = next(it,1);

    std::sort (hand.begin()+4, hand.end(), compare);
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
}
*/



Card * Hand::getTheHighestValue()
{

    std::sort (hand.begin()+4, hand.end(), compare);
    return hand.back();
}


Card * Hand::getTheLowestValue()
{
    std::sort (hand.begin()+4, hand.end(), compare);
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
