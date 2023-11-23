//// Pro100Project.cpp : This file contains the 'main' function. Program execution begins and ends there.
////
//
// main.cpp
#include <iostream>
#include <chrono>
#include <thread>
#include "GameBoard.h"
#include "UI.h"
#include "Piece.h"
#include "Game.h"

using namespace Umbrella;
using namespace std::chrono;
using namespace std;

int main() {
    GameBoard board;
    Game game;
    Piece piece(game.oBlock);
    auto start = high_resolution_clock::now();
    

    char userInput;
    UI::StartScreen();
    
    while (true) {
        
        UI::DisplayBoard(board, piece);

        //get the current time
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<seconds>(stop - start);
        cout << duration.count() << endl;

        if (duration.count() >= 3) {
            start = high_resolution_clock::now();
            piece.moveDown();
        }
        // Get user input
        std::cout << "Enter movement direction (l/r/s/q): ";
        std::cin >> userInput;

        // Handle user input
        if (userInput == 'q') {
            break;  // Quit the loop if the user enters 'q'
        }
        else if (userInput == 'l' || userInput == 'r') {
            // Move the piece left or right based on user input
            piece.move(userInput);
        }
        //else if (userInput == 's') {
        //    piece.drop(board);
        //}
        else if (userInput == 's') {
            board.PlacePiece(piece);
            piece.Reset(game.GetRandomPiece());
        }

        // Simulate a delay for a smoother experience (adjust as needed)
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
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
