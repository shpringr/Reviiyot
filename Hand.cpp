#include <algorithm>
#include "Card.h"
#include "Hand.h"

using namespace std;

Hand::Hand():hand(){}

Hand::Hand(const Hand& hand_): hand(){
    hand = hand_.copyHand();
}

vector<Card *>  Hand::copyHand() const {
    vector<Card *> newHand;
    for (unsigned int i = 0; i < hand.size(); ++i) {
        newHand.push_back(hand[i]->clone());
    }
    return newHand;
}


bool Hand::addCard(Card &card)
{
    hand.push_back(&card);
    return true;
}

bool Hand::removeCard(Card &card) {

    vector<Card *>::iterator it;

    for (it = hand.begin(); it != hand.end(); ++it){
        if ((*it)->compare(card) == 0){
            hand.erase(it);
            return true;
        }
    }

    return false;
}

int Hand::getNumberOfCards() {
    return (int)hand.size();
}

int Hand::getNumberOfSamePrefix(Card& card)
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


vector<Card *> Hand::searchCardsWithSamePrefix(Card& card) {
    vector<Card *> cards;
    for (Card *c : hand) {
        if (c->isSamePrefix(card)) {
            cards.push_back(c);
        }
    }

    return cards;
}

void Hand::discardSet(Card* currCard) {
    for (Card* card : searchCardsWithSamePrefix(*currCard)) {
        removeCard(*card);
        delete card;
    }
}

bool compare(Card *c1, Card *c2) { return (c1->compare(*c2) < 0); }

string Hand::toString() {

    string s;
    std::sort (hand.begin(), hand.end(), compare);

    for (Card *c : hand) {
        s += c->toString() + " ";
    }

    return s;
}


Card* Hand::getHighestAmount()
{
    std::sort (hand.begin(), hand.end(), compare);
    int i=0;
    int maxCounter=0;
    int counter = 1;
    Card * cardAns = hand[0];

    for (unsigned int j = 1; j < hand.size(); ++j) {
        if (hand[i]->isSamePrefix(*hand[j])){
            counter++;

        }
        else{
            if(counter>maxCounter){
                maxCounter=counter;
                cardAns = hand[i];

            }
            else if(counter==maxCounter) {
                cardAns = hand[i];
            }
            i=j;
            counter=1;
        }
    }
    if(counter>=maxCounter){
        cardAns=hand.back();
    }

    return cardAns;
}


Card* Hand::getLowestAmount()
{
    std::sort (hand.begin(), hand.end(), compare);
    int i=0;
    int minCounter=4;
    int counter = 1;
    Card * cardAns = hand[0];

    for (unsigned int j = 1; j < hand.size(); ++j) {
        if (hand[i]->isSamePrefix(*hand[j])){
            counter++;

        }
        else{
            if(counter<minCounter){
                minCounter=counter;
                cardAns = hand[i];

            }
            i=j;
            counter=1;
        }
    }
    if(counter<minCounter){
        cardAns=hand.back();
    }

    return cardAns;
}



Card * Hand::getTheHighestValue()
{
    std::sort (hand.begin(), hand.end(), compare);
    return hand.back();
}


Card * Hand::getTheLowestValue()
{
    std::sort (hand.begin(), hand.end(), compare);
    return hand.front();
}

Hand::~Hand(){
    clearHand();
}

void Hand::clearHand() {
for (unsigned int i = 0; i < hand.size(); ++i) {
        delete (hand[i]);
    }
}
