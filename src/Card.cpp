#ifndef CARD_CPP_
#define CARD_CPP_

#include "../include/Card.h"

#include <iostream>
#include <sstream>
#include <stdio.h>
#include <fstream>
#include <stdlib.h>
#include <string>
#include <map>

using namespace std;


map<char, Shape> shapeSymbolsToNames =  {
		   {'C', Shape::Club},
		   {'D', Shape::Diamond},
		   {'H', Shape::Heart},
		   {'S', Shape::Spade}
		};


map<char, Figure> figureSymbolsToNames =  {
		   {'J', Figure::Jack},
		   {'Q', Figure::Queen},
		   {'K', Figure::King},
		   {'A', Figure::Ace}
		};


map<Shape, char> shapeNamesToSymbols =  {
		   {Shape::Club, 'C'},
		   {Shape::Diamond, 'D'},
		   {Shape::Heart, 'H'},
		   {Shape::Spade, 'S'}
		};


map<Figure, char> figureNamesToSymbols =  {
		   {Figure::Jack, 'J'},
		   {Figure::Queen, 'Q'},
		   {Figure::King, 'K'},
		   {Figure::Ace, 'A'}
		};


Card::~Card(){}

Shape Card::getShape(){
	return shape;
}

void Card::setShape(Shape shap){
	shape=shap;
}

void FigureCard::setFigure(Figure figu)
{
	figure = figu;
}

Figure FigureCard::getFigure()
{
	return figure;
}


FigureCard::FigureCard(char figu , char shap)
{
	setFigure(figureSymbolsToNames[figu]);
	setShape(shapeSymbolsToNames[shap]);
}

string FigureCard::toString()
	 {
	stringstream ss;

	ss << figureNamesToSymbols[getFigure()];
	ss << shapeNamesToSymbols[getShape()];
	return ss.str();

	 }


void NumericCard::setNumber(int num)
{
	number = num;
}

int NumericCard::getNumber()
{
	return number;
}

NumericCard::NumericCard(int num, char shap){
	setNumber(num);
	setShape(shapeSymbolsToNames[shap]);
}

string NumericCard::toString(){
		stringstream ss;
		ss << getNumber();
		ss << shapeNamesToSymbols[getShape()];

		return ss.str();

}

#endif

