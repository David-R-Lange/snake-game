#ifndef SNAKE-GAME_POS_H
#define SNAKE-GAME_POS_H

typedef struct position{
  int x, y;
  position(){}
  position(int a, int b):x(a),y(b){}
}position;

#endif // !SNAKE-GAME_POS_H
