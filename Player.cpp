#include "Player.h"
#include <iostream>

using namespace std;

//void Player::setName(string nam) {name=nam;}
PlayerType1::PlayerType1(string nam){

}

PlayerType2::PlayerType2(string nam){

}

PlayerType3::PlayerType3(string nam){

}

PlayerType4::PlayerType4(string nam){

}

string Player::toString()
{
    return name + Hand::toString();
}