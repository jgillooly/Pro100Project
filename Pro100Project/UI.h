#pragma once
#include "GameBoard.h"
#include <iostream>
#include "Piece.h"
#include "GameBoard.h"
namespace Umbrella {
	static class UI {
	public:
		static void DisplayBoard(GameBoard board, Piece block) {
			auto newBoard = board.IncludePiece(block);
			for (int i = 0; i < 10; i++)
			{
				std::cout << "|";
				for (int j = 0; j < 10; j++)
				{
					std::cout << ((newBoard.board[i][j] != ' ') ? '#' : ' ');
				}
				std::cout << "|" << std::endl;
			}
			std::cout << "----------------------" << std::endl;
		}
	};
}