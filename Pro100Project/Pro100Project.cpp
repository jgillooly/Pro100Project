//// Pro100Project.cpp : This file contains the 'main' function. Program execution begins and ends there.
////
//
// main.cpp
#include <iostream>
#include <chrono>
#include <thread>
#include <conio.h>
#include <random>
#include <Windows.h>
#include <mmsystem.h>
#include "GameBoard.h"
#include "UI.h"
#include "Piece.h"
#include "Game.h"
#include <conio.h>

using namespace Umbrella;

int main() {
    GameBoard board;
    Game game;
    Game games;
    Piece piece(game.oBlock);

    char userInput;
    UI::StartScreen();

    // Prompt the user to start the game
    std::cout << "Press Enter to start the game...";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Wait for Enter key

    // Set up a timer for dropping the piece every second
    auto dropTimer = std::chrono::steady_clock::now();
    constexpr auto dropInterval = std::chrono::milliseconds(500);
    std::vector<int> currentPiece = game.GetRandomPiece();

    PlaySound(TEXT("Music.wav"), NULL, SND_FILENAME | SND_ASYNC);
    while (playing) {
        system("cls");
        UI::DisplayBoard(board, piece);

        // Get user input without blocking
        if (_kbhit()) {
            userInput = _getch();

            // Handle user input
            if (userInput == 'q') {
                break;  // Quit the loop if the user enters 'q'
            }
            else if (userInput == 'a' || userInput == 'd') {
                // Move the piece left or right based on user input
                piece.move(userInput);
            }
            else if (userInput == 's') {
                // Drop the piece one position down
                if (piece.canDown(board)) {
                    piece.drop(board);
                }
                else {
                    // If the piece cannot move down, place it on the board and reset
                    board.PlacePiece(piece);
                    piece.Reset(game.GetRandomPiece());
                }
            }
            else if (userInput == 'h' && game.canHold) {
                // Hold the current piece
                game.HoldPiece(currentPiece);
                piece.Reset(game.GetRandomPiece());
                game.canHold = false;
            }

            if (!game.canHold)
            {
                //std::swap(currentPiece, );
            }
        }

        // Check if it's time to drop the piece
        auto now = std::chrono::steady_clock::now();
        if (now - dropTimer >= dropInterval) {
            // Move the piece down if possible
            if (piece.canDown(board)) {
                if (!piece.canDown(board))
                {
                    board.PlacePiece(piece);
                    piece.Reset(game.GetRandomPiece());
                }
                else
                {
                    piece.moveDown();
                }
            }
            else {
                // If the piece cannot move down, place it on the board and reset
                board.PlacePiece(piece);
                game.canHold = true;
                piece.Reset(game.GetRandomPiece());
            }
            // Update the drop timer
            dropTimer = now;
        }

        // Simulate a delay for a smoother experience (adjust as needed)
        std::this_thread::sleep_for(std::chrono::milliseconds(1));


        // Clear completed lines on the board
        board.ClearLines();
    }

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
