#include <iostream>
#include <cstdio>
using namespace std;

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

bool updateBoard(char board[3][3], bool isXNext, int* coords) {
    if (board[coords[0]][coords[1]]) {
        cout << "This square is already filled!\n";
        return false;
    }
    (isXNext) ?
        board[coords[0]][coords[1]] = 'X' :
        board[coords[0]][coords[1]] = 'O';

    return true;
}

void printBoard(char board[3][3], bool* isStart) {
    if (*isStart) {
        cout << " 1 | 2 | 3 \n";
        cout << "---|---|---\n";
        cout << " 4 | 5 | 6 \n";
        cout << "---|---|---\n";
        cout << " 7 | 8 | 9 \n";
        *isStart = false;
    } else {
        printf("\n");
        printf(" %c | %c | %c \n", board[0][0] ? board[0][0] : ' ', board[0][1] ? board[0][1] : ' ', board[0][2] ? board[0][2] : ' ');
        printf("---|---|---\n");
        printf(" %c | %c | %c \n", board[1][0] ? board[1][0] : ' ', board[1][1] ? board[1][1] : ' ', board[1][2] ? board[1][2] : ' ');
        printf("---|---|---\n");
        printf(" %c | %c | %c \n", board[2][0] ? board[2][0] : ' ', board[2][1] ? board[2][1] : ' ', board[2][2] ? board[2][2] : ' ');
    }
    cout << "\n";
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
    
    bool isStart = true;
    bool isXNext = true;
    char winner = '\0';
    int squareNumber;
    int coords[2];
    char board[3][3] = {
        {'\0', '\0', '\0'},
        {'\0', '\0', '\0'},
        {'\0', '\0', '\0'}
    };

    while (!checkWinner(board, &winner) && !allSquaresFilled(board)) {
        bool updateStatus = false;
        printBoard(board, &isStart);
        isXNext ? cout << "X's turn (enter square number): " : cout << "O's turn (enter square number): ";
        cin >> squareNumber;
        switch (squareNumber) {
            case 1:
            	coords[0] = 0;
            	coords[1] = 0;
                updateStatus = updateBoard(board, isXNext, coords);
                break;
            case 2:
                coords[0] = 0;
                coords[1] = 1;
          	updateStatus = updateBoard(board, isXNext, coords);
                break;
            case 3:
                coords[0] = 0;
            	coords[1] = 2;
                updateStatus = updateBoard(board, isXNext, coords);
                break;
            case 4:
                coords[0] = 1;
            	coords[1] = 0;
                updateStatus = updateBoard(board, isXNext, coords);
                break;
            case 5:
        	coords[0] = 1;
            	coords[1] = 1;
                updateStatus = updateBoard(board, isXNext, coords);
                break;
            case 6:
	        coords[0] = 1;
            	coords[1] = 2;
                updateStatus = updateBoard(board, isXNext, coords);
                break;
            case 7:
		coords[0] = 2;
            	coords[1] = 0;
                updateStatus = updateBoard(board, isXNext, coords);
                break;
            case 8:
        	coords[0] = 2;
            	coords[1] = 1;
                updateStatus = updateBoard(board, isXNext, coords);
                break;
            case 9:
	        coords[0] = 2;
            	coords[1] = 2;
                updateStatus = updateBoard(board, isXNext, coords);
                break;
            default:
                cout << "Invalid square number! Please try again\n";
        }
        
        if (updateStatus) {
             isXNext ? isXNext = false : isXNext = true;
        }
    }

    printBoard(board, &isStart);

    winner ? printf("Winner: %c\n", winner) : printf("It's a draw\n");

    return 0;
}
