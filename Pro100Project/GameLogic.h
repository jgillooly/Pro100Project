#pragma once

namespace umbrella {
	static class GameLogic {
	public:
		void static ClearLines(char* board[][10]);
	private:
		void static ClearLine(char* board[]);
	};
}