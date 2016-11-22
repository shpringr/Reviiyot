#include "Player.h"

#include <iostream>
#include <string>
#include <vector>

using namespace std;

Player::Player(string nam) :name(nam){}

Player::~Player(){}

//void Player::setName(string nam) {name=nam;}

PlayerType1::PlayerType1(string nam): Player(nam){}

Player* PlayerType1::getFromWho(vector<Player *> players){
    return 0;
}

char PlayerType1::getWhichCardPrefix(Player *) {
    return 0;
}

PlayerType2::PlayerType2(string nam):Player(nam){}


Player* PlayerType2::getFromWho(vector<Player *> players){
    return 0;
}

char PlayerType2::getWhichCardPrefix(Player *) {
    return 0;
}

PlayerType3::PlayerType3(string nam):Player(nam){}


Player* PlayerType3::getFromWho(vector<Player *> players){
    return 0;
}

char PlayerType3::getWhichCardPrefix(Player *) {
    return 0;
}

PlayerType4::PlayerType4(string nam):Player(nam){}


Player* PlayerType4::getFromWho(vector<Player *> players){
    return 0;
}

char PlayerType4::getWhichCardPrefix(Player *) {
    return 0;
}


string Player::toString()
{
    return name + ": " + Hand::toString();
}