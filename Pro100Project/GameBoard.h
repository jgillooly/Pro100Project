#pragma once
namespace Umbrella {
	class GameBoard {
	public:
		GameBoard() {
			for (int i = 0; i < 10; i++)
			{
				for (int j = 0; j < 10; j++)
				{
					board[i][j] = 'X';
				}
			}
		}
	public:
		char board[10][10]; /*= {	{'x','x','x','x','x','x','x','x','x','x'},
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