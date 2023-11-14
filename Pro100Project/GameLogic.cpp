#include "GameLogic.h"

namespace umbrella {
	void GameLogic::ClearLines(char* board[][10]) {
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				if (*board[i][j] != ' ') {
					if (j == 9) {
						ClearLine(board[i]);
						i--;
					}
				}
				else continue;
			}
		}
	}

	void GameLogic::ClearLine(char* board[])
	{
		for (int i = 0; i < 10; i++) {
			*board[i] = ' ';
		}
	}

	void dropRow(char* board[][10], int col)
	{
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {

			}
		}
	}
}