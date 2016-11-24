#include "Deck.h"
#include "Player.h"
#include "Game.h"

using namespace std;


Game::Game(char *configurationFile): players(), deck(), isVerbalOn(), N(){
    dummyConfig1();
    //readConfigFile(configurationFile);
}
Game::Game(const Game& game): players(game.players), deck(game.deck), isVerbalOn(game.isVerbalOn), N(game.N){}

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

    players.push_back(new PlayerType1("Alice",1));
    players.push_back(new PlayerType2("Bob",2));
    players.push_back(new PlayerType3("Charlie",3));
   // players.push_back(new PlayerType3("Hey",4));
}

void Game::dummyConfig2() {

}

void Game::dummyConfig3() {

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


void Game::readConfigFile(char *configurationFile) {}

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
  //  cout << "gettheplayerwithmostcards: " << gettheplayerwithmostcards() << endl;
    cout << "getThemost " << getMost()->toString() << endl;
    cout << "getL " << getLoest()->toString() << endl;
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