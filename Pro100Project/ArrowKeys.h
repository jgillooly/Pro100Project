#include "Piece.h"
#include "GameBoard.h"
#include <conio.h>
#include <iostream>
using namespace std;

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77


namespace Umbrella {

    static bool Move(Piece& piece, GameBoard board) {
        int c = 0;
            c = 0;

            switch ((c = _getch())) {
            case KEY_UP:
               //rotation
                break;
            case KEY_DOWN:
                piece.drop(board);
                break;
            case KEY_LEFT:
                piece.move('l');
                cout << "LEFT" << endl;
                break;
            case KEY_RIGHT:
                piece.move('r');
                break;
            }
        return false;
    }
}