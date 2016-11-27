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
protected:
    Card(Shape shap);
public:
    Card(const Card &card);
    virtual Card * clone()=0;
    Shape getShape()const;
    virtual string toString() = 0;
    virtual ~Card();
    virtual int compare(Card &card) = 0;
    virtual string getPrefix() = 0;
    virtual bool isSamePrefix(Card &card) = 0;
};

class FigureCard : public Card {
private:
    Figure figure;
public:
    FigureCard(const FigureCard &figure_card);
    virtual Card * clone() override;
    FigureCard(char figu, char shap);
    virtual string toString() override;
    virtual int compare(Card &card) override;
    virtual string getPrefix() override;
    Figure getFigure()const;
    virtual bool isSamePrefix(Card &card) override;
    virtual ~FigureCard();

};

class NumericCard : public Card {
private:
    int number;
public:
    NumericCard(const NumericCard &numeric_card);
    virtual Card * clone() override;
    NumericCard(int num, char shap);
    virtual string toString() override;
    virtual int compare(Card &card) override;
    virtual string getPrefix() override;
    virtual bool isSamePrefix(Card &card) override;
    int getNumber()const;
    virtual ~NumericCard();

};

#endif