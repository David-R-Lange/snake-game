#include "game.h"

int main() {
  uint32_t difficulty = 111110;

  Game game('X', '*', difficulty);
  game.run();
}
