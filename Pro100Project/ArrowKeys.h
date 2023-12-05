#include "Piece.h"
#include "GameBoard.h"
#include "Game.h"
#include <conio.h>
#include <iostream>
using namespace std;

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77


namespace Umbrella {

    static bool Move(Piece& piece, GameBoard board, Game& game) {
        int c = 0;
           // c = 0;
            //Game game;
            std::vector<int> currentPiece = game.GetRandomPiece();
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
                piece.move('a', board);
                break;
            case KEY_RIGHT:
                piece.move('d', board);
                break;
            case 'c':
                if (game.canHold) {
                    // Hold the current piece
                    //game.HoldPiece(currentPiece);
                    int i = 1 + (rand() * (int)(7 - 1) / RAND_MAX);
                    piece.Reset(game.GetRandomPiece(i), i);
                    game.canHold = false;
                }
            }
        return false;
    }
}