// Tic Tac Toe
#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

#define N 3
#define TOTAL_SQUARES 9

void greet();

int main() {
  srand((unsigned)time(NULL));

  int gameCount = 0;
  int countX = 0, countO = 0;
  int row, col;
  int npcRow, npcCol;
  int board[3][3] = {
    {0, 0, 0},
    {0, 0, 0},
    {0, 0, 0}
  };
  int winningCoordinates[8][3][2] = {
    {{0, 0}, {0, 1}, {0, 2}},
    {{1, 0}, {1, 1}, {1, 2}},
    {{2, 0}, {2, 1}, {2, 2}},
    {{0, 0}, {1, 0}, {2, 0}},
    {{0, 1}, {1, 1}, {2, 1}},
    {{0, 2}, {1, 2}, {2, 2}},
    {{0, 0}, {1, 1}, {2, 2}},
    {{0, 2}, {1, 1}, {2, 0}}
  };
  int remainingZeroes;
  
  greet();

  while(countX != 3 && countO != 3 && gameCount < 5) {
    // Human
    do {
      cout << "Enter coordinates: ";
      cin >> row >> col;
    } while(board[row][col] != 0);
    board[row][col] = 1;
    gameCount++;

    // Check remaining zeroes
    remainingZeroes = TOTAL_SQUARES - (gameCount * 2);
    
    // Computer
    if(remainingZeroes > 0) {
      npcRow = rand() % N;
      npcCol = rand() % N;
      while(board[npcRow][npcCol] != 0) {
        npcRow = rand() % N;
        npcCol = rand() % N;
      }
      board[npcRow][npcCol] = 2;
      cout << "Computer chose: " << npcRow << " " << npcCol << "\n";
    }

    // Display board
    for(int i = 0; i < 3; i++) {
      for(int j = 0; j < 3; j++) {
        if(board[i][j] == 1)
          cout << "X  ";
        else if(board[i][j] == 2)
          cout << "O  ";
        else
          cout << ".  ";
      }
      cout << "\n";
    }

    if(gameCount >= 3) {
      for(int i = 0; i < 8; i++) {
        for(int j = 0; j < 3; j++) {
          if(board[winningCoordinates[i][j][0]][winningCoordinates[i][j][1]] == 1)
            countX++;
          else if(board[winningCoordinates[i][j][0]][winningCoordinates[i][j][1]] == 2)
            countO++;
        }

        if(countX == 3 || countO == 3)
          break;
        else {
          countX = 0;
          countO = 0;
        }
      }
    }
  }

  if(countX == 3)
    cout << "Congrats! You won 🎉\n";
  else if(countO == 3)
    cout << "Computer won\n";
  else
    cout << "It's a tie! 😲\n";

  return 0;
}

void greet() {
  cout << "Welcome to Tic Tac Toe!\n\n";
  cout << "Observe the board layout below.\n"
  << "You have to enter the coordinates as presented in the layout.\n\n";

  cout << "       |       |       " << "\n";
  cout << " [0,0] | [0,1] | [0,2] " << "\n";
  cout << "_______|_______|_______" << "\n";
  cout << "       |       |       " << "\n";
  cout << " [1,0] | [1,1] | [1,2] " << "\n";
  cout << "_______|_______|_______" << "\n";
  cout << "       |       |       " << "\n";
  cout << " [2,0] | [2,1] | [2,2] " << "\n";
  cout << "       |       |       " << "\n\n";
}
