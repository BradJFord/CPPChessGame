#include "Collisions.h"
bool Collisions::checkBoardCollision(int pieceNumber, float distance, MovementType movementType, vector<Piece*> pieces) {
	float checkXAxis = 0.0f;
	float checkYAxis = 0.0f;
	switch (movementType) {
	case UP:
		checkYAxis = pieces.at(pieceNumber)->getYCoord() + (distance);
		if (checkYAxis > (boardSize.boardMaxHeight - 1)) {
			cout << " Proposed direction UP will collide with board, another direction will be chosen." << endl;
			return true;
		}
		break;
	case DOWN:
		checkYAxis = pieces.at(pieceNumber)->getYCoord() + (-distance);
		if (checkYAxis < (boardSize.boardMinHeight + 1)) {
			cout << "Proposed direction DOWN will collide with board, another direction will be chosen." << endl;
			return true;
		}
		break;
	case LEFT:
		checkXAxis = pieces.at(pieceNumber)->getXCoord() + (-distance);
		if (checkXAxis < (boardSize.boardMinWidth + 1)) {
			cout << "Proposed direction LEFT will collide with board, another direction will be chosen." << endl;
			return true;
		}
		break;
	case RIGHT:
		checkXAxis = pieces.at(pieceNumber)->getXCoord() + (distance);
		if (checkXAxis > (boardSize.boardMaxWidth - 1)) {
			cout << "Proposed direction RIGHT will collide with board, another direction will be chosen." << endl;
			return true;
		}
		break;
	case UP_LEFT:
		distance = (sin(45) * distance);
		checkYAxis = pieces.at(pieceNumber)->getYCoord() + (distance);
		checkXAxis = pieces.at(pieceNumber)->getXCoord() + (-distance);

		if (checkXAxis < (boardSize.boardMinWidth + 1) || checkYAxis >(boardSize.boardMaxHeight - 1)) {
			cout << "Proposed direction UP_LEFT will collide with board, another direction will be chosen." << endl;
			return true;
		}
		break;
	case UP_RIGHT:
		distance = (sin(45) * distance);
		checkYAxis = pieces.at(pieceNumber)->getYCoord() + (distance);
		checkXAxis = pieces.at(pieceNumber)->getXCoord() + (distance);

		if (checkXAxis > (boardSize.boardMaxWidth - 1) || checkYAxis > (boardSize.boardMaxHeight - 1)) {
			cout << "Proposed direction UP_RIGHT will collide with board, another direction will be chosen." << endl;
			return true;
		}
		break;
	case DOWN_LEFT:
		distance = (sin(45) * distance);
		checkYAxis = pieces.at(pieceNumber)->getYCoord() + (-distance);
		checkXAxis = pieces.at(pieceNumber)->getXCoord() + (-distance);

		if (checkXAxis < (boardSize.boardMinWidth + 1) || checkYAxis < (boardSize.boardMinHeight + 1)) {
			cout << "Proposed direction DOWN_LEFT will collide with board, another direction will be chosen." << endl;
			return true;
		}
		break;
	case DOWN_RIGHT:
		distance = (sin(45) * distance);
		checkYAxis = pieces.at(pieceNumber)->getYCoord() + (-distance);
		checkXAxis = pieces.at(pieceNumber)->getXCoord() + (distance);

		if (checkXAxis > boardSize.boardMaxWidth - 1 || checkYAxis < boardSize.boardMinHeight + 1) {
			cout << "Proposed direction DOWN_RIGHT will collide with board, another direction will be chosen." << endl;
			return true;
		}
		break;
	default:
		return false;
		break;
	}
	return false;
}


bool Collisions::circleCircleCollision(Piece* lhs, Piece* rhs) {
	if ((lhs->getSize() + rhs->getSize() * lhs->getSize()) + (rhs->getSize() >= (lhs->getXCoord() + rhs->getXCoord() * lhs->getXCoord() + rhs->getXCoord())) + (lhs->getYCoord() + rhs->getYCoord() * lhs->getYCoord() + rhs->getYCoord())) {
		cout << "COLLISION DETECTED BETWEEN CIRCLE & CIRCLE" << endl;
		return true;
	}
	return false;
}
bool Collisions::squareSquareCollision(Piece* lhs, Piece* rhs) {
	if (rhs->getXCoord() <= lhs->getXCoord() + lhs->getSize() && lhs->getXCoord() <= rhs->getXCoord() + rhs->getSize() &&
		rhs->getYCoord() <= lhs->getYCoord() + lhs->getSize() && lhs->getYCoord() <= rhs->getYCoord() + rhs->getSize()) {
		cout << "COLLISION DETECTED BETWEEN SQUARE & SQUARE" << endl;
		return true;
	}
	return false;
}
bool Collisions::circleSquareCollision(Piece* lhs, Piece* rhs) {
	float x = lhs->getXCoord();
	float y = lhs->getYCoord();;

	//finding closest edge
	if (lhs->getXCoord() < rhs->getXCoord()) {
		x = rhs->getXCoord();
	}
	else if (lhs->getXCoord() > rhs->getXCoord() + rhs->getSize()) {
		x = rhs->getXCoord() + rhs->getSize();
	}

	if (lhs->getYCoord() < rhs->getYCoord()) {
		y = rhs->getYCoord();
	}
	else if (lhs->getYCoord() > rhs->getYCoord() + rhs->getSize()) {
		y = rhs->getYCoord() + rhs->getSize();
	}

	//finding distance from the closest edge
	float distDiffX = lhs->getXCoord() - x;
	float distDiffY = lhs->getYCoord() - y;

	float distance = sqrt((pow(distDiffX, 2)) + (pow(distDiffY, 2)));

	if (distance <= lhs->getSize()) {
		cout << "COLLISION DETECTED BETWEEN CIRCLE & SQUARE" << endl;
		return true;
	}
	return false;
}


int Collisions::checkPieceCollision(int pieceNumber, vector<Piece*> pieces) {
	for (int i = 0; i < pieces.size(); i++) {
		if (pieceNumber == i) {
			continue;
		}
		if (pieces.at(pieceNumber)->getShape() == SQUARE && pieces.at(i)->getShape() == SQUARE) {
			Piece* lhs = pieces.at(pieceNumber);
			Piece* rhs = pieces.at(i);
			if (squareSquareCollision(lhs, rhs)) {
				return i;
			}
			
		}
		else if (pieces.at(pieceNumber)->getShape() == CIRCLE && pieces.at(i)->getShape() == CIRCLE) {

			Piece* lhs = pieces.at(pieceNumber);
			Piece* rhs = pieces.at(i);
			if (circleCircleCollision(lhs, rhs)) {
				return i;
			}
		}
		else if (pieces.at(pieceNumber)->getShape() == CIRCLE && pieces.at(i)->getShape() == SQUARE) {
			Piece* lhs = pieces.at(pieceNumber);
			Piece* rhs = pieces.at(i);
			if (circleSquareCollision(lhs, rhs)) {
				return i;
			}
		}	
		else if (pieces.at(pieceNumber)->getShape() == SQUARE && pieces.at(i)->getShape() == CIRCLE) {
			Piece* lhs = pieces.at(i);
			Piece* rhs = pieces.at(pieceNumber);
			if (circleSquareCollision(lhs, rhs)) {
				return i;
			}
		}
	}
	return -1;
}