#ifndef SNAKEGAME_FOOD_HH
#define SNAKEGAME_FOOD_HH

#include "pos.h"

class Food {
  private:
    char m_symbol;
    position m_pos;

  public:
    Food(void);
    Food(position , char);
    ~Food();
    char getSymbol();
    position getPos();
    void setPos(position);
};
#endif // !SNAKE-GAME_FOOD_HH
