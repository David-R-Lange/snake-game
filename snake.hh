#include <vector> 

class Snake{
  private:
    std::size_t m_posX;
    std::size_t m_posY;
    std::size_t m_snakeSize;
    std::vector<std::size_t> m_snakeTailX;
    std::vector<std::size_t> m_snakeTailY;

  public:
    enum SnakeDirection { STOP = 0, LEFT, RIGHT, UP, DOWN };
    Snake(std::size_t x, std::size_t y, std::size_t len);
    ~Snake();
    void move(SnakeDirection);
    void grow();
    std::size_t getPosX();
    std::size_t getPosY();
    int getSnakeDirection();
};
