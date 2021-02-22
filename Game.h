#pragma once
#include <iostream>
#include <vector>
#include "Piece.h"
#include "Rook.h"
#include "Bishop.h"
#include "Queen.h"
#include<time.h>
#include "MovementType.h"
#include "PieceType.h"
#include "Collisions.h"
#include "BoardSize.h"
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

class Game {
	public:
		Game(float boardMaxWidth, float boardMaxHeight, float boardMinWidth, float boardMinHeight, int gameMoveLength) {
			this->boardSize.boardMaxWidth = boardMaxWidth;
			this->boardSize.boardMaxHeight = boardMaxHeight;
			this->boardSize.boardMinWidth = boardMinWidth;
			this->boardSize.boardMinHeight = boardMinHeight;
			this->gameMoveLength = gameMoveLength;

			collisions = new Collisions(boardSize);
			pieces = new vector<Piece*>;
		}

		BoardSize getBoardSize() {
			return boardSize;
		}
		int getGameMoveLength() {
			return gameMoveLength;
		}
		vector<Piece*>* getPieces() {
			return pieces;
		}
		void createPieces();
		void playGame();

		bool movePieces(int i, float distance, MovementType movementType);
		void moveThis(int piece, float distance, MovementType direction);
		void printMovementInformation(Piece* currentPiece, int previousX, int previousY);
	private:

		Collisions* collisions;
		MovementType getMovementType(int piece);
		void addScore(int addScorePiece);
		
		BoardSize boardSize;
		vector<Piece*>* pieces;
		int gameMoveLength;
		int rookScore = 0;
		int bishopScore = 0;
		int queenScore = 0;
};