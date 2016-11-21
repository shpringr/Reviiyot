#include "Deck.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib> // for exit()
#include <vector>
using namespace std;

//Deck::Deck() {
//	vector<Card *> emptyVector;
//	cards = emptyVector;
//}
//

 vector<Card *> & Deck ::getCards()
{
	return cards;
}
//
//Card* Deck::fetchCard(){
//	cards.pop_back();
//}

string Deck::toString()
{
	string s;

	for (unsigned int i = 0; i < cards.size(); ++i)
	{

	s += cards[i]->toString() + " ";
	}

	return s;
}

