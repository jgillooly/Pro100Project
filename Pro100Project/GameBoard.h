#pragma once
namespace Umbrella {
	class GameBoard {
	public:
		GameBoard() {
			for (int i = 0; i < ROW_SIZE; i++)
			{
				for (int j = 0; j < COL_SIZE; j++)
				{
					board[i][j] = 'X';
				}
			}
		}
	public:
		const static int ROW_SIZE = 10;
		const static int COL_SIZE = 10;
		char board[ROW_SIZE][COL_SIZE]; /*= {	{'x','x','x','x','x','x','x','x','x','x'},
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
	private:
		void ClearLine(int col);
	};
}