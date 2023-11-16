#pragma once
#include "GameBoard.h"

namespace Umbrella {
	class Game {
    public:
        Piece oBlock = Piece(0,0,0,1,1,0,1,1);
        Piece iBlock = Piece(0,0,0,1,0,2,0,3);
        Piece sBlock = Piece(0,0,1,0,1,1,1,2);
        Piece zBlock = Piece(0,2,0,1,1,1,1,0);
        Piece tBlock = Piece(0,0,0,1,0,2,1,1);
        Piece jBlock = Piece(0,0,1,0,2,0,2,1);
        Piece lBlock = Piece(0,1,1,1,2,1,2,0);
	};
}