#ifndef PLAYER_H_
#define PLAYER_H_

#include <iostream>
#include <string>
#include <vector>
#include "Hand.h"


using namespace std;

class Player : public Hand {
private:
    const string name;

protected:
    Player(string nam);

public:
    string getName();//Returns the name of the player
    virtual Player *getFromWho(vector<Player *> players)=0;

    virtual char getWhichCardPrefix(Player *)=0;

    virtual ~Player();

    string toString();
};

class PlayerType1 : public Player {  //For strategy 1
//...
public:

    PlayerType1(string nam);

    virtual Player *getFromWho(vector<Player *> players) override;

    virtual char getWhichCardPrefix(Player *) override;
};

class PlayerType2 : public Player {  //For strategy 2
//...
public:
    PlayerType2(string nam);

    virtual Player *getFromWho(vector<Player *> players) override;

    virtual char getWhichCardPrefix(Player *) override;
};

class PlayerType3 : public Player {  //For strategy 3
//...
public:
    PlayerType3(string nam);

    virtual Player *getFromWho(vector<Player *> players) override;

    virtual char getWhichCardPrefix(Player *) override;
};

class PlayerType4 : public Player {  //For strategy 4
//...
public:
    PlayerType4(string nam);

    virtual Player *getFromWho(vector<Player *> players) override;

    virtual char getWhichCardPrefix(Player *) override;
};

#endif
