#include "Game.h"

std::vector<int> Umbrella::Game::GetRandomPiece()
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
	return oBlock;
}

std::vector<int> Umbrella::Game::GetNextRotation(std::string piece, int current)
{
	return jBlock;
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


