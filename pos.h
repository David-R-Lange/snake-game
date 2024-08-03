#ifndef SNAKEGAME_POS_H
#define SNAKEGAME_POS_H

#include <cstdint>

typedef struct position{
  uint32_t x, y;
  position(){
    x = 0;
    y = 0;
  }
  position(uint32_t a, uint32_t b) {
    x = a;
    y = b;
  }
}position;

inline bool operator==(position pos1, position pos2) {
  return (pos1.x == pos2.x && pos1.y == pos2.y);
}

inline int operator+=(position pos1, position pos2) {
  return (pos1.x += pos2.x, pos1.y += pos2.y);
}
#endif // !SNAKE-GAME_POS_H
