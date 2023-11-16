#include "GameBoard.h"
#include <string>

namespace Umbrella {
	void GameBoard::ClearLines() {
		for (int i = ROW_SIZE - 1; i >= 0; i--) {
			for (int j = 0; j < COL_SIZE; j++) {
				if (board[i][j] != ' ') {
					if (j == 9) {
						ClearLine(i);
						i++;
					}
				}
				else break;
			}
		}
	}

	void GameBoard::ClearLine(int col)
	{
		for (int i = col; i > 0; i--) {
			for (int j = 0; j < COL_SIZE; j++) {
				board[i][j] = board[i - 1][j];
			}
		}
		for (int i = 0; i < COL_SIZE; i++) {
			board[0][i] = ' ';
		}
	}
}