#include "../include/Deck.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib> // for exit()
#include <vector>
using namespace std;

vector<Card *> Deck::getCards()
{
	return cards;
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
