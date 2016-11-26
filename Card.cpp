#include "Card.h"
#include <sstream>
#include <map>

using namespace std;

map<char, Shape> shapeSymbolsToNames = {
        {'C', Shape::Club},
        {'D', Shape::Diamond},
        {'H', Shape::Heart},
        {'S', Shape::Spade}
};


map<char, Figure> figureSymbolsToNames = {
        {'J', Figure::Jack},
        {'Q', Figure::Queen},
        {'K', Figure::King},
        {'A', Figure::Ace}
};


map<Shape, char> shapeNamesToSymbols = {
        {Shape::Club,    'C'},
        {Shape::Diamond, 'D'},
        {Shape::Heart,   'H'},
        {Shape::Spade,   'S'}
};


map<Figure, char> figureNamesToSymbols = {
        {Figure::Jack,  'J'},
        {Figure::Queen, 'Q'},
        {Figure::King,  'K'},
        {Figure::Ace,   'A'}
};

Card::Card(Shape shap):shape(shap) {}

Card::Card(const Card& card):shape(card.getShape())  {}

FigureCard::FigureCard(const FigureCard &figure_card) : Card(figure_card) , figure(figure_card.getFigure()) {}

NumericCard::NumericCard(const NumericCard &numeric_card): Card(numeric_card), number(numeric_card.getNumber()) {}


Card *NumericCard::clone() {
    return new NumericCard(*this);
}

Card *FigureCard::clone() {
    return new FigureCard(*this);
}


/*

Player::Player(const Player& player): name(player.getName()) {}

PlayerType1::PlayerType1(const PlayerType1 &player) : Player(player) {}

Player *PlayerType1::clone() {
    return new PlayerType1(*this);
}
*/




Card::~Card() {}

Shape Card::getShape()const {
    return shape;
}

FigureCard::FigureCard(char figu, char shap):Card(shapeSymbolsToNames[shap]),figure(figureSymbolsToNames[figu]) {
}

bool FigureCard::isSamePrefix(Card &card)
{
    if (FigureCard *fc = dynamic_cast<FigureCard *>(&card))
    {
        return (getPrefix() == fc->getPrefix());
    }

    return false;
}

int FigureCard::compare(Card &card) {

    if(FigureCard *fc = dynamic_cast<FigureCard *>(&card))
    {
        if (this->figure > fc->figure)
            return 1;
        else if (this->figure < fc->figure)
            return -1;
        else if (this->getShape() > fc->getShape())
            return 1;
        else if (this->getShape() < fc->getShape())
            return -1;
        else
            return 0;
    }
    return 1;
}

string FigureCard::getPrefix()
{
    stringstream ss;
    ss << figureNamesToSymbols[figure];
    return ss.str();
}

char Card::getShapeChar(){
    return shapeNamesToSymbols[shape];
}


string FigureCard::toString() {
    return getPrefix() + shapeNamesToSymbols[getShape()];

}

Figure FigureCard::getFigure()const {
    return this->figure;
}


NumericCard::NumericCard(int num, char shap) :Card(shapeSymbolsToNames[shap]),number(num) {
}

bool NumericCard::isSamePrefix(Card &card)
{
    if (NumericCard *nc = dynamic_cast<NumericCard *>(&card))
    {
        return (this->getPrefix() == nc->getPrefix());
    }

    return false;
}

int NumericCard::compare(Card &card) {

    if (NumericCard* nc = dynamic_cast<NumericCard *>(&card))
    {
        if (this->number > nc->number)
            return 1;
        else if (this->number < nc->number)
            return -1;
        else if (this->getShape() > nc->getShape())
            return 1;
        else if (this->getShape() < nc->getShape())
            return -1;
        else
            return 0;
    }
    return -1;
}

string NumericCard::getPrefix()
{
    stringstream ss;
    ss << number;
    return ss.str();
}

string NumericCard::toString() {
    return getPrefix() + shapeNamesToSymbols[getShape()];
}

int NumericCard::getNumber()const {
    return this->number;
}



