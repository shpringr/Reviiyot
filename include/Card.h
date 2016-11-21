#ifndef CARD_H_
#define CARD_H_

#include <iostream>
#include <string>

using namespace std;

enum class Shape {
	Club,
	Diamond,vdvds
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
  void setShape(Shape shape);
  virtual string toString() = 0; //Returns the string representation of the card "<value><shape>" exp: "12S" or "QD"
  virtual ~Card();
};

class FigureCard : public Card {
private:
	Figure figure;
public:
	FigureCard(char figu , char shap);
	Figure getFigure();
	void setFigure(Figure figure);
	virtual string toString() override;
};

class NumericCard : public Card {
private:
	int number;
public:
	NumericCard(int num, char shap);
	int getNumber();
	void setNumber(int num);
	virtual string toString() override;
};

#endif
