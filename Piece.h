#pragma once
#include <iostream>
#include "PieceType.h";
#include "ShapeType.h";
#include "MovementType.h";
#include <Math.h>
/*Name: Bradley John Ford
* Date: December 2019
*
* Program Description: This program is a simulation of a chess-like game. There are only 3 pieces:
* Rook,Bishop and Queen, and the board and distances moved are measured in floats rather than square units.
* This Program includes Inheritance, collision detection between pieces and the board.
*
* Class Description: this class is the parent class of the piece hierarchy. It contains all of the basic information
* and functions that every piece should have.
 */
class Piece
{
public:
	Piece();
	
	float getSize()const;
	float getXCoord()const;
	float getYCoord()const;
	ShapeType getShape()const;
	PieceType getPieceType()const;

	void setXCoord(float xCoord);
	void setYCoord(float yCoord);
	virtual void move(float distance, MovementType movementType) =0;


protected:
	ShapeType shape;
	PieceType piece;
	float xCoord = 0;
	float yCoord = 0;
	float size = 2.0f;
};
std::ostream& operator<<(std::ostream& outStream, const Piece& piece);