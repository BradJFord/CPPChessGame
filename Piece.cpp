#include "Piece.h"
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
Piece::Piece() {
}

float Piece::getSize()const {
	return size;
}
float Piece::getXCoord()const {
	return xCoord;
}
float Piece::getYCoord()const {
	return yCoord;
}

void Piece::setXCoord(float xCoord){
	this->xCoord = this->xCoord + xCoord;
}
void Piece::setYCoord(float yCoord){
	this->yCoord = this->yCoord + yCoord;
}

ShapeType Piece::getShape() const {
	return shape;
}
PieceType Piece::getPieceType() const {
	return piece;
}
std::ostream& operator<<(std::ostream& outStream, const Piece& piece) {
	if (piece.getPieceType() == ROOK) {
		outStream << "Piece: Rook "<< " XCoords: "<< piece.getXCoord()<< " yCoords: "<< piece.getYCoord() << " Shape: Square"<< " Size: "<< piece.getSize() << "\n";
	
	}
	else if (piece.getPieceType() == BISHOP) {
		outStream << "Piece: Bishop " << " XCoords: " << piece.getXCoord() << " yCoords: " << piece.getYCoord() << " Shape: Circle" << " Size: " << piece.getSize() << "\n";

	}
	else if (piece.getPieceType() == QUEEN) {
		outStream << "Piece: Queen " << " XCoords: " << piece.getXCoord() << " yCoords: " << piece.getYCoord() << " Shape: Circle" << " Size: " << piece.getSize() << "\n";
	}
	return outStream;
}