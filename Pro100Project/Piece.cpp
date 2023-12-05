// Piece.cpp
#include "Piece.h"
#include "GameBoard.h"

namespace Umbrella {
	void Piece::drop(GameBoard& board) {
		while (true) {
			for (int i = 0; i < 4; i++) {
				if (positions[i].row + 1 >= 10 || board.mainBoard.board[positions[i].row + 1][positions[i].column] != ' ') {
					for (int i = 0; i < 4; i++) {
						board.mainBoard.board[positions[i].row][positions[i].column] = '#';
					}
					return;
				}
			}

			// Move the piece down
			for (int i = 0; i < 4; i++) {
				positions[i].row += 1;
			}
		}
	}
	void Piece::move(char direction, GameBoard board) {
		bool canmove = true;
		switch (direction) {
		case 'l': {
			for (int i = 0; i < 4; ++i) {
				if (board.mainBoard.board[positions[i].row][positions[i].column - 1] != ' ') canmove = false;

			}
			if (canmove)
			{
				for (int i = 0; i < 4; ++i) {
					if (positions[i].column == 0) {
						positions[i].column = GameBoard::COL_SIZE - 1;
					}
					else {
						positions[i].column -= 1;
					}
				}
			}
			break;
		}
		case 'r': {
			for (int i = 0; i < 4; ++i) {
				if (board.mainBoard.board[positions[i].row][positions[i].column + 1] != ' ') canmove = false;

			}
			if (canmove)
			{
				for (int i = 0; i < 4; ++i) {
					if (positions[i].column == GameBoard::COL_SIZE - 1) {
						positions[i].column = 0;
					}
					else {
						positions[i].column += 1;
					}
				}
			}
			break;
		}
		}
	}

	bool Piece::canDown(const GameBoard& board) const {
		for (int i = 0; i < 4; ++i) {
			if (positions[i].row + 1 >= 10 || board.mainBoard.board[positions[i].row + 1][positions[i].column] != ' ') {

				return false;  // Collision with the bottom or another piece
			}
		}
		return true;
	}

	void Piece::moveDown() {
		for (int i = 0; i < 4; ++i) {
			positions[i].row += 1;
		}
	}

	void Piece::Reset(std::vector<int> vec) {
		positions[0].column = vec[0] + 4;
		positions[0].row = vec[1];

		positions[1].column = vec[2] + 4;
		positions[1].row = vec[3];

		positions[2].column = vec[4] + 4;
		positions[2].row = vec[5];

		positions[3].column = vec[6] + 4;
		positions[3].row = vec[7];
	}
	void Piece::Reset(std::vector<int> vec, int ID)
	{
		positions[0].column = vec[0] + 4;
		positions[0].row = vec[1];

		positions[1].column = vec[2] + 4;
		positions[1].row = vec[3];

		positions[2].column = vec[4] + 4;
		positions[2].row = vec[5];

		positions[3].column = vec[6] + 4;
		positions[3].row = vec[7];

        pieceID = ID;
        rotation = 0;
    }
    void Piece::Rotate(GameBoard board, std::vector<int> vec, int ID)
    {

        Position origin = positions[0];

        if (vec[1] + origin.row >= 10 || vec[3] + origin.row >= 10 ||
            vec[5] + origin.row >= 10 || vec[7] + origin.row >= 10 ||
            board.mainBoard.board[vec[1] + origin.row][vec[0] + origin.column] != ' ' ||
            board.mainBoard.board[vec[3] + origin.row][vec[2] + origin.column] != ' ' ||
            board.mainBoard.board[vec[5] + origin.row][vec[4] + origin.column] != ' ' ||
            board.mainBoard.board[vec[7] + origin.row][vec[6] + origin.column] != ' ') return;

        positions[0].column = vec[0] + origin.column;
        positions[0].row = vec[1] + origin.row;

		positions[1].column = vec[2] + origin.column;
		positions[1].row = vec[3] + origin.row;

		positions[2].column = vec[4] + origin.column;
		positions[2].row = vec[5] + origin.row;

		positions[3].column = vec[6] + origin.column;
		positions[3].row = vec[7] + origin.row;

		rotation = ID;

		return *this;
	}
}