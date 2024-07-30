#ifndef BOARD_HH
#define BOARD_HH

#include <vector>
#include "pos.h"

class Board{
  private:
    int m_height, m_width;
    char m_symbol;
    std::vector<std::vector<char>> m_board;

  public:
    Board(void); // default constructor
    Board(int&, int&, char);
    ~Board();
    int getHeight();
    int getWidth();
    char getSymbol();
    void setOnBoard(position, char);
    void showBoard();
    void clearBoard();
};
#endif // !BOARD_HH
