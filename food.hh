#ifndef FOOD_HH
#define FOOD_HH

#include <stdlib.h>

class Food {
  private:
    int m_posX;
    int m_posY;

  public:
    Food(int, int);
    ~Food();
    int getPosX();
    int getPosY();
};
#endif // !FOOD_HH
