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
        case 'a': {
            for (int i = 0; i < 4; ++i) {
                if (board.mainBoard.board[positions[i].row][positions[i].column - 1] != ' ') canmove = false;

            }
            if (canmove)
            {
                for (int i = 0; i < 4; ++i) {
                    positions[i].column -= 1;
                }
            }
            break;
        }
        case 'd': {
            for (int i = 0; i < 4; ++i) {
                if (board.mainBoard.board[positions[i].row][positions[i].column + 1] != ' ') canmove = false;

            }
            if (canmove)
            {
                for (int i = 0; i < 4; ++i) {
                    positions[i].column += 1;
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

    Piece::Piece(const std::vector<int>& vec) {
        for (int i = 0; i < 4; ++i) {
            Position pos;
            pos.column = vec[i * 2] + 4;
            pos.row = vec[i * 2 + 1];
            positions.push_back(pos);
        }
    }
    Piece::Piece() {
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
    void Piece::Rotate(std::vector<int> vec, int ID)
    {
        Position origin = positions[0];

        positions[0].column = vec[0] + origin.column;
        positions[0].row = vec[1] + origin.row;

        positions[1].column = vec[2] + origin.column;
        positions[1].row = vec[3] + origin.row;

        positions[2].column = vec[4] + origin.column;
        positions[2].row = vec[5] + origin.row;

        positions[3].column = vec[6] + origin.column;
        positions[3].row = vec[7] + origin.row;

        rotation = ID;
    }
}