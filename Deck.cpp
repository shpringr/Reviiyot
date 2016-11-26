#include "Deck.h"

using namespace std;

Deck::Deck():cards(){}
 vector<Card *>& Deck::getCards()
{
	return cards;
}

Card* Deck::fetchCard()
{
	Card* temp = cards.front();
	cards.erase(cards.begin());
	return temp;
}

int Deck::getNumberOfCards(){
	return (int)cards.size();
}


void Deck::addCardToCopyDeck(char shape, string prefix) {

    bool isDigit = isdigit(prefix[0]);

    if (isDigit) {
        int numericPrefix = atoi(prefix.c_str());
        cards.push_back(new NumericCard(numericPrefix, shape));
    }
    else
        cards.push_back(new FigureCard(prefix[0], shape));
}


string Deck::toString()
{
	string s;

	for (unsigned int i = 0; i < cards.size(); ++i)
	{
		s += cards[i]->toString() + " ";
	}

	return s;
}