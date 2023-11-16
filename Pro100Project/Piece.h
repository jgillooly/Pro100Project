// Piece.h
#pragma once

namespace Umbrella {
	class GameBoard;
	class Piece {
	public:
		struct Position {
			int row, column;
		};
		Position positions[4];
		void move(char dir);
		void drop(GameBoard& board); // New method for dropping the piece
		bool canMoveDown(const GameBoard& board) const;
		void moveDown();
	};
}
