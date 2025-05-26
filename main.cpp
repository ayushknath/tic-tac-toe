#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <sstream>
#include "headers/board.h"
#include "headers/gameplay.h"

int main()
{
    Board b;
    Gameplay gp;
    char repeatGame;
    bool firstGame = true;

    printf("\nTic Tac Toe\n");
    printf("===========\n\n");
    printf(" 1 | 2 | 3 \n");
    printf("---|---|---\n");
    printf(" 4 | 5 | 6 \n");
    printf("---|---|---\n");
    printf(" 7 | 8 | 9 \n\n");

    while (firstGame || repeatGame == 'y')
    {
        if (firstGame)
            firstGame = false;
        else
        {
            b.resetBoard();
            gp.resetMoves();
            std::cin.ignore();
        }

        int cellNumber;
        bool isXNext = true;
        std::string winner = "";

        while (!gp.victory(b.getBoard(), winner) && !b.allSquaresFilled())
        {
            if (isXNext)
                printf("X's turn (enter cell number): ");
            else
                printf("O's turn (enter cell number): ");

            std::string input;
            std::getline(std::cin, input);
            std::stringstream ss(input);
            ss >> cellNumber;
            if (ss.fail() || (cellNumber > 9 || cellNumber < 1))
            {
                printf("Invalid cell number! Please try again\n");
                continue;
            }

            bool isUpdated = b.updateBoard(isXNext, cellNumber);

            if (isUpdated)
            {
                b.printBoard();

                if (isXNext)
                {
                    gp.updateMoves(isXNext, cellNumber);
                    isXNext = false;
                }
                else
                {
                    gp.updateMoves(isXNext, cellNumber);
                    isXNext = true;
                }
            }
        }

        if (winner != "")
            printf("Winner: %s\n", winner.c_str());
        else
            printf("It\'s a draw\n");

        gp.printStatistics();

        printf("Would you like to play again? [y/n]: ");
        std::cin >> repeatGame;
        printf("\n");
    }

    return 0;
}
