#pragma once
/*Name: Bradley John Ford
* Date: December 2019
*
* Program Description: This program is a simulation of a chess-like game. There are only 3 pieces:
* Rook,Bishop and Queen, and the board and distances moved are measured in floats rather than square units.
* This Program includes Inheritance, collision detection between pieces and the board.
*
* Class Description: This class contains the enum information needed to determine the direction of movement
* for a piece.
  */

enum MovementType {
	UP = 0,
	DOWN = 1,
	LEFT =2,
	RIGHT = 3,
	UP_LEFT = 4,
	UP_RIGHT = 5,
	DOWN_LEFT= 6,
	DOWN_RIGHT = 7
};