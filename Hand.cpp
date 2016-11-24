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

vector<Card *> Hand::getHand(){
    return hand;
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
    int counter = 0;
    Card * cardAns = hand[0];

    for (unsigned int j = 1; j < hand.size(); ++j) {
        if (hand[i]->isSamePrefix(hand[j])){
            counter++;
            if(counter>maxCounter){
                maxCounter=counter;
            }
            else if(counter==maxCounter) {
                cardAns = hand[j];
            }
        }
        else{
            i=j;
            counter=0;
        }
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


Hand::~Hand(){}

//TO DELETE
Card *Hand::getFirstCard() {
    for (Card *c : hand) {
        return c;
    }
    return nullptr;
}
