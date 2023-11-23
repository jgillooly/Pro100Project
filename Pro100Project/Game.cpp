#include "Game.h"

namespace Umbrella {
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
	}

	void Game::play() {
		bool quit = false;
		do {

		} while (!quit);
	}
}
