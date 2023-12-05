#include "Game.h"
#include "Piece.h"

namespace Umbrella
{
	std::vector<int> Game::GetRandomPiece()
	{
		int output = 1 + (rand() * (int)(7 - 1) / RAND_MAX);
		switch (output) {
		case 1:
			return oBlock;
		case 2:
			return iBlock;
		case 3:
			return sBlock;
		case 4:
			return zBlock;
		case 5:
			return tBlock;
		case 6:
			return jBlock;
		case 7:
			return lBlock;
		}
	}

	std::string Umbrella::Game::PieceIDtoString(int id)
	{
		switch (id) {
		default:
			return "oBlock";
		case 1:
			return "iBlock";
		case 2:
			return "sBlock";
		case 3:
			return "zBlock";
		case 4:
			return "tBlock";
		case 5:
			return "jBlock";
		case 6:
			return "lBlock";
		}
	}


	void Game::HoldPiece(std::vector<int>& currentPiece) {
		if (!heldPiece.empty()) {
			// Swap the current piece with the held piece
			std::swap(currentPiece, heldPiece);
		}
		else {
			// If there's no held piece, store the current piece in the held piece
			heldPiece = currentPiece;
		}
	}
}

