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
		void move(char direction);
		void drop(GameBoard& board); // New method for dropping the piece
		bool canDown(const GameBoard& board) const;
		void moveDown();
	};
}
