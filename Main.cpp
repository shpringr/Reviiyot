#include <string>
#include <vector>
#include <iostream>
#include "Card.h"
#include "Game.h"

void tryCompareCards();

using namespace std;

int main(int argc, char **argv) {

    char *configurationFile = argv[1];
    Game game = Game(configurationFile);
    game.init();
    game.printState();
    Game initializedGame = game;
    game.play();
    cout << std::endl;
    game.printWinner();
    game.printNumberOfTurns();
    cout << "----------" << endl;
    cout << "Initial State:" << endl;
    initializedGame.printState();
    cout << "----------" << endl;
    cout << "Final State:" << endl;
    game.printState();

//    tryCompareCards();

    return 0;


}

void tryCompareCards() {

    FigureCard *C = new FigureCard('A', 'C');
    NumericCard *C1 = new NumericCard(3, 'C');

    FigureCard *C2 = new FigureCard('A', 'C');
    FigureCard *C3 = new FigureCard('A', 'D');
    FigureCard *C4 = new FigureCard('K', 'D');

    NumericCard *C5 = new NumericCard(3, 'C');
    NumericCard *C6 = new NumericCard(3, 'D');
    NumericCard *C7 = new NumericCard(2, 'D');

    int a1 = C->compare(C1); // 1
    int a2 = C1->compare(C); //-1

    int a3 = C->compare(C2); // 0
    int a4 = C2->compare(C3); //-1
    int a5 = C3->compare(C4); // 1

    int a6 = C1->compare(C5); //0
    int a7 = C5->compare(C6); //-1
    int a8 = C6->compare(C7); //1

    cout << "actul : " << a1 << a2 << a3 << a4 << a5 << a6 << a7 << a8 << endl;
    cout << "1-10-110-11" << endl;
}

/*

	vector<Card *> myVector1;
	myVector1.push_back(C);
	myVector1.push_back(C1);



	for(unsigned int i =0; i<myVector1.size(); i++){
		cout << myVector1.size() << "  " << myVector1[i] <<  " ";
	}

	cout << myVector1[0]->toString() << "  " ;

	vector<int> myVector;
	myVector.push_back(3);
	myVector.push_back(4);
	myVector.push_back(5);
	myVector.push_back(6);

	cout << "myVector:" << endl;

	for(unsigned int i =0; i<myVector.size(); i++){
		cout << myVector[i] << " ";
	}

	int temp = myVector.front();
	cout << "\n temp: " << temp  << endl;
	myVector.erase(myVector.begin());

	cout << "\n " << myVector.front()  << endl;


	cout << "myVectorBack:" << endl;

	for(unsigned int i =0; i<myVector.size(); i++){
		cout << myVector[i] << " ";
	}


	//srting card = "KC QH 3D AH JH 2C 3S KS AS JS 3C KH AD QC JD QS 3H KD AC JC 2D 2H 2S QD ";
*/
