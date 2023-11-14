#include "GameBoard.h"
#include <string>

namespace Umbrella {
	void GameBoard::ClearLines() {
		for (int i = 9; i >= 0; i--) {
			for (int j = 0; j < 10; j++) {
				if (board[i][j] != ' ') {
					if (j == 9) {
						ClearLine(i);
						//i++;
					}
				}
				else break;
			}
		}
	}

	void GameBoard::ClearLine(int col)
	{
		for (int i = col; i > 1; i--) {
			for (int j = 0; j < 10; j++) {
				board[i][j] = board[i - 1][i];
			}
		}
		for (int i = 0; i < 10; i++) {
			board[0][i] = ' ';
		}
	}
}