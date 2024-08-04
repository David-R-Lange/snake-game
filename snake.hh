#ifndef SNAKE_HH
#define SNAKE_HH

#include <deque>
#include "pos.h"
#include <ncurses.h>

class Snake{
  private:
    position m_headPos;
    std::deque<position> m_body; // Data Structure to store the Snake Body in memory. m_body[0] == head, else tail

  public:
    Snake(void); // default constructor
    Snake(position);
    ~Snake();
    position getHeadPos();
    void setHeadPos(position);
    std::deque<position>& getBody();
    void move(int, bool);
};
#endif // !SNAKE_HH
