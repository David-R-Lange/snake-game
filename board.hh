#include <vector>

class Board{
  private:
    int m_boardSize;
    std::vector<std::vector<char>> m_board;

  public:
    Board(int);
    ~Board();
    int getBoardSize();
    std::vector<std::vector<char>> getBoard();
    void setBoard(std::vector<std::vector<char>>&);
};
