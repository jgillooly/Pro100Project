//// Pro100Project.cpp : This file contains the 'main' function. Program execution begins and ends there.
////
//
// main.cpp
#include <iostream>
//#include <experimental/filesystem>
#include <chrono>
#include <thread>
#include <conio.h>
#include <Windows.h>
#include "GameBoard.h"
#include "UI.h"
#include "Piece.h"
#include "Game.h"
#include "ArrowKeys.h"

using namespace Umbrella;
using namespace std::chrono;
using namespace std;

int main() {
    std::error_code ec;
    //std::experimental::filesystem::current_path("assets", ec);

    GameBoard board;
    Game game;
    Piece piece(game.oBlock);
    auto start = high_resolution_clock::now();
    
    UI::StartScreen();
    
    std::cout << "Press Enter to start the game...";
    std::cin.ignore(LLONG_MAX, '\n'); // Wait for Enter key

    //auto dropTimer = std::chrono::steady_clock::now();
    bool playing = true;

   // PlaySound(TEXT("Music.mp3"), NULL, SND_FILENAME | SND_ASYNC);
    while (playing) {
        system("cls");
        UI::DisplayBoard(board, piece);

        //get the current time
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<seconds>(stop - start);
  
        if (duration.count() >= 2) {
            start = high_resolution_clock::now();
            if (!piece.canDown(board))
            {
                board.PlacePiece(piece);
                piece.Reset(game.GetRandomPiece());
            }
            else {
                piece.moveDown();
            }
        }
        // Get user input
        //std::cout << "Enter movement direction (l/r/s/q): ";
        if (_kbhit()) {
            Umbrella::Move(piece, board);
        }


        //check if loss 
        if (board.CheckForLoss(piece))
        {
            playing = false;
            UI::EndScreen();
        }
        

        // Simulate a delay for a smoother experience (adjust as needed)
        std::this_thread::sleep_for(std::chrono::milliseconds(10));

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
