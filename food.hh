#ifndef SNAKEGAME_FOOD_HH
#define SNAKEGAME_FOOD_HH

#include "pos.h"

class Food {
  private:
    position m_pos;

  public:
    Food(void);
    Food(position );
    ~Food();
    position getPos();
    void setPos(position);
};
#endif // !SNAKE-GAME_FOOD_HH
