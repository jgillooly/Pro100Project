// Piece.h
#pragma once
#include <vector>

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

		Piece(std::vector<int> vec) {
			positions[0].column = vec[0] + 4;
			positions[0].row = vec[1];

			positions[1].column = vec[2] + 4;
			positions[1].row = vec[3];

			positions[2].column = vec[4] + 4;
			positions[2].row = vec[5];

			positions[3].column = vec[6] + 4;
			positions[3].row = vec[7];
		}
		Piece() {

		}
		Position positions[4];
		void move(char direction);
		void drop(GameBoard& board); // New method for dropping the piece
		bool canDown(const GameBoard& board) const;
		void moveDown();
		void Reset(std::vector<int> vec);
	};
}
