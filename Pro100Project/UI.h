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
					std::cout << ((newBoard.board[i][j] != ' ') ? '#' : ' ');
				}
				std::cout << "|" << std::endl;
			}
			std::cout << whitespace << "+----------+" << std::endl;
		}

		static void StartScreen()
		{
			std::cout << " .----------------.  .----------------.  .----------------.  .----------------.  .----------------.  .----------------." << std::endl;
			std::cout << " | .--------------. || .--------------. || .--------------. || .--------------. || .--------------. || .--------------.|\n" << std::endl;
			std::cout << " | |  _________   | || |  _________   | || |  _________   | || |  _______     | || |     _____    | || |    _______   | |" << std::endl;
			std::cout << " | | |  _   _  |  | || | |_   ___  |  | || | |  _   _  |  | || | |_   __ \\    | || |    |_   _|   | || |   /  ___  |  | |" << std::endl;
			std::cout << " | | |_/ | | \\_|  | || |   | |_  \\_|  | || | |_/ | | \\_|  | || |   | |__) |   | || |      | |     | || |  |  (__ \\_|  | |" << std::endl;
			std::cout << " | |     | |      | || |   |  _ | _   | || |     | |      | || |   |  __ /    | || |      | |     | || |   '.___`-.   | |" << std::endl;
			std::cout << " | |    _| |_     | || |  _| |___/ |  | || |    _| |_     | || |  _| |  \\ \\_  | || |     _| |_    | || |  |`\\____) |  | |" << std::endl;
			std::cout << " | |   |_____|    | || | |_________|  | || |   |_____|    | || | |____| |___| | || |    |_____|   | || |  |_______.'  | |" << std::endl;
			std::cout << " | |              | || |              | || |              | || |              | || |              | || |              | |" << std::endl;
			std::cout << " | '--------------' || '--------------' || '--------------' || '--------------' || '--------------' || '--------------' |" << std::endl;
			std::cout << " '----------------'  '----------------'  '----------------'  '----------------'  '----------------'  '----------------' " << std::endl;
		
		}
	};
}