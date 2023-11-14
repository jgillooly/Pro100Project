#pragma once
namespace Umbrella {
	class GameBoard {
	public:
		GameBoard() {
			for (int i = 0; i < 10; i++)
			{
				for (int j = 0; j < 10; j++)
				{
					board[i][j] = ' ';
				}
			}
		}
	public:
		char board[10][10];
		void ClearLines(char* board[][10]);
	private:
		void ClearLine(char* board[]);
		void DropRow(char* board[][10], int col);
	};
}