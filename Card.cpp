#ifndef CARD_CPP_
#define CARD_CPP_

#include "../include/Card.h"

#include <iostream>
#include <sstream>
#include <stdio.h>
#include <fstream>
#include <stdlib.h>
#include <string>


using namespace std;



string ShapeName[]=
{
	"C","D","H","S"
};

string FigureName[]=
{
		"J","Q","K","A"
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

FigureCard::FigureCard(Figure figu , Shape shap)
{
	setFigure(figu);
	setShape(shap);
}

string FigureCard::toString()
{
	string s (FigureName[figure] + ShapeName[Card::getShape()]);
	return s;
}

void NumericCard::setNumber(int num)
{
	number = num;
}
NumericCard::NumericCard(int num, Shape shap){
	setNumber(num);
	setShape(shap);
}

std::string NumericCard::toString(){
		stringstream ss;
		ss << number << endl;
		string s = ss.str() + ShapeName[Card::getShape()];

		return s;


	//std::string s (std::to_string(number) + ShapeName[shape]);
	//return s;
}


#endif

