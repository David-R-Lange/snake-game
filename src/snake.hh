#ifndef SNAKE_HH
#define SNAKE_HH

#include <vector> 
#include "pos.h"

class Snake{
  private:
    char m_headSymbol;
    char m_tailSymbol;
    position m_headPos;
    int m_snakeSize;
    std::vector<position> m_body; // Data Structure to store the Snake Body in memory. m_body[0] == head, else tail
    enum m_snakeDirection { STOP = 0, LEFT, RIGHT, UP, DOWN };
    m_snakeDirection dir;

  public:
    Snake(char, char, position, int);
    ~Snake();
    char getHeadSymbol();
    char getTailSymbol();
    position getHeadPos();
    std::vector<position> getBody;
    void move(m_snakeDirection);
};
#endif // !SNAKE_HH
