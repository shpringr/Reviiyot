#include <cstdlib>
#include <sstream>
#include <iostream>

#include "Deck.h"
#include "Player.h"
#include "Game.h"

using namespace std;

Game::Game(char *configurationFile): players(), deck(), isVerbalOn(), N(){
    readConfigFile(configurationFile);
}

vector<Player *> Game::copyPlayers() const {

    vector<Player *> playersNew;

    for (unsigned int i = 0; i < players.size(); ++i) {
        playersNew.push_back(players[i]->clone());
    }
    return playersNew;
}

Game::Game(const Game& game):
        players(game.copyPlayers()), deck(game.deck), isVerbalOn(game.isVerbalOn), N(game.N)
{
}

void Game::readConfigFile(char *configurationFile) {

    ifstream source;
    source.open(configurationFile);
    string line;

    if (source.is_open()) {

        ignoreInsignificantLines(source, line);

        isVerbalOn = line == "1";

        ignoreInsignificantLines(source, line);

        N = atoi(line.c_str());

        ignoreInsignificantLines(source, line);

        string currCard;
        istringstream iss(line);

        while (getline(iss, currCard, ' ')) {

            char shape = currCard.back();
            string prefix;
            prefix = currCard.substr(0, currCard.size() - 1);
            addCardToDeck(shape, prefix);

        }

        string currPlayerName;
        string currType;

        while (!source.eof())
        {
            ignoreInsignificantLines(source, line);

            if (!isLineInsignificant(line))
            {
                iss.str(line);
                iss.clear();
                getline(iss, currPlayerName, ' ');
                getline(iss, currType, ' ');
                addPlayer(currPlayerName, atoi(currType.c_str()));
            }
        }

        source.close();
    } else{
        cout << "couldn't open file!" << endl;
    }
}

void Game::ignoreInsignificantLines(ifstream &source, string &line)
{
    getline(source, line);

    while (isLineInsignificant(line) && !source.eof()) {
        getline(source, line);
    }
}

bool Game::isLineInsignificant(string &line)
{
    return line.empty() || line.front() ==  '#';
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

    Player *playerToAdd = nullptr;
    switch (type) {
        case 1 :
            playerToAdd = new PlayerType1(name);
            break;
        case 2 :
            playerToAdd = new PlayerType2(name);
            break;
        case 3 :
            playerToAdd = new PlayerType3(name);
            break;
        case 4 :
            playerToAdd = new PlayerType4(name);
            break;
        default :
            cout << "Invalid Player type" << endl;
            break;
    }

            players.push_back(playerToAdd);

}

void Game::init() {

    for (unsigned int i = 0; i < players.size(); ++i) {

        for (int j = 0; j < 7 && deck.getCards().size() > 0; ++j) {
            Card *currCard = deck.fetchCard();
            Player *currPlayer = players[i];

            addCardAndDiscardIfNeeded(*currPlayer, *currCard);
        }
    }
}

void Game::play() {

    int currPlayerIndex = 0;

    while (!isThereAWinner()) {

        increaseNumberOfTurns();

        Player *askingPlayer = players[currPlayerIndex];
        Player *askedPlayer = players[askingPlayer->getFromWho(players,currPlayerIndex)];
        Card *cardToAsk = askingPlayer->getWhichCardPrefix();

        if (isVerbalOn)
            printATurn(*askingPlayer, *askedPlayer, *cardToAsk);

        vector<Card *> cardsOfSamePref = askedPlayer->searchCardsWithSamePrefix(*cardToAsk);

        if (cardsOfSamePref.size() == 0 && deck.getNumberOfCards() > 0)
            addCardAndDiscardIfNeeded(*askingPlayer, *deck.fetchCard());
        else
        {
            for (Card *cardToMove : cardsOfSamePref)
            {
                askedPlayer->removeCard(*cardToMove);
                addCardAndDiscardIfNeeded(*askingPlayer, *cardToMove);
            }

            if (askedPlayer->getNumberOfCards() > 0)
            {
                for (unsigned int i = 0; i < cardsOfSamePref.size() && deck.getNumberOfCards() > 0; ++i)
                {
                    addCardAndDiscardIfNeeded(*askedPlayer, *deck.fetchCard());
                }
            }
        }

        currPlayerIndex = (currPlayerIndex + 1) % (int) players.size();
    }
}

void Game::printATurn(Player& askingPlayer, Player& askedPlayer, Card& cardToAsk) {
    cout << "Turn " << numberOfTurns << endl;
    printState();
    cout << askingPlayer.getName() + " asked " + askedPlayer.getName()
            + " for the value " + cardToAsk.getPrefix() << endl << endl;
}

void Game::addCardAndDiscardIfNeeded(Player& player, Card& card) {
    player.addCard(card);
    if (player.getNumberOfSamePrefix(card) == 4)
        player.discardSet(&card);
}

void Game::printState() {
    cout << "Deck: " << deck.toString() << endl;

    for (unsigned int i = 0; i < players.size(); ++i)
        cout << players[i]->toString() << endl;
}

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

void Game::clearPlayers() {
    for (unsigned int i = 0; i < players.size(); ++i) {
        delete (players[i]);
    }
}

Game::~Game() {
    clearPlayers();
}
