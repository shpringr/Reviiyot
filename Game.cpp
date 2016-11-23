#include "Deck.h"
#include "Player.h"
#include "Game.h"
#include <iostream>

using namespace std;

Game::Game(char *configurationFile) {
    dummyConfig1();
    readConfigFile(configurationFile);
    //printState();
}

void Game::dummyConfig1() {
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

//    for (int i = 0; i < deck.getCards().size(); ++i) {
//        players[0]->addCard(*(deck.getCards()[i]));
//    }

}

Card *Game::tryFetch() {
    Card *temp = deck.fetchCard();
    return temp;
}

int Game::trygetNumberOfCards() {
    return deck.getNumberOfCards();
}

int Game::getNumbersOfPlayers() {
    return (int) players.size();
}


void Game::dummyConfig2() {

}

void Game::dummyConfig3() {

}

vector<Player *> Game::getPlayers() {
    return players;

}

void Game::readConfigFile(char *configurationFile) {}

void Game::init() {

    for (int i = 0; i < players.size(); ++i) {

        for (int j = 0; j < 7 && deck.getCards().size() > 0; ++j) {
            Card *currCard = deck.fetchCard();
            Player *currPlayer = players[i];
            currPlayer->addCard(*currCard);

            if (currPlayer->getNumberOfSamePref(currCard) == 4) {
                currPlayer->discardSet(currCard);
            }
        }
    }

}

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

void Game::play() {
    int currPlayer = 0;

    while (!isThereAWinner()) {
        increaseNumberOfTurns();
        int nextPlayer = (currPlayer + 1) % players.size();

        Player *askingPlayer = players[currPlayer];
        Player *askedPlayer = players[nextPlayer]; //meanwhile till we have getFromWho()
        Card *cardToAsk = askingPlayer->getFirstCard(); //meanwhile till we have getCardToAsk()

        cout << "asking " + askingPlayer->getName() << endl;
        cout << "asked " + askedPlayer->getName() << endl;
        cout << "card " << cardToAsk->toString() << endl;

        vector<Card *> cardsOfSamePref = askedPlayer->getCardsWithSamePref(cardToAsk);

        if (cardsOfSamePref.size() == 0 && deck.getNumberOfCards() > 0)
            askingPlayer->addCard(*deck.fetchCard());
        else {
            for (Card *cardToMove : cardsOfSamePref) {
                askedPlayer->removeCard(*cardToMove);
                askingPlayer->addCard(*cardToMove);
            }

            if (askedPlayer->getNumberOfCards() > 0) {
                for (int j = 0; j < cardsOfSamePref.size() && deck.getNumberOfCards() > 0; ++j) {
                    askedPlayer->addCard(*deck.fetchCard());
                }
            }


            if (askingPlayer->getNumberOfSamePref(cardToAsk) == 4)
                askingPlayer->discardSet(cardToAsk);
        }

        if (isVerbalOn) {
            printNumberOfTurns();
            printState();
        }

        currPlayer = nextPlayer;


    }
//    Player asked = ask.getFromWho(vector(copy));
//    char cardToAsk = askingPlayer.getCardToAsk(asked.getCards());
}

void Game::printState() {

    cout << deck.toString() << endl;
    for (int i = 0; i < players.size(); ++i) {
        cout << players[i]->toString() << endl;
    }

}       //This function prints the cards remaining in
//the deck from top to bottom in a single line,
//followed by the name and sorted hand of all players (a single line per player).
//***This function should be implemented with extra care because yonatan said.***
//

void Game::printWinner() {}       // or winners

void Game::printNumberOfTurns() {}

/*
//ifstream infile;

//infile("/home/spl/workspace/Reviiyot/config_1.txt");


string readFile(){

// ifstream is used for reading files
// We'll read from a file called Sample.dat

ifstream inf("/home/spl/workspace/Reviiyot/config_1.txt");

// If we couldn't open the input file stream for reading
if (!inf){
    // Print an error and exit
    cerr << "Uh oh, config_1.txt could not be opened for reading!" << endl;
    exit(1);
}

// While there's still stuff left to read
while (inf)
{
    // read stuff from the file into a string and print it
    std::string strInput;
    getline(inf, strInput);
    cout << strInput << endl;
}

// When inf goes out of scope, the ifstream
// destructor will close the file

return 0;

}


int main()
{
    using namespace std;

    // ifstream is used for reading files
    // We'll read from a file called Sample.dat
    ifstream inf("Sample.dat");

    // If we couldn't open the input file stream for reading
    if (!inf)
    {
        // Print an error and exit
        cerr << "Uh oh, Sample.dat could not be opened for reading!" << endl;
        exit(1);
    }

    // While there's still stuff left to read
    while (inf)
    {
        // read stuff from the file into a string and print it
        std::string strInput;
        getline(inf, strInput);
        cout << strInput << endl;
    }

    return 0;

    // When inf goes out of scope, the ifstream
    // destructor will close the file
}

*/

