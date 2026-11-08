#include <vector>
#include <iostream>
#include "game.h"

using namespace std;

/**
 * an implementation of John Conway's game of life in C++
 * done as an excersize in programming and as a study of emergent behavior
 */

// Dimensions of the game board
int generation;

// Create game board and the it's next state
vector<vector<bool>> board(width, vector<bool>(height, false));
vector<vector<bool>> board_next(width, vector<bool>(height, false));

/**
 * checks the surrounding 8 cells to see if they are alive or dead
 * this is the main game logic loop
 */
bool check_state (int x, int y, vector<vector<bool>> board) {
  int neighbors = 0;

  //check surrounding cells
  for(int i = (x - 1); i < (x + 2); i ++){
    for(int j = (y - 1); j < (y + 2); j++){
      //skip if looking at cell itself
      if(i == x && j == y){
        continue;
      } else if ((i < 0) || (i > width - 1)) {
        // prevent seg fault in X
      } else if ((j < 0) || (j > height - 1)) {
        // prevent seg fault in y
      } else if(board[i][j]){
        //increase count of neighbors
        neighbors ++;
      }
    }
  }

  //rules for the game
  if(board[x][y] && neighbors == 2){
    return true;
  } else if (neighbors == 3) {
    return true;
  }

  return false;
}

void step () {
  //update loop
  for(int i = 0; i < board.size(); i ++){
    for(int j = 0; j < board[i].size(); j++){
      cout<<board[i][j];
      board_next[i][j] = check_state(i, j, board);
    }
    cout<<endl;
  }

  //update the board
  board = board_next;
  generation ++;
  cout<<generation<<endl;
}