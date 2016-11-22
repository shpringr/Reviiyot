#include "Card.h"
#include "Hand.h"
#include <iostream>

using namespace std;
/*
 *
class Hand {
private:
	vector<Card *> hand;
	// Declare here the collection of "Card *" of the hand
public:
	Hand();
	bool addCard(Card &card);
	bool removeCard(Card &card);
	int getNumberOfCards(); // Get the number of cards in hand
	string toString() ; // Return a list of the cards, separated by space, in one line,in a sorted order, ex: "2S 5D 10H"
};
 */


bool Hand::addCard(Card &card)
{
    //hand.(&card);
}
bool Hand::removeCard(Card &card)
{}
int Hand::getNumberOfCards()
{}// Get the number of cards in hand

string Hand::toString() {
    string s;
    for (int i = 0; i < hand.size(); ++i) {
        s += hand[i]->toString() + " ";
    }

    return s;
}

