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


Card::~Card() {}

Shape Card::getShape() {
    return shape;
}

void Card::setShape(Shape &shap) {
    shape = shap;
}

FigureCard::FigureCard(char figu, char shap) {
    setFigure(figureSymbolsToNames[figu]);
    setShape(shapeSymbolsToNames[shap]);
}

void FigureCard::setFigure(Figure figur) {
    figure = figur;
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

    if (NumericCard *nc = dynamic_cast<NumericCard *>(card)) {
        return 1;
    }

    FigureCard *fc = dynamic_cast<FigureCard *>(card);

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

string FigureCard::toString() {
    stringstream ss;

    ss << figureNamesToSymbols[getFigure()];
    ss << shapeNamesToSymbols[getShape()];
    return ss.str();
}


NumericCard::NumericCard(int num, char shap) {
    setNumber(num);
    setShape(shapeSymbolsToNames[shap]);
}

int NumericCard::getNumber() {
    return number;
}

void NumericCard::setNumber(int num) {
    number = num;
}

bool NumericCard::isSamePrefix(Card *card)
{
    if (NumericCard *nc = dynamic_cast<NumericCard *>(card)) {
        return (this->getNumber() == nc->getNumber());
    }

    return false;
}

int NumericCard::compare(Card *card) {

    if (FigureCard *fc = dynamic_cast<FigureCard *>(card)) {
        return -1;
    }

    NumericCard *nc = dynamic_cast<NumericCard *>(card);

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

string NumericCard::toString() {
    stringstream ss;
    ss << getNumber();
    ss << shapeNamesToSymbols[getShape()];

    return ss.str();
}