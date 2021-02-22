#pragma once
#include "MovementType.h"
#include "ShapeType.h"
#include <vector>
#include "Piece.h"
#include <iostream>
#include "BoardSize.h"
using namespace std;
class Collisions {

	public:
		Collisions(BoardSize boardSize) {
			this->boardSize = boardSize;
		}
		bool checkBoardCollision(int pieceNumber, float distance, MovementType movementType, vector<Piece*> pieces);
		int checkPieceCollision(int pieceNumber, vector<Piece*> pieces);
	private:
		BoardSize boardSize;
		bool circleCircleCollision(Piece* lCircle, Piece* rCircle);
		bool squareSquareCollision(Piece* lSquare, Piece* rSquare);
		bool circleSquareCollision(Piece* lhs, Piece* rhs);

};