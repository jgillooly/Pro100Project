#include <conio.h>
#include <iostream>
using namespace std;

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77


namespace Umbrella {

    static int Move() {
        int c = 0;
        while (1)
        {
            c = 0;

            switch ((c = _getch())) {
            case KEY_UP:
                cout << endl << "Up" << endl; // Rotation
                break;
            case KEY_DOWN:
                cout << endl << "Down" << endl; // Go Down
                break;
            case KEY_LEFT:
                cout << endl << "Left" << endl; //  Go Left
                break;
            case KEY_RIGHT:
                cout << endl << "Right" << endl; // Go Right
                break;
            }
        }
        return 0;
    }
}