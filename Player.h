#ifndef PLAYER_H_
#define PLAYER_H_

#include "Hand.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Player : public Hand {
private:
    const string name;

protected:
    Player(string nam);

public:
	string getName();
	virtual Player* getFromWho(vector<Player *> players, int iCurrPlayer)=0;
	virtual char getWhichCardPrefix(Player *)=0;
	virtual ~Player();
	string toString();
};

class PlayerType1 : public Player {  //For strategy 1
//...
public:

	PlayerType1(string nam);
	virtual Player* getFromWho(vector<Player *> players, int iCurrPlaye) override;
	virtual char getWhichCardPrefix(Player *) override;
};

class PlayerType2 : public Player {  //For strategy 2
//...
public:
	PlayerType2(string nam);
	virtual Player* getFromWho(vector<Player *> players, int iCurrPlaye) override;
	virtual char getWhichCardPrefix(Player *) override;
};

class PlayerType3 : public Player {  //For strategy 3
//...
private:
	int from;
	int numberOfPlayers;
public:
	PlayerType3(string nam);
	virtual Player* getFromWho(vector<Player *> players, int iCurrPlaye) override;
	virtual char getWhichCardPrefix(Player *) override;
};

class PlayerType4 : public Player {  //For strategy 4
//...
public:
	PlayerType4(string nam);
	virtual Player* getFromWho(vector<Player *> players, int iCurrPlaye) override;
	virtual char getWhichCardPrefix(Player *) override;
};

#endif