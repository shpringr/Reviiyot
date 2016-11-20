#include <iostream>
#include "../include/Card.h"


using namespace std;

int main(int argc, char **argv) {

	Shape s = Heart;
	Figure f = Queen;

	FigureCard c1 = FigureCard(f, s);
	cout << c1.toString() << endl;

	NumericCard c2 = NumericCard(5, s);
	cout << c2.toString() << endl;
	/*int argc, char **argv
	 * char* configurationFile = argv[1];

	Game game = Game(configurationFile);
	game.init();
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



