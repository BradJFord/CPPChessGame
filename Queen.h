#pragma once
#include "Piece.h"
/*Name: Bradley John Ford
* Date: December 2019
*
* Program Description: This program is a simulation of a chess-like game. There are only 3 pieces:
* Rook,Bishop and Queen, and the board and distances moved are measured in floats rather than square units.
* This Program includes Inheritance, collision detection between pieces and the board.
*
* Class Description: this class is a child class of the Piece class, it contains the information that
* pertains to a Queen piece and overrides the default move function that is located in Piece.h.
 */
class Queen : public virtual Piece
{
public:
	Queen();
	Queen(float xCoord, float yCoord);
	~Queen();

	void move(float distance, MovementType movementType);
};

