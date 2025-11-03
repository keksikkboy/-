#include <iostream>
#include <windows.h>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

const int WIDTH = 1200;   
const int HEIGHT = 400;  
const int SPEED = 5;    

void setCursorPosition(int x, int y) {
 
    if (x < 0) x = 0;
    if (y < 0) y = 0;
    if (x >= WIDTH) x = WIDTH - 1;
    if (y >= HEIGHT) y = HEIGHT - 1;

    COORD coord = { (SHORT)x, (SHORT)y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void setConsoleColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

int main() {
    srand((unsigned)time(0));
    system("cls");
 
    SetConsoleTitleA("Matrix Hacker Mode");

    vector<int> yPositions(WIDTH, 0);

    while (true) {
        for (int i = 0; i < WIDTH; i++) {
            int randChar = 33 + rand() % 94; 
            setConsoleColor(10); 
            setCursorPosition(i, yPositions[i]);
            cout << (char)randChar;

            if (yPositions[i] < HEIGHT - 1) yPositions[i]++;
            else if (rand() % 100 > 97) yPositions[i] = 0;
        }

        Sleep(SPEED);
    }

    return 0;
}
