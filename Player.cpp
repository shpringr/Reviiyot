#include "Player.h"

using namespace std;

Player::Player(string nam) : name(nam) {}

Player::Player(const Player& player): name(player.getName()) {}

string Player::getName()const {
    return name;
}

int  Player::getThePlayerWithMostCards(vector<Player *> players , int iCurrPlaye){
    int from;

    for (unsigned int i=0; i<players.size()-1; i++){
        for (unsigned int j=1; j<players.size();j++){
            if(players[i]->getNumberOfCards() > players[j]->getNumberOfCards() && players[i] != players[iCurrPlaye] ){
                from = i;
            }
            else if(players[i]->getNumberOfCards() < players[j]->getNumberOfCards() && players[i] != players[iCurrPlaye]){
                from = j;
            }
            else{
                if(i > j && players[i] != players[iCurrPlaye]){
                    from = i;
                }
                else{
                    from = j;
                }
            }
        }
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

int PlayerType1::getFromWho(vector<Player *> players, int iCurrPlaye){
    return getThePlayerWithMostCards(players, iCurrPlaye);
}

Card * PlayerType1::getWhichCardPrefix() {
    return this->getHighestAmount();
}

PlayerType1::~PlayerType1() {}


PlayerType2::PlayerType2(string nam ) : Player(nam) {}

PlayerType2::PlayerType2(const PlayerType2 &player) : Player(player) {}

Player *PlayerType2::clone() {
    return new PlayerType2(*this);
}

int PlayerType2::getFromWho(vector<Player *> players, int iCurrPlaye){
    return getThePlayerWithMostCards(players,iCurrPlaye);
}

Card * PlayerType2::getWhichCardPrefix() {
    return this->getLowestAmount();
}

PlayerType2::~PlayerType2() {}


PlayerType3::PlayerType3(string nam): Player(nam), from(0), numberOfPlayers(0){}

PlayerType3::PlayerType3(const PlayerType3 &player) : Player(player) {}

Player *PlayerType3::clone() {
    return new PlayerType3(*this);
}

int PlayerType3::getFromWho(vector<Player *> players, int iCurrPlaye){
    if (from==0){
        from = iCurrPlaye;
    }
    from = (int) ((from + 1) % players.size());
    if (from==iCurrPlaye){
        from = (int) ((from + 1) % players.size());
    }
    return from;
}

Card * PlayerType3::getWhichCardPrefix()  {
    return this->getTheHighestValue();
}
PlayerType3::~PlayerType3() {}



PlayerType4::PlayerType4(string nam) : Player(nam), from(0), numberOfPlayers(0) {}

PlayerType4::PlayerType4(const PlayerType4 &player) : Player(player) {}

Player *PlayerType4::clone() {
    return new PlayerType4(*this);
}

int PlayerType4::getFromWho(vector<Player *> players, int iCurrPlaye){
    if (from==0){
        from = iCurrPlaye;
    }
    from = (int) ((from + 1) % players.size());
    if (from==iCurrPlaye){
        from = (int) ((from + 1) % players.size());
    }
    return from;
}

Card * PlayerType4::getWhichCardPrefix() {
    return this->getTheLowestValue();
}

PlayerType4::~PlayerType4() {}
