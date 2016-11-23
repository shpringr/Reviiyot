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

    players.push_back(new PlayerType1("Alice"));
    players.push_back(new PlayerType2("Bob"));
    players.push_back(new PlayerType3("Charlie"));
}

void Game::dummyConfig2() {

}

void Game::dummyConfig3() {

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
    int currPlayer = 0;

    while (!isThereAWinner()) {

        increaseNumberOfTurns();

        Player *askingPlayer = players[currPlayer];
        Player *askedPlayer = players[(currPlayer + 1) % players.size()]; //meanwhile till we have getFromWho()
        //Player askedPlayer = askingPlayer.getFromWho(vector(copy));
        Card *cardToAsk = askingPlayer->getFirstCard(); //meanwhile till we have getCardToAsk()
        //Card *cardToAsk = askingPlayer.getCardToAsk(askedPlayer.getCards());

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

        if (isVerbalOn) {

            cout << "asking " + askingPlayer->getName() << endl;
            cout << "asked " + askedPlayer->getName() << endl;
            cout << "card " << cardToAsk->toString() << endl;
            printNumberOfTurns();
            printState();
        }

        currPlayer = (currPlayer + 1) % players.size();
    }
}

void Game::addCardAndDiscardIfNeeded(Player *player, Card *card) {
    player->addCard(*card);
    if (player->getNumberOfSamePref(card) == 4)
        player->discardSet(card);
}

//This function prints the cards remaining in
//the deck from top to bottom in a single line,
//followed by the name and sorted hand of all players (a single line per player).
//***This function should be implemented with extra care because yonatan said.***
//
void Game::printState() {

    cout << deck.toString() << endl;
    for (unsigned int i = 0; i < players.size(); ++i) {
        cout << players[i]->toString() << endl;
    }

}
// or winners
void Game::printWinner() {}

void Game::printNumberOfTurns() {}

void Game::increaseNumberOfTurns() {
    numberOfTurns++;
}

bool Game::isThereAWinner() {
    for (Player *player : players) {
        if (player->getNumberOfCards() == 0)
            return true;
    }

    return false;
}