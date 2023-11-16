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
		const static int ROW_SIZE = 10;
		const static int COL_SIZE = 10;
		char board[ROW_SIZE][COL_SIZE]; /*= {		{'x','x','x','x','x','x','x','x','x','x'},
												{'x','x','x','x','x','x','x','x','x','x'},
												{'x','x','x','x','x','x','x','x','x','x'},
												{'x','x','x','x','x','x','x','x','x','x'},
												{'x','x',' ','x','x','x','x','x','x','x'},
												{'x','x','x','x','x','x','x','x','x','x'},
												{'x','x','x','x','x','x','x','x','x','x'},
												{'x','x','x','x','x','x','x','x','x','x'},
												{'x',' ','x','x','x','x','x','x','x','x'},
												{' ','x','x','x','x','x','x','x','x','x'} };*/
		void ClearLines();
		Board mainBoard;
		Board IncludePiece(Piece block);


	private:
		void ClearLine(int col);
	};
}