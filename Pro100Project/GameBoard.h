#pragma once
#include "Piece.h"
namespace Umbrella {
	class GameBoard {
	public:
		struct Board {
			char board[10][10];
		};
		GameBoard() {
			for (int i = 0; i < ROW_SIZE; i++)
			{
				for (int j = 0; j < COL_SIZE; j++)
				{
					mainBoard.board[i][j] = ' ';
				}
			}
		}
	public:
		void ClearLines();
		Board mainBoard;
		Board IncludePiece(Piece block);


	private:
		void ClearLine(int col);
	};
}