// Piece.h
#pragma once
#include <vector>
#include <string>

namespace Umbrella {
	class GameBoard;
	class Piece {
	public:
		struct Position {
			int row, column;
		};
	private:
		std::vector<Position> positions;
	public:
		std::string color = "red";
		int rotation = 0;
		int pieceID;
		Piece(int col0, int row0, int col1, int row1, int col2, int row2, int col3, int row3);

		Piece(const std::vector<int>& vec);
		Piece();

		const std::vector<Position>& getPositions() const {
			return positions;
		}

		void move(char direction, GameBoard board);
		void drop(GameBoard& board); // New method for dropping the piece
		bool canDown(const GameBoard& board) const;
		void moveDown();
		void Reset(std::vector<int> vec);
		void Reset(std::vector<int> vec, int ID);
		void Rotate(GameBoard board, std::vector<int> vec, int ID);
	};
}
