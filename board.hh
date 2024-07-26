#include <string>
#include <iostream>
#include "snake.hh"
#include "food.hh"

class Board{
  private:
    std::size_t m_boardSize;
    std::vector<std::vector<int>> m_board;

  public:
    Board(std::size_t);
    ~Board();
    void drawBoard(std::string);
};
