#include "game.h"

int main() {
  int difficulty = 11000;
  

  Game game('X', '*', difficulty);
  game.run();
}
