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
	virtual int getFromWho(const vector<Player *> &players, int iCurrPlayer)=0;
	virtual Card * getWhichCardPrefix()=0;
    int getThePlayerWithMostCards(vector<Player *> players,int iCurrPlayer);
	virtual ~Player();
	string toString();
};

class PlayerType1 : public Player {
public:

	PlayerType1(string nam);
	virtual int getFromWho(const vector<Player *> &players, int iCurrPlayer) override;
	virtual Card * getWhichCardPrefix() override;
};

class PlayerType2 : public Player {
public:
	PlayerType2(string nam);
	virtual int getFromWho(const vector<Player *> &players, int iCurrPlayer) override;
	virtual Card * getWhichCardPrefix() override;
};

class PlayerType3 : public Player {
private:
	int from;
	int numberOfPlayers;
public:
	PlayerType3(string nam);
	virtual int getFromWho(const vector<Player *> &players, int iCurrPlayer) override;
	virtual Card * getWhichCardPrefix() override;
};

class PlayerType4 : public Player {
private:
    int from;
    int numberOfPlayers;
public:
	PlayerType4(string nam);
	virtual int getFromWho(const vector<Player *> &players, int iCurrPlayer) override;
	virtual Card * getWhichCardPrefix() override;
};

#endif