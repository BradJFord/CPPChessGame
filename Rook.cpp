#include "Rook.h"
/*Name: Bradley John Ford
* Date: December 2019
*
* Program Description: This program is a simulation of a chess-like game. There are only 3 pieces:
* Rook,Bishop and Queen, and the board and distances moved are measured in floats rather than square units.
* This Program includes Inheritance, collision detection between pieces and the board.
*
* Class Description: this class is a child class of the Piece class, it contains the information that
* pertains to a Rook piece, it overrides the size to be 2 as it is larger than any other shape currently implemented.
* this class also overrides the default move function that is located in Piece.h.
 */
Rook::Rook(){

}
Rook::Rook(float xCoord, float yCoord){
	this->piece = ROOK;
	this->shape = SQUARE;
	this->size = 2.0f;
	this->setXCoord(xCoord);
	this->setYCoord(yCoord);
}

void Rook::move(float distance, MovementType movementType){
	if (movementType == UP) {
		this->setYCoord(distance);
	}else if(movementType == DOWN) {
		this->setYCoord(-distance);
	}
	else if (movementType == LEFT) {
		this->setXCoord(-distance);
	}
	else if (movementType == RIGHT) {
		this->setXCoord(distance);
	}
}