#include "Player.h"

using namespace std;

Player::Player(string nam, int position) : name(nam), position(position) {}

Player::~Player() {}

string Player::getName() {
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
                if(players[i]->position > players[j]->position && players[i] != players[iCurrPlaye]){
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


PlayerType1::PlayerType1(string nam , int position) : Player(nam, position) {}

int PlayerType1::getFromWho(vector<Player *> players, int iCurrPlaye){
    return getThePlayerWithMostCards(players, iCurrPlaye);
}

Card * PlayerType1::getWhichCardPrefix() {
    return this->getHighestAmount();
}

PlayerType2::PlayerType2(string nam , int position) : Player(nam, position) {}


int PlayerType2::getFromWho(vector<Player *> players, int iCurrPlaye){

    return getThePlayerWithMostCards(players,iCurrPlaye);
}

Card * PlayerType2::getWhichCardPrefix() {
    return this->getLowestAmount();
}

PlayerType3::PlayerType3(string nam, int position): Player(nam, position), from(position-1), numberOfPlayers(0){

}

int PlayerType3::getFromWho(vector<Player *> players, int iCurrPlaye){
    from = (int) ((from + 1) % players.size());
    if (from==iCurrPlaye){
        from = (int) ((from + 1) % players.size());
    }
    return from;
}

Card * PlayerType3::getWhichCardPrefix()  {
    return this->getTheHighestValue();
}

PlayerType4::PlayerType4(string nam, int position) : Player(nam, position), from(position-1), numberOfPlayers(0) {}


int PlayerType4::getFromWho(vector<Player *> players, int iCurrPlaye){
    from = (int) ((from + 1) % players.size());
    if (from==iCurrPlaye){
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