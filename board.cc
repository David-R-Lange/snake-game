#include "board.hh"

using namespace std;

Board::Board(size_t size) {
  m_boardSize = size;
  vector<int> row(m_boardSize, 0);
  vector<vector<int>> m_board(m_boardSize, row);
}

Board::~Board() = default;

void Board::drawBoard(string playerName) {
  system("clear");

  for(size_t i = 0; i < this->m_board.size(); ++i) {
    for(size_t j = 0; j < this->m_board[i].size(); ++j) {
      cout << this->m_board[i][j];
    }
    cout << endl;
  }

}
