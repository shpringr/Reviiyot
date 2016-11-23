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

string Deck::toString()
{
	string s;

	for (unsigned int i = 0; i < cards.size(); ++i)
	{
		s += cards[i]->toString() + " ";
	}

	return s;
}