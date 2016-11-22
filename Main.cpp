#include <string>
#include <vector>
#include <iostream>
#include "Card.h"
#include "Game.h"
using namespace std;

int main(int argc, char **argv) {

	FigureCard * C = new FigureCard('A','C');
	NumericCard* C1 = new NumericCard('3','C');

	FigureCard c1 = FigureCard('H', 'Q');
	cout << c1.toString() << endl;

	NumericCard c2 = NumericCard(5, 'H');
	cout << c2.toString() << endl;
//	int argc, char **argv
	 char* configurationFile = argv[1];



	Game game = Game(configurationFile);
	cout << "first : " << endl;
	game.printState();

	Card* temp = game.tryFetch();
	cout << temp->toString() << endl;
	cout << "second : " << endl;
	game.printState();



	/*game.init();
 	Game initializedGame = game;
 	game.play();

	cout << std::endl;
 	game.printWinner();
	game.printNumberOfTurns();
	cout << "----------" << endl;
	cout<<"Initial State:"<<endl;
  	initializedGame.printState();
	cout<<"----------"<<endl;
	cout<<"Final State:"<<endl;
	game.printState();
	*/
	//Shape s = Club;
	//Card Card(s);

	return 0;
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
