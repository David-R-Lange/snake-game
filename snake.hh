#ifndef SNAKE_HH
#define SNAKE_HH

#include <deque>
#include "pos.h"

class Snake{
  private:
    position m_headPos;
    int m_snakeSize;
    std::deque<position> m_body; // Data Structure to store the Snake Body in memory. m_body[0] == head, else tail

  public:
    Snake(void); // default constructor
    Snake(position, int);
    ~Snake();
    position getHeadPos();
    std::deque<position> getBody();
    int getLength();
    void move(int, bool);
};
#endif // !SNAKE_HH
