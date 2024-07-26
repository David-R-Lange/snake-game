#include <stdlib.h>

class Food {
  private:
    size_t m_posX;
    size_t m_posY;

  public:
    Food(size_t, size_t);
    ~Food();
    size_t getPosX();
    size_t getPosY();
};
