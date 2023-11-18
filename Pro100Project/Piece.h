// Piece.h
#pragma once

namespace Umbrella {
	class GameBoard;
	class Piece {
	public:
		struct Position {
			int row, column;
		};
	public:
		Piece(int col0, int row0, int col1, int row1, int col2, int row2, int col3, int row3) {
			positions[0].column = col0;
			positions[0].row = row0;

			positions[1].column = col1;
			positions[1].row = row1;

			positions[2].column = col2;
			positions[2].row = row2;

			positions[3].column = col3;
			positions[3].row = row3;
		}
		Piece() {

		}
		Position positions[4];
		void move(char direction);
		void drop(GameBoard& board); // New method for dropping the piece
		bool canDown(const GameBoard& board) const;
		void moveDown();
	};
}
