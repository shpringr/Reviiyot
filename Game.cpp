#include <cstdlib>
#include <sstream>
#include <iostream>

#include "Deck.h"
#include "Player.h"
#include "Game.h"

using namespace std;

//vector<Player *> players;
//Deck deck;
//bool isVerbalOn;
//int N;



Game::Game(char *configurationFile): players(), deck(), isVerbalOn(), N(){
    //dummyConfig1();
    readConfigFile(configurationFile);
}

Game::Game(const Game& game) {
//    vector<Player *> *  players = new vector<Player *>
}


Card* Game::getThehighestValue(){
    return players[0]->getTheHighestValue();
}

int Game::gettheplayerwithmostcards(){
    return players[0]->getThePlayerWithMostCards(players,0);
}

Card * Game::getMost(){
    return players[1]->getHighestAmount();
}

Card * Game::getLoest(){
    return players[1]->getLowestAmount();
}


void Game::readConfigFile(char *configurationFile) {

    ifstream source;
    source.open("config1.txt");
    vector<string> lines;
    string line;

    if (source.is_open()) {

        ignoreInsignificantLines(source, line);

        isVerbalOn = line == "1";

        ignoreInsignificantLines(source, line);

        N = atoi(line.c_str());

        ignoreInsignificantLines(source, line);

        string currCard;
        istringstream iss(line);

        while ( getline( iss, currCard, ' ' ) ) {

            char shape = currCard.back();
            string prefix;
            prefix = currCard.substr(0, currCard.size() - 1);
            addCardToDeck(shape, prefix);
        }

        ignoreInsignificantLines(source, line);

        string currPlayerName;
        string currType;
        istringstream iss1(line);

        while ( getline( iss1, currPlayerName, ' ' ) ) {

            getline( iss1, currType, ' ');
            addPlayer(currPlayerName, atoi(currType.c_str()));

            ignoreInsignificantLines(source, line);
        }

        source.close();
        deck.toString();

    } else{
        cout << "couldn't open file!" << endl;
    }
}

void Game::ignoreInsignificantLines(ifstream &source, string &line)
{
    getline(source, line);

    while (line.empty() || line.front() ==  '#') {
        getline(source, line);
    }
}


void Game::addCardToDeck(char shape, string prefix) {

    bool isDigit = isdigit(prefix[0]);

    if (isDigit) {
        int numericPrefix = atoi(prefix.c_str());
        deck.getCards().push_back(new NumericCard(numericPrefix, shape));
    }
    else
        deck.getCards().push_back(new FigureCard(prefix[0], shape));
}


void Game::addPlayer(string name, int type) {

    Player* playerToAdd;
//    switch(type) {
//        case 1 :
//            playerToAdd = new PlayerType1(name);
//            break;
//        case 2 :
//            playerToAdd = new PlayerType2(name);
//            break;
//        case 3 :
//            playerToAdd = new PlayerType3(name);
//            break;
//        case 4 :
//            playerToAdd = new PlayerType4(name);
//            break;
//        default :
//            cout << "Invalid Player type" << endl;
//
//        players.push_back(playerToAdd);
}

void Game::init() {

    for (unsigned int i = 0; i < players.size(); ++i) {

        for (int j = 0; j < 7 && deck.getCards().size() > 0; ++j) {
            Card *currCard = deck.fetchCard();
            Player *currPlayer = players[i];

            addCardAndDiscardIfNeeded(currPlayer, currCard);
        }
    }
}

void Game::play() {

    int currPlayerIndex = 0;

    while (!isThereAWinner()) {

        increaseNumberOfTurns();

        Player *askingPlayer = players[currPlayerIndex];
        Player *askedPlayer = players[askingPlayer->getFromWho(players,currPlayerIndex)]; //meanwhile till we have getFromWho()
        //Player askedPlayer = askingPlayer.getFromWho(vector(copy));
        Card *cardToAsk = askingPlayer->getWhichCardPrefix(); //meanwhile till we have getCardToAsk()
        //Card *cardToAsk = askingPlayer.getCardToAsk(askedPlayer.getCards());

        if (isVerbalOn)
            printATurn(askingPlayer, askedPlayer, cardToAsk);

        vector<Card *> cardsOfSamePref = askedPlayer->searchCardsWithSamePref(cardToAsk);

        if (cardsOfSamePref.size() == 0 && deck.getNumberOfCards() > 0)
            addCardAndDiscardIfNeeded(askingPlayer, deck.fetchCard());
        else
        {
            for (Card *cardToMove : cardsOfSamePref)
            {
                askedPlayer->removeCard(*cardToMove);
                addCardAndDiscardIfNeeded(askingPlayer, cardToMove);
            }

            if (askedPlayer->getNumberOfCards() > 0)
            {
                for (unsigned int i = 0; i < cardsOfSamePref.size() && deck.getNumberOfCards() > 0; ++i)
                {
                    addCardAndDiscardIfNeeded(askedPlayer, deck.fetchCard());
                }
            }
        }

        currPlayerIndex = (currPlayerIndex + 1) % players.size();
    }
}

void Game::printATurn(Player *askingPlayer, Player *askedPlayer, Card *cardToAsk) {
    cout << "Turn " << numberOfTurns << endl;
    printState();
    cout << askingPlayer->getName() + " asked " + askedPlayer->getName()
            + " for the value " + cardToAsk->getPrefix() << endl << endl;
}

void Game::addCardAndDiscardIfNeeded(Player *player, Card *card) {
    player->addCard(*card);
    if (player->getNumberOfSamePrefix(card) == 4)
        player->discardSet(card);
}

//This function prints the cards remaining in
//the deck from top to bottom in a single line,
//followed by the name and sorted hand of all players (a single line per player).
//***This function should be implemented with extra care because yonatan said.***
//
void Game::printState() {
//    cout << "the hiest value: " <<  getThehighestValue()->toString() << endl;
//    cout << "gettheplayerwithmostcards: " << gettheplayerwithmostcards() << endl;
//    cout << "getThemost " << getMost()->toString() << endl;
//    cout << "getL " << getLoest()->toString() << endl;
    cout << "Deck: " << deck.toString() << endl;
    for (unsigned int i = 0; i < players.size(); ++i) {
        cout << players[i]->toString() << endl;
    }

}
// or winners
void Game::printWinner() {
    vector<Player*> winners = getWinners();

    if (winners.size() > 1)
        cout << "***** The winners are: ";
     else
        cout << "***** The Winner is: ";

    for (unsigned int i = 0; i < winners.size(); ++i) {
        if (i>0)
            cout << "and ";
        cout << winners[i]->getName() + " ";
    }

    cout <<  "*****" << endl;
}

void Game::printNumberOfTurns() {
    cout << "NumberOfTurns: " << numberOfTurns << endl;
}

void Game::increaseNumberOfTurns() {
    numberOfTurns++;
}

bool Game::isThereAWinner() {
    return getWinners().size() > 0;
}

vector<Player*> Game::getWinners()
{
    vector<Player*> winners;
    for (Player *player : players) {
            if (player->getNumberOfCards() == 0)
                winners.push_back(player);
        }

        return winners;
}