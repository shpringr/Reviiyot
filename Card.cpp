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
Card::~Card() {}

Shape Card::getShape() {
    return shape;
}

FigureCard::FigureCard(char figu, char shap):Card(shapeSymbolsToNames[shap]),figure(figureSymbolsToNames[figu]) {
}

Figure FigureCard::getFigure() {
    return figure;
}

bool FigureCard::isSamePrefix(Card *card)
{
    if (FigureCard *fc = dynamic_cast<FigureCard *>(card)) {
        return (figureNamesToSymbols[this->getFigure()] == figureNamesToSymbols[fc->getFigure()]);
    }

    return false;
}

int FigureCard::compare(Card *card) {

    if(FigureCard *fc = dynamic_cast<FigureCard *>(card)) {
        if (this->getFigure() > fc->getFigure())
            return 1;
        else if (this->getFigure() < fc->getFigure())
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

string FigureCard::toString() {
    stringstream ss;

    ss << figureNamesToSymbols[getFigure()];
    ss << shapeNamesToSymbols[getShape()];
    return ss.str();
}


NumericCard::NumericCard(int num, char shap) :Card(shapeSymbolsToNames[shap]),number(num) {
}

int NumericCard::getNumber() {
    return number;
}

bool NumericCard::isSamePrefix(Card *card)
{
    if (NumericCard *nc = dynamic_cast<NumericCard *>(card)) {
        return (this->getNumber() == nc->getNumber());
    }

    return false;
}

int NumericCard::compare(Card *card) {
    if (NumericCard *nc = dynamic_cast<NumericCard *>(card)) {

        if (this->getNumber() > nc->getNumber())
            return 1;
        else if (this->getNumber() < nc->getNumber())
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

string NumericCard::toString() {
    stringstream ss;
    ss << getNumber();
    ss << shapeNamesToSymbols[getShape()];

    return ss.str();
}