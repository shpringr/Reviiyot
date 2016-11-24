#include "Player.h"

using namespace std;

Player::Player(string nam, int position) : name(nam), position(position) {}

Player::~Player() {}

string Player::getName() {
    return name;
}

int  Player::getThePlayerWithMostCards(vector<Player *> players){
    int from;
    for (unsigned int i=0; i<players.size()-1; i++){
        for (unsigned int j=1; j<players.size();j++){
            if(players[i]->getNumberOfCards() > players[j]->getNumberOfCards()){
                from = i;
            }
            else if(players[i]->getNumberOfCards() < players[j]->getNumberOfCards()){
                from = j;
            }
            else{
                if(players[i]->position > players[j]->position){
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
    return getThePlayerWithMostCards(players);
}

Card * PlayerType1::getWhichCardPrefix(Player * player) {
    return 0;
}

PlayerType2::PlayerType2(string nam , int position) : Player(nam, position) {}


int PlayerType2::getFromWho(vector<Player *> players, int iCurrPlaye){
    return getThePlayerWithMostCards(players);
}

Card * PlayerType2::getWhichCardPrefix(Player * player) {
    return 0;
}

PlayerType3::PlayerType3(string nam, int position): Player(nam, position), from(0), numberOfPlayers(0){

}

int PlayerType3::getFromWho(vector<Player *> players, int iCurrPlaye){
    from = (int)((iCurrPlaye+1) % players.size());
    return from;
}

Card * PlayerType3::getWhichCardPrefix(Player * player)  {
    return player->getTheHighestValue();
}

PlayerType4::PlayerType4(string nam, int position) : Player(nam, position), from(0), numberOfPlayers(0) {}


int PlayerType4::getFromWho(vector<Player *> players, int iCurrPlaye){
    from = (int)((iCurrPlaye+1) % players.size());
    return from;
}

Card * PlayerType4::getWhichCardPrefix(Player * player) {
    return player->getTheLowestValue();
}

string Player::toString() {
    return name + ": " + Hand::toString();
}