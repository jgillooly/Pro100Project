// Pro100Project.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "GameBoard.h"
#include "UI.h"
#include "Piece.h"

using namespace Umbrella;

    int main()
    {
        GameBoard board;
        
        //board.ClearLines();
        //UI::DisplayBoard(board);

        Piece piece;
        piece.positions[0].column = 0;
        piece.positions[0].row = 0;

        piece.positions[1].column = 0;
        piece.positions[1].row = 1;

        piece.positions[2].column = 1;
        piece.positions[2].row = 0;

        piece.positions[3].column = 1;
        piece.positions[3].row = 1;

        UI::DisplayBoard(board, piece);

        piece.move('r');

        UI::DisplayBoard(board, piece);

        piece.move('l');

        UI::DisplayBoard(board, piece);

        return 0;
    }

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
