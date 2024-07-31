#include "board.hh"
#include "snake.hh"
#include "food.hh"
#include "game.h"
#include <iostream>

int main() {
  int boardHeight = 16;
  int boardWidth = 16;
  int snakeSize = 1;
  int difficulty = 1;
  
  position snakeStartingPosition ( 8, 8 );
  position foodStartingPosition (2, 4);

  std::string playerName = "David";

  Board board(boardHeight, boardWidth);
  Snake snake( snakeStartingPosition, snakeSize);
  Food food(foodStartingPosition);
  Game game(board, snake, food, '@', '0', '*', difficulty);

  game.run();
}
