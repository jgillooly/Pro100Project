#pragma once
#include "GameBoard.h"
#include <vector>
#include <random>
#include <map>

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
        std::vector<int> tBlockR1 = { 2,0,2,1,1,1,2,2 };
        std::vector<int> tBlockR2 = { 2,2,1,2,0,2,1,1 };
        std::vector<int> tBlockR3 = { 0,0,0,1,0,2,1,1 };

        std::vector<int> jBlock = { 0,0,1,0,2,0,2,1 };
        std::vector<int> jBlockR1 = { 2,0,2,1,2,2,1,2 };
        std::vector<int> jBlockR2 = { 2,2,1,2,0,2,0,1 };
        std::vector<int> jBlockR3 = { 0,2,0,1,0,0,1,0 };


        std::vector<int> lBlock = { 0,1,1,1,2,1,2,0 };
        std::vector<int> lBlockR = { 0,1,1,1,2,1,2,2 };

        std::vector<std::vector<int>> oBlocks;
        std::vector<std::vector<int>> iBlocks;
        std::vector<std::vector<int>> sBlocks;
        std::vector<std::vector<int>> zBlocks;
        std::vector<std::vector<int>> tBlocks;
        std::vector<std::vector<int>> jBlocks;
        std::vector<std::vector<int>> lBlocks;

        std::map<std::string, std::vector<std::vector<int>>> allBlocks;

        std::vector<int> GetNextRotation(std::string piece, int current);
        std::string PieceIDtoString(int id);

        Game() {
            oBlocks.push_back(oBlock);
            
            iBlocks.push_back(iBlock);
            iBlocks.push_back(iBlockR);

            sBlocks.push_back(sBlock);
            sBlocks.push_back(sBlockR);

            zBlocks.push_back(zBlock);
            zBlocks.push_back(zBlockR);

            tBlocks.push_back(tBlock);
            tBlocks.push_back(tBlockR1);
            tBlocks.push_back(tBlockR2);
            tBlocks.push_back(tBlockR3);

            jBlocks.push_back(jBlock);
            jBlocks.push_back(jBlockR1);
            jBlocks.push_back(jBlockR2);
            jBlocks.push_back(jBlockR3);

            lBlocks.push_back(lBlock);
           // lBlocks.push_back(lBlockR1);
           // lBlocks.push_back(lBlockR2);
           // lBlocks.push_back(lBlockR3);

            allBlocks["oBlock"] = oBlocks;
            allBlocks["iBlock"] = iBlocks;
            allBlocks["sBlock"] = sBlocks;
            allBlocks["zBlock"] = zBlocks;
            allBlocks["tBlock"] = tBlocks;
            allBlocks["jBlock"] = jBlocks;
            allBlocks["lBlock"] = lBlocks;
        }
	};
}