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
    int position;
    Player(string nam, int position);

public:
	string getName();
	virtual int getFromWho(vector<Player *> players, int iCurrPlayer)=0;
	virtual Card * getWhichCardPrefix()=0;
    virtual int getThePlayerWithMostCards(vector<Player *> players,int iCurrPlaye);
	virtual ~Player();
	string toString();
};

class PlayerType1 : public Player {  //For strategy 1
//...
public:

	PlayerType1(string nam, int position);
	virtual int getFromWho(vector<Player *> players, int iCurrPlaye) override;
	virtual Card * getWhichCardPrefix() override;
};

class PlayerType2 : public Player {  //For strategy 2
//...
public:
	PlayerType2(string nam, int position);
	virtual int getFromWho(vector<Player *> players, int iCurrPlaye) override;
	virtual Card * getWhichCardPrefix() override;
};

class PlayerType3 : public Player {  //For strategy 3
//...
private:
	int from;
	int numberOfPlayers;
public:
	PlayerType3(string nam, int position);
	virtual int getFromWho(vector<Player *> players, int iCurrPlaye) override;
	virtual Card * getWhichCardPrefix() override;
};

class PlayerType4 : public Player {  //For strategy 4
//...
private:
    int from;
    int numberOfPlayers;
public:
	PlayerType4(string nam, int position);
	virtual int getFromWho(vector<Player *> players, int iCurrPlaye) override;
	virtual Card * getWhichCardPrefix() override;
};

#endif