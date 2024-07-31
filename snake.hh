#ifndef SNAKE_HH
#define SNAKE_HH

#include <deque>
#include "pos.h"

class Snake{
  private:
    position m_headPos;
    size_t m_snakeSize;
    std::deque<position> m_body; // Data Structure to store the Snake Body in memory. m_body[0] == head, else tail

  public:
    Snake(void); // default constructor
    Snake(position, size_t);
    ~Snake();
    position getHeadPos();
    std::deque<position> getBody();
    size_t getLength();
    void move(int, bool);
};
#endif // !SNAKE_HH
