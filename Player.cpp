#include "Player.h"

using namespace std;

Player::Player(string nam) : name(nam) {}

Player::Player(const Player& player):Hand(player),  name(player.getName())  {
}

string Player::getName()const {
    return name;
}

string Player::getName(){
    return name;
}

int  Player::getPlayerWithMostCards(const vector<Player *> &players, int iCurrPlayer){

    int from = 0;
    int maxNumOfCards = 0;

    for (unsigned int i = 0; i < players.size() ; ++i) {
        if (players[i]->getNumberOfCards() > maxNumOfCards && (int)i != iCurrPlayer)
            maxNumOfCards = players[i]->getNumberOfCards();
    }

    for (unsigned int j = 0; j < players.size() ; ++j ) {
        if (players[j]->getNumberOfCards() == maxNumOfCards && (int)j != iCurrPlayer)
            from = j;
    }

    return from;

}

int Player::getNextPlayer(const vector<Player *> &players, int iCurrPlayer, int& from) {
    from = (int) ((from + 1) % players.size());
    if (from == iCurrPlayer){
        from = (int) ((from + 1) % players.size());
    }
    return from;
}

string Player::toString() {
    return name + ": " + Hand::toString();
}

Player::~Player() {}



PlayerType1::PlayerType1(string nam) : Player(nam) {}

PlayerType1::PlayerType1(const PlayerType1 &player) : Player(player) {}

Player *PlayerType1::clone() {
    return new PlayerType1(*this);
}

int PlayerType1::getFromWho(const vector<Player *> &players, int iCurrPlayer){
    return getPlayerWithMostCards(players, iCurrPlayer);
}

string PlayerType1::getWhichCardPrefix() {
    return this->getCardWIthHighestAmount()->getPrefix();
}

PlayerType1::~PlayerType1() {}


PlayerType2::PlayerType2(string nam ) : Player(nam) {}

PlayerType2::PlayerType2(const PlayerType2 &player) : Player(player) {}

Player *PlayerType2::clone() {
    return new PlayerType2(*this);
}

int PlayerType2::getFromWho(const vector<Player *> &players, int iCurrPlayer){

    return getPlayerWithMostCards(players, iCurrPlayer);
}

string PlayerType2::getWhichCardPrefix() {
    return this->getCardWithLowestAmount()->getPrefix();
}

PlayerType2::~PlayerType2() {}


PlayerType3::PlayerType3(string nam): Player(nam), from(-1){}

PlayerType3::PlayerType3(const PlayerType3 &player) : Player(player), from(player.from){}

Player *PlayerType3::clone() {
    return new PlayerType3(*this);
}

int PlayerType3::getFromWho(const vector<Player *> &players, int iCurrPlayer){
    return getNextPlayer(players, iCurrPlayer, from);
}

string PlayerType3::getWhichCardPrefix()  {
    return this->getCardWithHighestValue()->getPrefix();
}
PlayerType3::~PlayerType3() {}



PlayerType4::PlayerType4(string nam) : Player(nam), from(-1){}

PlayerType4::PlayerType4(const PlayerType4 &player) : Player(player), from(player.from) {}

Player *PlayerType4::clone() {
    return new PlayerType4(*this);
}

int PlayerType4::getFromWho(const vector<Player *> &players, int iCurrPlayer){
    return getNextPlayer(players,iCurrPlayer, from);
}

string PlayerType4::getWhichCardPrefix() {
    return this->getCardWithLowestValue()->getPrefix();
}

PlayerType4::~PlayerType4() {}