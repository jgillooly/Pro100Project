#include "GameBoard.h"
#include <string>

namespace Umbrella {
	void GameBoard::ClearLines() {
		for (int i = COL_SIZE - 1; i >= 0; i--) {
			for (int j = 0; j < ROW_SIZE; j++) {
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

		for (int i = 0; i < COL_SIZE; i++)
		{
			for (int j = 0; j < ROW_SIZE; j++)
			{
				newboard.board[i][j] = mainBoard.board[i][j];
			}
		}

		for (auto segment : block.positions) {
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
			mainBoard.board[block.positions[i].row][block.positions[i].column] = 'X';
			mainBoard.colors[block.positions[i].row][block.positions[i].column] = block.color;
		}
	}

	void GameBoard::ClearLine(int col)
	{
		for (int i = col; i >= 1; i--) {
			for (int j = 0; j < ROW_SIZE; j++) {
				mainBoard.board[i][j] = mainBoard.board[i - 1][j];
			}
		}
		for (int i = 0; i < ROW_SIZE; i++) {
			mainBoard.board[0][i] = ' ';
		}
	}
}