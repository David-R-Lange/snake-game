#include "game.h"

int main() {
  uint32_t difficulty = 110;

  Game game('X', '*', difficulty);
  game.run();
}
