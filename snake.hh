#ifndef SNAKE_HH
#define SNAKE_HH

#include <vector> 

class Snake{
  private:
    char m_headSymbol;
    char m_tailSymbol;
    int m_headX;
    int m_headY;
    int m_snakeSize;
    std::vector<int> m_body; // Data Structure to store the Snake Body in memory. m_body[0] == head, else tail
    enum m_snakeDirection { STOP = 0, LEFT, RIGHT, UP, DOWN };
    m_snakeDirection dir;

  public:
    Snake(char, char, int, int, int);
    ~Snake();
    char getHeadSymbol();
    char getTailSymbol();
    int getHeadX();
    int getHeadY();
    void setSnakeOnBoard(Board&);
    void move(SnakeDirection);
    bool foundFood(Food&);
};
#endif // !SNAKE_HH
