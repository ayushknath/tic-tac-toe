#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

struct Move {
    char player;
    vector<int> cells;
};

vector<int> cellMapper(int cellNumber) {
    int cellMap[9][2] = {
        {0,0}, {0,1}, {0,2},
        {1,0}, {1,1}, {1,2},
        {2,0}, {2,1}, {2,2}
    };
    vector<int> mappedCoords = {
        *cellMap[cellNumber-1],
        *(cellMap[cellNumber-1] + 1)
    };
    return mappedCoords;
}

bool checkWinner(char board[3][3], char* winner) {
    int winCoords[8][3][2] = {
        {{0,0}, {1,1}, {2,2}},
        {{0,2}, {1,1}, {2,0}},
        {{0,0}, {0,1}, {0,2}},
        {{1,0}, {1,1}, {1,2}},
        {{2,0}, {2,1}, {2,2}},
        {{0,0}, {1,0}, {2,0}},
        {{0,1}, {1,1}, {2,1}},
        {{0,2}, {1,2}, {2,2}}
    };
    for (int i = 0; i < 8; i++) {
        if (board[winCoords[i][0][0]][winCoords[i][0][1]] == board[winCoords[i][1][0]][winCoords[i][1][1]] && board[winCoords[i][1][0]][winCoords[i][1][1]] == board[winCoords[i][2][0]][winCoords[i][2][1]] && board[winCoords[i][0][0]][winCoords[i][0][1]] != '\0') {
            *winner = board[winCoords[i][0][0]][winCoords[i][0][1]];
            return true;
        }
    }
    return false; 
}

bool updateBoard(char board[3][3], bool isXNext, vector<int> coords) {
    if (board[coords.at(0)][coords.at(1)]) {
        cout << "This cell is already filled!\n";
        return false;
    }
    (isXNext) ?
        board[coords.at(0)][coords.at(1)] = 'X' :
        board[coords.at(0)][coords.at(1)] = 'O';

    return true;
}

void printBoard(char board[3][3]) {
    printf("\n %c | %c | %c \n", board[0][0] ? board[0][0] : ' ', board[0][1] ? board[0][1] : ' ', board[0][2] ? board[0][2] : ' ');
    printf("---|---|---\n");
    printf(" %c | %c | %c \n", board[1][0] ? board[1][0] : ' ', board[1][1] ? board[1][1] : ' ', board[1][2] ? board[1][2] : ' ');
    printf("---|---|---\n");
    printf(" %c | %c | %c \n\n", board[2][0] ? board[2][0] : ' ', board[2][1] ? board[2][1] : ' ', board[2][2] ? board[2][2] : ' ');
}

void printStatistics(vector<Move> moves) {
    printf("\nPlayer | %-30s\n", "Moves");
    for (int i = 1; i<= 39; i++) {
        printf("=");
    }
    printf("\n%-6c | ", moves.at(0).player);
    for (int m : moves.at(0).cells) {
        printf(" %d ", m);
    }
    printf("\n");
    for (int i = 1; i <= 39; i++) {
        printf("-");
    }
    printf("\n%-6c | ", moves.at(1).player);
    for (int m : moves.at(1).cells) {
        printf(" %d ", m);
    }
    printf("\n");
}

bool allSquaresFilled(char board[3][3]) {
    for (int row = 0; row < 3; row++) {
        for (int cell = 0; cell < 3; cell++) {
            if (board[row][cell] == '\0')
                return false;
        }
    }
    return true;
}

int main() {
    cout << "Tic Tac Toe\n";
    cout << "===========\n\n";

    cout << " 1 | 2 | 3 \n";
    cout << "---|---|---\n";
    cout << " 4 | 5 | 6 \n";
    cout << "---|---|---\n";
    cout << " 7 | 8 | 9 \n\n";
 
    bool isXNext = true;
    bool isStart = true;
    char winner = '\0';
    int cellNumber;
    char board[3][3] = {
        {'\0', '\0', '\0'},
        {'\0', '\0', '\0'},
        {'\0', '\0', '\0'}
    };

    vector<Move> moveTracker = {
        {'X', {}},
        {'O', {}}
    };

    while (!checkWinner(board, &winner) && !allSquaresFilled(board)) {
        bool updateStatus = false;
        vector<int> coords;

        if (!isStart) {
            printBoard(board);
        } else {
            isStart = false;
        }

        isXNext ? cout << "X's turn (enter cell number): " : cout << "O's turn (enter cell number): ";
        cin >> cellNumber;

        if (cellNumber > 9 || cellNumber < 1) {
            cout << "Invalid cell number! Please try again\n";
            continue;
        }

        coords = cellMapper(cellNumber);

        updateStatus = updateBoard(board, isXNext, coords);
        
        if (updateStatus) {
            if (isXNext) {
                moveTracker.at(0).cells.push_back(cellNumber);
                isXNext = false;
            } else {
                moveTracker.at(1).cells.push_back(cellNumber);
                isXNext = true;
            }
        }
    }

    printBoard(board);

    winner ? printf("Winner: %c\n", winner) : printf("It's a draw\n");

    printStatistics(moveTracker);

    return 0;
}
