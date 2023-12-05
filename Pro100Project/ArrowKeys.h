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
            Game game;
            switch ((c = _getch())) {
            case KEY_UP:
            { //rotation
                int rotID = piece.rotation;
                if (rotID + 1 == game.allBlocks[game.PieceIDtoString(piece.pieceID)].size()) {
                    rotID = 0;
                }
                else {
                    rotID++;
                }
                piece.Rotate(board,game.allBlocks[game.PieceIDtoString(piece.pieceID)][rotID], rotID);
                break;
            }
            case KEY_DOWN:
                piece.drop(board);
                break;
            case KEY_LEFT:
                piece.move('l', board);
                break;
            case KEY_RIGHT:
                piece.move('r', board);
                break;
            }
        return false;
    }
}