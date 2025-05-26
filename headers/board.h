#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include <string>
#include <cstdio>

class Board
{
private:
    std::vector<std::string> board;

public:
    Board() : board(9, "") {}

    bool updateBoard(bool, int);
    void resetBoard();
    void printBoard() const;
    bool allSquaresFilled() const;
    std::vector<std::string> getBoard() const { return board; }
};

bool Board::updateBoard(bool isXNext, int cellNumber)
{
    if (board[cellNumber - 1] != "")
    {
        printf("This cell is already filled!\n");
        return false;
    }

    if (isXNext)
        board[cellNumber - 1] = "X";
    else
        board[cellNumber - 1] = "O";

    return true;
}

void Board::resetBoard()
{
    for (std::string &cell : board)
    {
        cell = "";
    }
}

void Board::printBoard() const
{
    printf("\n");
    for (int i = 0; i < board.size(); i++)
    {
        if (i % 3 == 0 && i != 0)
        {
            printf("\n---|---|---\n");
        }

        if (board[i] != "")
            printf(" %s ", board[i].c_str());
        else
            printf("   ");

        if ((i + 1) % 3 != 0)
            printf("|");
    }
    printf("\n\n");
}

bool Board::allSquaresFilled() const
{
    for (int i = 0; i < board.size(); i++)
    {
        if (board[i] == "")
            return false;
    }
    return true;
}

#endif