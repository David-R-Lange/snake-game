#include <chrono>
#include <thread>
#include <stdio.h>
#include "board.hh"
#include <string>


int main() {
  int boardHeight = 16;
  int boardWidth = 16;
  char boardCharacter = '*';
  int snakeSize = 1;

  std::string playerName = "David";

  Board board(boardHeight, boardWidth, boardCharacter);

  //Snake snake(boardSize * 0.5, boardSize * 0.5, snakeSize);
  //Food food(2, 4);

  bool isGameOver = false;

  board.showBoard();
}
