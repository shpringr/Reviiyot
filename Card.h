#ifndef CARD_H_
#define CARD_H_

#include <iostream>
#include <string>

using namespace std;

enum class Shape {
    Club,
    Diamond,
    Heart,
    Spade
};

enum class Figure {
    Jack,
    Queen,
    King,
    Ace
};

class Card {
private:
    Shape shape;
public:
    Shape getShape();
    void setShape(Shape &shape);
    virtual string toString() = 0;
    virtual ~Card();
    virtual int compare(Card *card) = 0;
    virtual bool isSamePrefix(Card *card) = 0;
};

class FigureCard : public Card {
private:
    Figure figure;
public:
    FigureCard(char figu, char shap);
    Figure getFigure();
    void setFigure(Figure figure);
    virtual string toString() override;
    virtual int compare(Card *card) override;
    virtual bool isSamePrefix(Card *card) override;
};

class NumericCard : public Card {
private:
    int number;
public:
    NumericCard(int num, char shap);
    int getNumber();
    void setNumber(int num);
    virtual string toString() override;
    virtual int compare(Card *card) override;
    virtual bool isSamePrefix(Card *card) override;
};

#endif