#include "Game.h"
void test(Game game) {

	//checking move and piece collision
	//square - square
	game.getPieces()->push_back(new Rook(2, 2));
	game.getPieces()->push_back(new Rook(5, 2)); //square - square
	game.moveThis(0, 3, RIGHT);
	game.getPieces()->clear();


	//circle - circle
	game.getPieces()->push_back(new Bishop(9, 9)); //circle - square
	game.getPieces()->push_back(new Bishop(15, 15)); //circle - circle
	game.moveThis(0, 7, UP_RIGHT);
	game.getPieces()->clear();

	//square circle
	game.getPieces()->push_back(new Rook(2, 2));
	game.getPieces()->push_back(new Bishop(2, 5));
	game.moveThis(0, 2.5, UP);
	game.getPieces()->clear();

	//circle square
	game.getPieces()->push_back(new Queen(16, 16));
	game.getPieces()->push_back(new Rook(14, 14)); // square - circle
	game.moveThis(0, 5, DOWN_LEFT);
	game.getPieces()->clear();

	//checking board collision

	game.getPieces()->push_back(new Rook(2, 2));
	game.getPieces()->push_back(new Bishop(18, 18)); //circle - circle

	game.moveThis(0, 3, DOWN);
	game.moveThis(1, 3, UP_RIGHT);
	game.getPieces()->clear();


}


void main() {
	srand(static_cast <unsigned>(time(0)));
	int x = 0;
	cout << "enter 1 to play a random game or 2 to start tests" << endl;
	cin >> x;
	Game game(20.0f, 20.0f, 0.0f, 0.0f, 100);
	switch (x) {
		case 1:
			game.createPieces();
			cout << *game.getPieces()->at(0) << endl;
			while (game.getGameMoveLength() > 0) {
				if (game.getPieces()->size() > 1) {
					game.playGame();
				}
				else {
					break;
				}
			break;
		case 2:
			test(game);
			break;
		default:
			cout << "enter valid number" << endl;
			break;
			}
	}
}