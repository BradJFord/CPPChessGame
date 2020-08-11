#include <iostream>
#include <vector>
#include "Piece.h"
#include "Rook.h"
#include "Bishop.h"
#include "Queen.h"
#include<time.h>
#include "MovementType.h"
#include "PieceType.h"
/*Name: Bradley John Ford
* Date: December 2019
*
* Program Description: This program is a simulation of a chess-like game. There are only 3 pieces:
* Rook,Bishop and Queen, and the board and distances moved are measured in floats rather than square units.
* This Program includes Inheritance, collision detection between pieces and the board.
*
* Class Description: this class is responsible for running the game, creating pieces, moving pieces,
* keeping track of the score, detecting collisons, and resolving them.
  */



using namespace std;

vector<Piece*> pieces;
int gameMoveLength = 100;

//create board bounds
float boardMaxWidth = 20.0f;
float boardMinWidth = 0.0f;

float boardMaxHeight = 20.0f;
float boardMinHeight = 0.0f;

int rookScore = 0;
int bishopScore = 0;
int queenScore = 0;

bool checkBoardCollision(int pieceNumber,float distance,MovementType movementType){
	if (movementType == UP) {
		float checkYAxis = pieces.at(pieceNumber)->getYCoord() + (distance);
		if (checkYAxis > (boardMaxHeight - 1)) {
			cout << "collided with board" << endl;
			return true;
			
		}
		else {
			return false;
		}
	}
	else if (movementType == DOWN) {
		float checkYAxis = pieces.at(pieceNumber)->getYCoord() + (-distance);
		if (checkYAxis < (boardMinHeight + 1)) {
			cout << "collided with board" << endl;
			return true;
		}
	}
	else if (movementType == LEFT) {
		float checkXAxis = pieces.at(pieceNumber)->getXCoord() + (-distance);
		if (checkXAxis < (boardMinWidth + 1)) {
			cout << "collided with board" << endl;
			return true;
		}
		else {
			return false;
		}
	}
	else if (movementType == RIGHT) {
		float checkXAxis = pieces.at(pieceNumber)->getXCoord() + (distance);
		if (checkXAxis > (boardMaxWidth - 1)) {
			cout << "collided with board" << endl;
			return true;
		}
		else {
			return false;
		}
	}
	else if (movementType == UP_LEFT) {
		distance = (sin(45) * distance);
		float checkYAxis = pieces.at(pieceNumber)->getYCoord() + (distance);
		float checkXAxis = pieces.at(pieceNumber)->getXCoord() + (-distance);

		if (checkXAxis < (boardMinWidth + 1) || checkYAxis > (boardMaxHeight - 1)) {
			cout << "collided with board" << endl;
			return true;
		}
		else {
			return false;
		}
	}
	else if (movementType == UP_RIGHT) {
		distance = (sin(45) * distance);
		float checkYAxis = pieces.at(pieceNumber)->getYCoord() + (distance);
		float checkXAxis = pieces.at(pieceNumber)->getXCoord() + (distance);

		if (checkXAxis > (boardMaxWidth - 1) || checkYAxis > (boardMaxHeight - 1)) {
			cout << "collided with board" << endl;
			return true;
		}
		else {
			return false;
		}
	}
	else if (movementType == DOWN_LEFT) {
		distance = (sin(45) * distance);
		float checkYAxis = pieces.at(pieceNumber)->getYCoord() + (-distance);
		float checkXAxis = pieces.at(pieceNumber)->getXCoord() + (-distance);

		if (checkXAxis < (boardMinWidth + 1) || checkYAxis < (boardMinHeight + 1)) {
			cout << "collided with board" << endl;
			return true;
		}
		else {
			return false;
		}
	}
	else if (movementType == DOWN_RIGHT) {
		distance = (sin(45) * distance);
		float checkYAxis = pieces.at(pieceNumber)->getYCoord() + (-distance);
		float checkXAxis = pieces.at(pieceNumber)->getXCoord() + (distance);

		if (checkXAxis > boardMaxWidth - 1 || checkYAxis < boardMinHeight + 1) {
			cout << "collided with board" << endl;
			return true;
		}
		else {
			return false;
		}
	}
}
void createPieces() {
	for (int i = 0; i < 6; i++) {
		float randX = rand() % 18;
		float randY = rand() % 18;

		int randPiece = rand() % 3;
		if (randPiece == 0) {
			pieces.push_back(new Rook(randX, randY));
			cout << "created rook at index: " << i << endl;
		}
		else if (randPiece == 1) {
			pieces.push_back(new Bishop(randX, randY));
			cout << "created bishop at index: " << i << endl;
		}
		else {
			pieces.push_back(new Queen(randX, randY));
			cout << "created queen at index: " << i << endl;
		}
	}
}
MovementType getMovementType(int piece) {
	MovementType movementType;
	if (pieces.at(piece)->getPieceType() == ROOK) {
		return movementType = MovementType(rand() % 4);
	}
	else if (pieces.at(piece)->getPieceType() == BISHOP) {
		return movementType = MovementType(rand() % 8 + 5);
	}
	else if (pieces.at(piece)->getPieceType() == QUEEN) {
		return movementType = MovementType(rand() % 8);
	}

}
void addScore(int addScorePiece){
	PieceType pieceType = pieces.at(addScorePiece)->getPieceType();
	if (pieceType == ROOK) {
		rookScore++;
		cout << "rook score: " << rookScore << endl;
	}
	else if (pieceType == BISHOP) {
		bishopScore++;
		cout << "bishop score: " << bishopScore << endl;
	}
	else if(pieceType == QUEEN){
		queenScore++;
		cout << "queen score: "<< queenScore<< endl;
	}
}
int checkPieceCollision(int pieceNumber) {
	for (int i = 0; i < pieces.size(); i++) {
		if (pieceNumber == i) {
			continue;
		}
		if (pieces.at(pieceNumber)->getShape() == SQUARE && pieces.at(i)->getShape() == SQUARE) {
			if (pieces.at(i)->getXCoord() <= pieces.at(pieceNumber)->getXCoord() + pieces.at(pieceNumber)->getSize() &&
				pieces.at(pieceNumber)->getXCoord() <= pieces.at(i)->getXCoord() + pieces.at(i)->getSize() &&
				pieces.at(i)->getYCoord() <= pieces.at(pieceNumber)->getYCoord() + pieces.at(pieceNumber)->getSize() &&
				pieces.at(pieceNumber)->getYCoord() <= pieces.at(i)->getYCoord() + pieces.at(i)->getSize()) {

				cout << "COLLISION DETECTED BETWEEN SQUARE & SQUARE" << endl;
				return i;
			}
			else {
				return -1;
			}
		}
		else if (pieces.at(pieceNumber)->getShape() == CIRCLE && pieces.at(i)->getShape() == CIRCLE) {
			if ((pieces.at(pieceNumber)->getSize() + pieces.at(i)->getSize() * pieces.at(pieceNumber)->getSize()) + (pieces.at(i)->getSize() >= (pieces.at(pieceNumber)->getXCoord() + pieces.at(i)->getXCoord() * pieces.at(pieceNumber)->getXCoord() + pieces.at(i)->getXCoord())) +
				(pieces.at(pieceNumber)->getYCoord() + pieces.at(i)->getYCoord() * pieces.at(pieceNumber)->getYCoord() + pieces.at(i)->getYCoord())) {

				cout << "COLLISION DETECTED BETWEEN CIRCLE & CIRCLE" << endl;
				return i;
			}
			else {
				return -1;
			}
		}
		else if (pieces.at(pieceNumber)->getShape() == CIRCLE && pieces.at(i)->getShape() == SQUARE) {

			float x = pieces.at(pieceNumber)->getXCoord();
			float y = pieces.at(pieceNumber)->getYCoord();;

			//finding closest edge
			if (pieces.at(pieceNumber)->getXCoord() < pieces.at(i)->getXCoord()) {
				x = pieces.at(i)->getXCoord();
			}
			else if (pieces.at(pieceNumber)->getXCoord() > pieces.at(i)->getXCoord() + pieces.at(i)->getSize()) {
				x = pieces.at(i)->getXCoord() + pieces.at(i)->getSize();
			}

			if (pieces.at(pieceNumber)->getYCoord() < pieces.at(i)->getYCoord()) {
				y = pieces.at(i)->getYCoord();
			}
			else if (pieces.at(pieceNumber)->getYCoord() > pieces.at(i)->getYCoord() + pieces.at(i)->getSize()) {
				y = pieces.at(i)->getYCoord() + pieces.at(i)->getSize();
			}

			//finding distance from the closest edge
			float distDiffX = pieces.at(pieceNumber)->getXCoord() - x;
			float distDiffY = pieces.at(pieceNumber)->getYCoord() - y;

			float distance = sqrt((pow(distDiffX, 2)) + (pow(distDiffY, 2)));

			if (distance <= pieces.at(pieceNumber)->getSize()) {
				cout << "COLLISION DETECTED BETWEEN CIRCLE & SQUARE" << endl;
				return i;
			}
			else {
				return -1;
			}
		}
		else if (pieces.at(pieceNumber)->getShape() == SQUARE && pieces.at(i)->getShape() == CIRCLE) {

			float x = pieces.at(i)->getXCoord();
			float y = pieces.at(i)->getYCoord();


			//finding closest edge
			if (pieces.at(i)->getXCoord() < pieces.at(pieceNumber)->getXCoord()) {
				x = pieces.at(pieceNumber)->getXCoord();
			}
			else if (pieces.at(i)->getXCoord() > pieces.at(pieceNumber)->getXCoord() + pieces.at(pieceNumber)->getSize()) {
				x = pieces.at(pieceNumber)->getXCoord() + pieces.at(pieceNumber)->getSize();
			}

			if (pieces.at(i)->getYCoord() < pieces.at(pieceNumber)->getYCoord()) {
				y = pieces.at(pieceNumber)->getYCoord();
			}
			else if (pieces.at(i)->getYCoord() > pieces.at(pieceNumber)->getYCoord() + pieces.at(pieceNumber)->getSize()) {
				y = pieces.at(pieceNumber)->getYCoord() + pieces.at(pieceNumber)->getSize();
			}

			//finding distance from the closest edge
			float distDiffX = pieces.at(i)->getXCoord() - x;
			float distDiffY = pieces.at(i)->getYCoord() - y;

			float distance = sqrt((pow(distDiffX, 2)) + (pow(distDiffY, 2)));
			if (distance <= pieces.at(i)->getSize()) {
				cout << "COLLISION DETECTED BETWEEN SQUARE & CIRCLE" << endl;
				return i;
			}
			else {
				return -1;
			}
		}
	}

}
void moveThis(int piece, float distance, MovementType direction) {
		//line below assumes both width and height are the same, if not must change values manually
		while (distance > 0.0) {
			if (distance >= 1.0) {
				float tempDistance = 1.0;
				if (checkBoardCollision(piece, distance, direction) == true) {
						distance = 0;
						cout << "choose new direction and distance" << endl;
				}
				else {
					pieces.at(piece)->move(tempDistance, direction);
					int pieceCollisionCheck = checkPieceCollision(piece);

					if (pieceCollisionCheck != -1) {
						//consider shape clipping
						addScore(piece);
						pieces.erase(pieces.begin() + pieceCollisionCheck);
						break;

					}
					distance = distance - tempDistance;

				}
			}
			else {
				pieces.at(piece)->move(distance, direction);
				int pieceCollisionCheck = checkPieceCollision(piece);
				if (pieceCollisionCheck != -1) {
					//consider shape clipping
					addScore(piece);
					pieces.erase(pieces.begin() + pieceCollisionCheck);
					break;
				}
				distance = distance - distance;
			}
			gameMoveLength--;
			//cout << "index: " << i << " x Coord: " << pieces.at(i)->getXCoord() << " y Coord: " << pieces.at(i)->getYCoord() << " Piece type: " << pieces.at(i)->getPieceType() << endl;
		}
}
void movePieces() {
	for (int i = 0; i < pieces.size(); i++) {
		//line below assumes both width and height are the same, if not must change values manually
		float distance = rand() % 18;
		MovementType movementType = getMovementType(i);
		while (distance > 0.0 && i < pieces.size()) {
			if (distance >= 1.0) {
				float tempDistance = 1.0;
				if (checkBoardCollision(i, distance, movementType) == true) {
					while (checkBoardCollision(i, distance, movementType) == true) {
						movementType = getMovementType(i);
						distance = rand() % 18;
					}
				}
				else {
					pieces.at(i)->move(tempDistance, movementType);
					int pieceCollisionCheck = checkPieceCollision(i);

					if(pieceCollisionCheck != -1){
						//consider shape clipping
						addScore(i);
						pieces.erase(pieces.begin() + pieceCollisionCheck);
						break;

						
					}
					distance = distance - tempDistance;

				}
			}
			else{
				pieces.at(i)->move(distance, movementType);
				int pieceCollisionCheck = checkPieceCollision(i);
				if (pieceCollisionCheck != -1) {
					//consider shape clipping
					addScore(i);
					pieces.erase(pieces.begin() + pieceCollisionCheck);
					break;
				}
				distance = distance - distance;
			}
			gameMoveLength--;
			//cout << "index: " << i << " x Coord: " << pieces.at(i)->getXCoord() << " y Coord: " << pieces.at(i)->getYCoord() << " Piece type: " << pieces.at(i)->getPieceType() << endl;
		}
	}
}
void test() {
	gameMoveLength = 100;

	//checking move and piece collision
	//square - square
	pieces.push_back(new Rook(2, 2));
	pieces.push_back(new Rook(5, 2)); //square - square
	moveThis(0, 3, RIGHT);
	pieces.clear();


	//circle - circle
	pieces.push_back(new Bishop(9, 9)); //circle - square
	pieces.push_back(new Bishop(15, 15)); //circle - circle
	moveThis(0, 7, UP_RIGHT);
	pieces.clear();

	//square circle
	pieces.push_back(new Rook(2, 2));
	pieces.push_back(new Bishop(2, 5));
	moveThis(0, 2.5, UP);
	pieces.clear();

	//circle square
	pieces.push_back(new Queen(16, 16));
	pieces.push_back(new Rook(14, 14)); // square - circle
	moveThis(0, 5, DOWN_LEFT);
	pieces.clear();

	//checking board collision

	pieces.push_back(new Rook(2, 2));
	pieces.push_back(new Bishop(18, 18)); //circle - circle

	moveThis(0, 3, DOWN);
	moveThis(1, 3, UP_RIGHT);
	pieces.clear();

	
}


void main() {
	cout << "enter 1 to play a random game or 2 to start tests" << endl;
	int x = 0;
	cin >> x;
	if (x == 1) {
		srand(static_cast <unsigned>(time(0)));

		createPieces();
		cout << *pieces.at(0) << endl;
		while (gameMoveLength > 0) {
			if (pieces.size() > 1) {
				movePieces();
			}
			else {
				break;
			}
		}
	}
	else if (x ==2) {
		test();
	}
	else {
		cout << "enter valid number" << endl;
	}
}