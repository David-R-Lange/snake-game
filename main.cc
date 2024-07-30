#include "board.hh"
#include "snake.hh"
#include "food.hh"
#include "game.h"
#include <string>


int main() {
  int boardHeight = 16;
  int boardWidth = 16;
  char boardCharacter = ' ';
  int snakeSize = 1;
  char snakeHead = '@';
  char snakeBody = '0';
  position snakeStartingPosition ( 8, 8 );
  char foodSymbol = '*';
  position foodStartingPosition (2, 4);

  std::string playerName = "David";

  Board board(boardHeight, boardWidth, boardCharacter);
  Snake snake( snakeHead, snakeBody, snakeStartingPosition, snakeSize);
  Food food(foodStartingPosition, foodSymbol);

  Game game(board, snake, food);

  game.run();
}
