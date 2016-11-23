#include "Player.h"

using namespace std;

Player::Player(string nam) : name(nam) {}

Player::~Player() {}

string Player::getName() {
    return name;
}

PlayerType1::PlayerType1(string nam) : Player(nam) {}

Player* PlayerType1::getFromWho(vector<Player *> players, int iCurrPlaye){
    return 0;
}

char PlayerType1::getWhichCardPrefix(Player *) {
    return 0;
}

PlayerType2::PlayerType2(string nam) : Player(nam) {}


Player* PlayerType2::getFromWho(vector<Player *> players, int iCurrPlaye){
    return 0;
}

char PlayerType2::getWhichCardPrefix(Player *) {
    return 0;
}

PlayerType3::PlayerType3(string nam):Player(nam), from(0), numberOfPlayers(0){
}

Player* PlayerType3::getFromWho(vector<Player *> players, int iCurrPlaye){
    numberOfPlayers = (int)players.size();
    bool stop= false;
    for (unsigned int i = (unsigned int)from; !stop && i < players.size() ; i++) {
        if (players[i]->getName().compare(players[iCurrPlaye]->getName()) != 0) {
            from = (int)(i % numberOfPlayers);
            stop = true;
        } else {
            i++;
        }
    }

    return players[from];
}

char PlayerType3::getWhichCardPrefix(Player *) {
    return 0;
}

PlayerType4::PlayerType4(string nam) : Player(nam) {}


Player* PlayerType4::getFromWho(vector<Player *> players, int iCurrPlaye){
    return 0;
}

char PlayerType4::getWhichCardPrefix(Player *) {
    return 0;
}

string Player::toString() {
    return name + ": " + Hand::toString();
}