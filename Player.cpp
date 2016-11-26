#include "Player.h"

using namespace std;

Player::Player(string nam) : name(nam) {}

Player::~Player() {}

string Player::getName() {
    return name;
}

int  Player::getThePlayerWithMostCards(vector<Player *> players , int iCurrPlayer){
    int from = 0;

    for (unsigned int i=0; i<players.size()-1; i++){
        for (unsigned int j=1; j<players.size();j++){
            if(players[i]->getNumberOfCards() > players[j]->getNumberOfCards() && players[i] != players[iCurrPlayer] ){
                from = i;
            }
            else if(players[i]->getNumberOfCards() < players[j]->getNumberOfCards() && players[i] != players[iCurrPlayer]){
                from = j;
            }
            else{
                if(i > j && players[i] != players[iCurrPlayer]){
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


PlayerType1::PlayerType1(string nam) : Player(nam) {}

int PlayerType1::getFromWho(const vector<Player *> &players, int iCurrPlayer){
    return getThePlayerWithMostCards(players, iCurrPlayer);
}

Card * PlayerType1::getWhichCardPrefix() {
    return this->getHighestAmount();
}

PlayerType2::PlayerType2(string nam ) : Player(nam) {}


int PlayerType2::getFromWho(const vector<Player *> &players, int iCurrPlayer){

    return getThePlayerWithMostCards(players,iCurrPlayer);
}

Card * PlayerType2::getWhichCardPrefix() {
    return this->getLowestAmount();
}

PlayerType3::PlayerType3(string nam): Player(nam), from(0), numberOfPlayers(0){

}

int PlayerType3::getFromWho(const vector<Player *> &players, int iCurrPlayer){
    if (from==0){
        from = iCurrPlayer;
    }
    from = (int) ((from + 1) % players.size());
    if (from==iCurrPlayer){
        from = (int) ((from + 1) % players.size());
    }
    return from;
}

Card * PlayerType3::getWhichCardPrefix()  {
    return this->getTheHighestValue();
}

PlayerType4::PlayerType4(string nam) : Player(nam), from(0), numberOfPlayers(0) {}


int PlayerType4::getFromWho(const vector<Player *> &players, int iCurrPlayer){
    if (from==0){
        from = iCurrPlayer;
    }
    from = (int) ((from + 1) % players.size());
    if (from==iCurrPlayer){
        from = (int) ((from + 1) % players.size());
    }
    return from;
}

Card * PlayerType4::getWhichCardPrefix() {
    return this->getTheLowestValue();
}

string Player::toString() {
    return name + ": " + Hand::toString();
}