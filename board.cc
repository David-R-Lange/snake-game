#include "board.hh"

using namespace std;

Board::Board(int size) {
  m_boardSize = size;
  vector<int> row(m_boardSize, 0);
  vector<vector<char>> m_board(m_boardSize, row);
}

Board::~Board() = default;

int Board::getBoardSize() {
  return this->m_boardSize;
}

vector<vector<char>> Board::getBoard() {
  return this->m_board;
}

void Board::setBoard(vector<vector<char>> &board) {
  this->m_board = board;
}
}
