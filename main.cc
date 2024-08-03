#include "game.h"

int main() {
  int snakeSize = 2;
  int difficulty = 1;
  
  position snakeStartingPosition ( 8, 8 );
  position foodStartingPosition (2, 4);

  Snake snake( snakeStartingPosition, snakeSize);
  Game game(snake, '0', '*', difficulty);
  game.run();
}
