#include "Player.h"
#include <iostream>

using namespace std;

Player::Player(string nam) :name(nam){}
//void Player::setName(string nam) {name=nam;}
PlayerType1::PlayerType1(string nam): Player(nam){

}

PlayerType2::PlayerType2(string nam):Player(nam){

}

PlayerType3::PlayerType3(string nam):Player(nam){

}

PlayerType4::PlayerType4(string nam):Player(nam){

}

string Player::toString()
{
    return name + ": " + Hand::toString();
}