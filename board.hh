#ifndef BOARD_HH
#define BOARD_HH

#include <vector>

class Board{
  private:
    int m_height, m_width;
    char m_symbol;
    std::vector<std::vector<char>> m_board;

  public:
    Board(int&, int&, char);
    ~Board();
    int getHeight();
    int getWidth();
    char getSymbol();
    void setOnBoard(int&, int&, char);
    void showBoard();
    void clearBoard();
};
#endif // !BOARD_HH
