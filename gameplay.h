#ifndef GAMEPLAY_H
#define GAMEPLAY_H

#include <string>
#include <vector>
#include <cstdio>

struct Move
{
    std::string player;
    std::vector<int> cells;
};

class Gameplay
{
private:
    std::vector<Move> moves;

public:
    Gameplay() : moves(2)
    {
        moves[0].player = "X";
        moves[1].player = "O";
    }

    bool victory(std::vector<std::string>, std::string &) const;
    void updateMoves(bool, int);
    void resetMoves();
    void printStatistics() const;
};

bool Gameplay::victory(std::vector<std::string> board, std::string &winner) const
{
    std::vector<std::vector<int>> winCoords = {
        {0, 1, 2},
        {3, 4, 5},
        {6, 7, 8},
        {0, 3, 6},
        {1, 4, 7},
        {2, 5, 8},
        {0, 4, 8},
        {2, 4, 6}};

    for (int i = 0; i < winCoords.size(); i++)
    {
        if (board[winCoords[i][0]] != "" && board[winCoords[i][0]] == board[winCoords[i][1]] && board[winCoords[i][1]] == board[winCoords[i][2]])
        {
            winner = board[winCoords[i][0]];
            return true;
        }
    }

    return false;
}

void Gameplay::updateMoves(bool isXNext, int cellNumber)
{
    if (isXNext)
        moves[0].cells.push_back(cellNumber);
    else
        moves[1].cells.push_back(cellNumber);
}

void Gameplay::resetMoves()
{
    for (Move &plMove : moves)
    {
        plMove.cells.clear();
    }
}

void Gameplay::printStatistics() const
{
    printf("\nPlayer | %-30s\n", "Moves");
    for (int i = 1; i <= 39; i++)
    {
        printf("=");
    }
    printf("\n%-6s | ", moves[0].player.c_str());
    for (int m : moves[0].cells)
    {
        printf(" %d ", m);
    }
    printf("\n");
    for (int i = 1; i <= 39; i++)
    {
        printf("-");
    }
    printf("\n%-6s | ", moves[1].player.c_str());
    for (int m : moves[1].cells)
    {
        printf(" %d ", m);
    }
    printf("\n\n");
}

#endif