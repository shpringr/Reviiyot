#ifndef PLAYER_H_
#define PLAYER_H_

#include <iostream>
#include <string>
#include "Hand.h"


using namespace std;

class Player : public Hand {
private:
	const string name;
protected:
	Player(string nam);
public:
	string getName();//Returns the name of the player
	string toString();

};

class PlayerType1 : public Player {  //For strategy 1
//...
public:
	PlayerType1(string nam);
};

class PlayerType2 : public Player {  //For strategy 2
//...
public:
	PlayerType2(string nam);
};

class PlayerType3 : public Player {  //For strategy 3
//...
public:
	PlayerType3(string nam);
};

class PlayerType4 : public Player {  //For strategy 4
//...
public:
	PlayerType4(string nam);
};

#endif
