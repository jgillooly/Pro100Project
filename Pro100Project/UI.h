#pragma once
#include <iostream>
namespace Umbrella {
	static class UI {
	public:
		static void DisplayBoard(char board[10][10]) {
			for (int i = 0; i < 10; i++)
			{
				for (int j = 0; j < 10; j++)
				{
					std::cout << board[i][j];
				}
				std::cout << std::endl;
			}
		}
	};
}