#include <cstdlib>
#include <sstream>
#include <iostream>

#include "Deck.h"
#include "Player.h"
#include "Game.h"

using namespace std;

Game::Game(char *configurationFile): players(), deck(), isVerbalOn(), N(){
    //dummyConfig1();
    //readConfigFile(configurationFile);
    readConfigFile(configurationFile);
}

/*

*/
/**
 * deep copy of this list (allocates links)
*//*

vector<Player *> * Game::copyPlayers() const
{

    Player *playerToAdd;
    vector<Player *> *  playersNew = new vector<Player *>;

    for (unsigned  int i = 0; i < players.size() ; ++i) {
            playerToAdd = new Player(players[i]);
            playersNew->push_back(playerToAdd);
    }
    return playersNew;
Game::Game(const Game& game): players(), deck(), isVerbalOn(), N() {
}

Deck * Game::copyDeck() const {

    Deck * ref = new Deck();
    unsigned int size = (unsigned int) (deck.getCards().size());
    for (unsigned int i = 0; i < size; ++i) {
        ref->addCardToCopyDeck(this->deck.getCards()[i]->getShapeChar(), this->deck.getCards()[i]->getPrefix());
    }
    return ref;
}



*/
/**
 * Copy Constructor:deep copy of aList
 */

/*

Game::Game(const Game& game):
    players()
{
    players = *game.copyPlayers();
    deck = *game.copyDeck();
    isVerbalOn =  game.isVerbalOn;
    N = game.N;
}

*/


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

void Game::dummyConfig1()
{
    isVerbalOn = true;
    N = 3;

    deck.getCards().push_back(new FigureCard('K', 'C'));
    deck.getCards().push_back(new FigureCard('Q', 'H'));
    deck.getCards().push_back(new NumericCard(3, 'D'));
    deck.getCards().push_back(new FigureCard('A', 'H'));
    deck.getCards().push_back(new FigureCard('J', 'H'));
    deck.getCards().push_back(new NumericCard(2, 'C'));
    deck.getCards().push_back(new NumericCard(3, 'S'));
    deck.getCards().push_back(new FigureCard('K', 'S'));
    deck.getCards().push_back(new FigureCard('A', 'S'));
    deck.getCards().push_back(new FigureCard('J', 'S'));
    deck.getCards().push_back(new NumericCard(3, 'C'));
    deck.getCards().push_back(new FigureCard('K', 'H'));
    deck.getCards().push_back(new FigureCard('A', 'D'));
    deck.getCards().push_back(new FigureCard('Q', 'C'));
    deck.getCards().push_back(new FigureCard('J', 'D'));
    deck.getCards().push_back(new FigureCard('Q', 'S'));
    deck.getCards().push_back(new NumericCard(3, 'H'));
    deck.getCards().push_back(new FigureCard('K', 'D'));
    deck.getCards().push_back(new FigureCard('A', 'C'));
    deck.getCards().push_back(new FigureCard('J', 'C'));
    deck.getCards().push_back(new NumericCard(2, 'D'));
    deck.getCards().push_back(new NumericCard(2, 'H'));
    deck.getCards().push_back(new NumericCard(2, 'S'));
    deck.getCards().push_back(new FigureCard('Q', 'D'));

    players.push_back(new PlayerType1("Alice"));
    players.push_back(new PlayerType2("Bob"));
    players.push_back(new PlayerType3("Charlie"));
    // players.push_back(new PlayerType3("Hey",4));
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

        currPlayerIndex = (currPlayerIndex + 1) % players.size();
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