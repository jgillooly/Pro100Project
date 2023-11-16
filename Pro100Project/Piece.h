#pragma once
namespace Umbrella {
	class Piece {
	public:
		struct Position {
			int row, column;
		};
	public:
		Position positions[4];
		void move(char dir);
	};
}