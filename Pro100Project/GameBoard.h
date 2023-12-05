#pragma once
#include "Piece.h"
#include <string>
namespace Umbrella {
	class GameBoard {
	public:
		static const int COL_SIZE = 10;
		static const int ROW_SIZE = 10;
		struct Board {
			char board[COL_SIZE][ROW_SIZE];
			std::string colors[COL_SIZE][ROW_SIZE];
		};
		GameBoard() {
			for (int i = 0; i < COL_SIZE; i++)
			{
				for (int j = 0; j < ROW_SIZE; j++)
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

		bool CheckForLoss(Piece nextBlock);

	private:
		void ClearLine(int col);
	};
}