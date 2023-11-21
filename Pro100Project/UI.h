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
			std::cout << "\n";
			std::string whitespace = "    ";
			for (int i = 0; i < 10; i++)
			{
				std::cout << whitespace <<"|";
				for (int j = 0; j < GameBoard::COL_SIZE; j++)
				{
					std::cout << ((newBoard.board[i][j] != ' ') ? newBoard.board[i][j] : ' ');
				}
				std::cout << "|" << std::endl;
			}
			std::cout << whitespace << "+----------+" << std::endl;
		}
	};
}