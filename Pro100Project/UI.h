#pragma once
#include "GameBoard.h"
#include <iostream>
namespace Umbrella {
	static class UI {
	public:
		static void DisplayBoard(char board[10][10]) {
			for (int i = 0; i < GameBoard::ROW_SIZE; i++)
			{
				std::cout << "|";
				for (int j = 0; j < GameBoard::COL_SIZE; j++)
				{
					std::cout << ((board[i][j] != ' ') ? '#' : ' ');
				}
				std::cout << "|" << std::endl;
			}
			std::cout << "----------------------" << std::endl;
		}
	};
}