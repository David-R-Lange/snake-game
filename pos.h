#ifndef SNAKEGAME_POS_H
#define SNAKEGAME_POS_H

typedef struct position{
  int x, y;
  position(){}
  position(int a, int b):x(a),y(b){}
}position;

inline bool operator==(position pos1, position pos2) {
  return (pos1.x == pos2.x && pos1.y == pos2.y);
}

inline int operator+=(position pos1, position pos2) {
  return (pos1.x += pos2.x, pos1.y += pos2.y);
}
#endif // !SNAKE-GAME_POS_H
