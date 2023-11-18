#include "Piece.h"

void Umbrella::Piece::move(char dir)
{
	switch (dir) {
	case 'l': {
		for (int i = 0; i < 4; i++)
		{
			positions[i].column -= 1;
		}
		break;
	}
	case 'r': {
		for (int i = 0; i < 4; i++)
		{
			positions[i].column += 1;
		}
		break;
	}
	}
}
