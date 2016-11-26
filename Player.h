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

public:
    Player(string nam);
    Player(const Player& player);
    string getName()const;
    virtual Player * clone()=0;
	//virtual int getFromWho(vector<Player *> players, int iCurrPlayer)=0;
	//string getName();
	virtual int getFromWho(const vector<Player *> &players, int iCurrPlayer)=0;
	virtual Card * getWhichCardPrefix()=0;
    int getThePlayerWithMostCards(vector<Player *> players,int iCurrPlayer);
	virtual ~Player();
	string toString();
};

class PlayerType1 : public Player {
public:
    PlayerType1(const PlayerType1& player);
	PlayerType1(string nam);
    virtual Player * clone() override;

    //virtual int getFromWho(vector<Player *> players, int iCurrPlaye) override;
	virtual int getFromWho(const vector<Player *> &players, int iCurrPlayer) override;
	virtual Card * getWhichCardPrefix() override;
    ~PlayerType1();
};

class PlayerType2 : public Player {
public:
	PlayerType2(string nam);
    PlayerType2(const PlayerType2 &player);
    virtual Player * clone() override;

    //virtual int getFromWho(vector<Player *> players, int iCurrPlaye) override;
	virtual int getFromWho(const vector<Player *> &players, int iCurrPlayer) override;
	virtual Card * getWhichCardPrefix() override;
    ~PlayerType2();
};

class PlayerType3 : public Player {
private:
    int from;
	int numberOfPlayers;
public:
	PlayerType3(string nam);
    PlayerType3(const PlayerType3 &player);
    virtual Player * clone() override;

	//virtual int getFromWho(vector<Player *> players, int iCurrPlaye) override;
	virtual int getFromWho(const vector<Player *> &players, int iCurrPlayer) override;
	virtual Card * getWhichCardPrefix() override;
    ~PlayerType3();
};

class PlayerType4 : public Player {
private:

    int from;
    int numberOfPlayers;
public:
	PlayerType4(string nam);
    PlayerType4(const PlayerType4 &player);
    virtual Player * clone() override;

	//virtual int getFromWho(vector<Player *> players, int iCurrPlaye) override;
	virtual int getFromWho(const vector<Player *> &players, int iCurrPlayer) override;
	virtual Card * getWhichCardPrefix() override;
    ~PlayerType4();

};

#endif