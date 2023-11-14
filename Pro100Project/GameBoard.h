#pragma once
class GameBoard {
public:
	GameBoard() {
		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				board[i][j] = 'x';
			}
		}
	}
public:
	char board[10][10];
};