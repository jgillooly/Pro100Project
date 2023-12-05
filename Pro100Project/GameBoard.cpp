#include "GameBoard.h"
#include <string>

namespace Umbrella {
	void GameBoard::ClearLines() {
		for (int i = 9; i >= 0; i--) {
			for (int j = 0; j < 10; j++) {
				if (mainBoard.board[i][j] != ' ') {
					if (j == 9) {
						ClearLine(i);
						i++;
					}
				}
				else break;
			}
		}
	}

	Umbrella::GameBoard::Board GameBoard::IncludePiece(Piece block) {
		GameBoard::Board newboard;

		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				newboard.board[i][j] = mainBoard.board[i][j];
			}
		}

		for (auto segment : block.getPositions()) {
			newboard.board[segment.row][segment.column] = '#';
		}
		return newboard;
	}

	bool GameBoard::CheckForLoss(Piece nextBlock)
	{
		for (int i = 0; i < ROW_SIZE; i++)
		{
			if (mainBoard.board[0][i] == ' ') continue;
			for (int j = 0; j < 4; j++)
			{
				if (nextBlock.positions[j].column == i)
				{
					return true;
				}

			}
		}
		return false;
	}

	void GameBoard::PlacePiece(Piece block)
	{
		block.drop(*this);
		for (int i = 0; i < 4; i++)
		{
			mainBoard.board[block.getPositions()[i].row][block.getPositions()[i].column] = 'X';
		}
	}

	void GameBoard::ClearLine(int col)
	{
		for (int i = col; i >= 1; i--) {
			for (int j = 0; j < 10; j++) {
				mainBoard.board[i][j] = mainBoard.board[i - 1][j];
			}
		}
		for (int i = 0; i < 10; i++) {
			mainBoard.board[0][i] = ' ';
		}
	}
}