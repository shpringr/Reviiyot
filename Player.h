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
    Player(const Player& player);


public:
	string getName()const;
    virtual Player * clone()=0;
	virtual int getFromWho(vector<Player *> players, int iCurrPlayer)=0;
	virtual Card * getWhichCardPrefix()=0;
    virtual int getThePlayerWithMostCards(vector<Player *> players,int iCurrPlaye);
	virtual ~Player();
	string toString();
   // virtual Player(const Player& player)=0;

};

class PlayerType1 : public Player {  //For strategy 1
//...
public:
    PlayerType1(const PlayerType1& player);
	PlayerType1(string nam);
    virtual Player * clone() override;

    virtual int getFromWho(vector<Player *> players, int iCurrPlaye) override;
	virtual Card * getWhichCardPrefix() override;
    ~PlayerType1();
};

class PlayerType2 : public Player {  //For strategy 2
//...
public:
	PlayerType2(string nam);
    PlayerType2(const PlayerType2 &player);
    virtual Player * clone() override;
    
    virtual int getFromWho(vector<Player *> players, int iCurrPlaye) override;
	virtual Card * getWhichCardPrefix() override;
    ~PlayerType2();
};

class PlayerType3 : public Player {  //For strategy 3
//...
private:
    int from;
	int numberOfPlayers;
public:
	PlayerType3(string nam);
    PlayerType3(const PlayerType3 &player);
    virtual Player * clone() override;
    
	virtual int getFromWho(vector<Player *> players, int iCurrPlaye) override;
	virtual Card * getWhichCardPrefix() override;
    ~PlayerType3();
};

class PlayerType4 : public Player {  //For strategy 4
//...
private:

    int from;
    int numberOfPlayers;
public:
	PlayerType4(string nam);
    PlayerType4(const PlayerType4 &player);
    virtual Player * clone() override;
    
	virtual int getFromWho(vector<Player *> players, int iCurrPlaye) override;
	virtual Card * getWhichCardPrefix() override;
    ~PlayerType4();

};

#endif