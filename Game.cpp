#include "Game.h"
using namespace std;

void Game::createPieces() {
	int boardWidth = boardSize.boardMaxWidth - 2;
	int boardHeight = boardSize.boardMinHeight - 2;
	for (int i = 0; i < 6; i++) {
		float randX = rand() % boardWidth;
		float randY = rand() % boardHeight;

		int randPiece = rand() % 3;

		switch(randPiece){
			case 0:
				pieces->push_back(new Rook(randX, randY));
				cout << "created rook at index: " << i << endl;
				break;
			case 1:
				pieces->push_back(new Bishop(randX, randY));
				cout << "created bishop at index: " << i << endl;
				break;

			case 2:
				pieces->push_back(new Queen(randX, randY));
				cout << "created queen at index: " << i << endl;
				break;
		}
	}
}
MovementType Game::getMovementType(int piece) {
	MovementType movementType;

	switch(pieces->at(piece)->getPieceType()){
		case ROOK:
			return movementType = MovementType(rand() % 4);
			break;
		case BISHOP:
			return movementType = MovementType(rand() % 8 + 5);
			break;
		case QUEEN:
			return movementType = MovementType(rand() % 8);
			break;
	}
}
void Game::addScore(int addScorePiece){
	PieceType pieceType = pieces->at(addScorePiece)->getPieceType();
	switch(pieceType){
		case ROOK:
			rookScore++;
			cout << "rook score: " << rookScore << endl;
			break;
		case BISHOP:
			bishopScore++;
			cout << "bishop score: " << bishopScore << endl;
			break;
		case QUEEN:
			queenScore++;
			cout << "queen score: "<< queenScore<< endl;
			break;
	}
}

void Game::moveThis(int piece, float distance, MovementType direction) {
		//line below assumes both width and height are the same, if not must change values manually
		while (distance > 0.0) {
			if (distance >= 1.0) {
				float tempDistance = 1.0;
				if (collisions->checkBoardCollision(piece, distance, direction, *pieces)) {
						distance = 0;
						cout << "choose new direction and distance" << endl;
				}
				else {
					pieces->at(piece)->move(tempDistance, direction);
					int pieceCollisionCheck = collisions->checkPieceCollision(piece, *pieces);

					if (pieceCollisionCheck != -1) {
						//consider shape clipping
						addScore(piece);
						pieces->erase(pieces->begin() + pieceCollisionCheck);
						break;

					}
					distance = distance - tempDistance;

				}
			}
			else {
				pieces->at(piece)->move(distance, direction);
				int pieceCollisionCheck = collisions->checkPieceCollision(piece, *pieces);
				if (pieceCollisionCheck != -1) {
					//consider shape clipping
					addScore(piece);
					pieces->erase(pieces->begin() + pieceCollisionCheck);
					break;
				}
				distance = distance - distance;
			}
			gameMoveLength--;
		}
}


void Game::printMovementInformation(Piece* currentPiece, int previousX, int previousY) {
	cout << "Moving ";
	switch (currentPiece->getPieceType()) {
	case ROOK:
		cout << "ROOK ";
		break;
	case BISHOP:
		cout << "BISHOP ";
		break;
	case QUEEN:
		cout << "QUEEN ";
		break;
	}
	cout << "from Coordinates X : " << previousX << " Y : " << previousY << " To " << "Coordinates X: " << currentPiece->getXCoord() << " Y : " << currentPiece->getYCoord() << endl;
}
bool Game::movePieces(int i, float distance , MovementType movementType) {
	Piece* currentPiece = pieces->at(i);

	float previousX = currentPiece->getXCoord();
	float previousY = currentPiece->getYCoord();

	currentPiece->move(distance, movementType);
	int pieceCollisionCheck = collisions->checkPieceCollision(i, *pieces);

	if (pieceCollisionCheck != -1) {
		printMovementInformation(currentPiece, previousX, previousY);
		addScore(i);
		pieces->erase(pieces->begin() + pieceCollisionCheck);
		return false;
	}
	return true;
}

void Game::playGame() {
	int bSize = boardSize.boardMaxWidth - 2;
	for (int i = 0; i < pieces->size(); i++) {
		//line below assumes both width and height are the same, if not must change values manually
		float distance = rand() % bSize;
		MovementType movementType = getMovementType(i);
		while (distance > 0.0 && i < pieces->size()) {
			if (distance >= 1.0) {
				float tempDistance = 1.0;
				if (collisions->checkBoardCollision(i, distance, movementType, *pieces)) {
					while (collisions->checkBoardCollision(i, distance, movementType, *pieces)) {
						movementType = getMovementType(i);
						distance = rand() % bSize;
					}
				}
				else {
					if (!movePieces(i,tempDistance,movementType)) {
						break;
					}
					distance = distance - tempDistance;
				}
			}
			else{
				if (!movePieces(i, distance, movementType)) {
					break;
				}
				distance = distance - distance;
			}
			gameMoveLength--;
		}
	}
}