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
    void Piece::move(char dir) {
        switch (dir) {
        case 'l': {
            for (int i = 0; i < 4; ++i) {
                positions[i].column -= 1;
            }
            break;
        }
        case 'r': {
            for (int i = 0; i < 4; ++i) {
                positions[i].column += 1;
            }
            break;
        }
        }
        moveDown();
    }

    bool Piece::canMoveDown(const GameBoard& board) const {
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
}