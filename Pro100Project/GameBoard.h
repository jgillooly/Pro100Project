#pragma once
#include "Piece.h"
namespace Umbrella {
	class GameBoard {
	public:
		static const int COL_SIZE = 10;
		static const int ROW_SIZE = 10;
		struct Board {
			char board[10][10];
		};
		GameBoard() {
			for (int i = 0; i < 10; i++)
			{
				for (int j = 0; j < 10; j++)
				{
					mainBoard.board[i][j] = ' ';
				}
			}
		}
	public:
		void ClearLines();
		Board mainBoard;
		Board IncludePiece(Piece block);
		void PlacePiece(Piece block);

		bool CheckForLoss(Board board, Piece nextBlock);

	private:
		void ClearLine(int col);
	};
}