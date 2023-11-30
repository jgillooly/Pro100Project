#pragma once
#include "GameBoard.h"
#include <vector>
#include <random>

namespace Umbrella {
    class Game {
    public:
        std::vector<int> GetRandomPiece();

        std::vector<int> oBlock = { 0, 0, 0, 1, 1, 0, 1, 1 };

        std::vector<int> iBlock = { 0,0,0,1,0,2,0,3 };
        std::vector<int> iBlockR = { 0,0,1,0,2,0,3,0 };

        std::vector<int> sBlock = { 1,0,1,1,0,1,0,2 };
        std::vector<int> sBlockR = { 0,0,1,0,1,1,2,1 };

        std::vector<int> zBlock = { 0,0,0,1,1,1,1,2 };
        std::vector<int> zBlockR = { 2,0,1,0,1,1,0,1 };

        std::vector<int> tBlock = { 0,0,1,0,1,1,2,0 };
        std::vector<int> tBlockR = { 2,0,2,1,1,1,2,2 };

        std::vector<int> jBlock = { 0,0,1,0,2,0,2,1 };
        std::vector<int> jBlockR = { 0,2,0,1,0,2,0,2,1 };

        std::vector<int> lBlock = { 0,1,1,1,2,1,2,0 };
        std::vector<int> lBlockR = { 0,1,1,1,2,1,2,2 };
	};
}