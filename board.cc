#include "board.hh"
#include <iostream>

Board::Board(int height, int width, char symbol) {
  m_height = height;
  m_width = width;
  m_symbol = symbol;
  std::vector<std::vector<char>> m_board(m_height, std::vector<char> (m_width, symbol));
}

Board::~Board() = default;

int Board::getHeight() {
  return this->m_height;
}

int Board::getWidth() {
  return this->m_width;
}

char Board::getSymbol() {
  return this->m_symbol;
}


void Board::setOnBoard(int x, int y, char input) {
  this->m_board[x][y] = input;
}

void Board::showBoard() {
  for(int i = 0; i < m_height; ++i) {
    for(int j = 0; j <= m_width; ++j) {
      std::cout << m_board[i][j] << " ";
    }
    std::cout << std::endl;
  }
}

void Board::clearBoard() {
  for(int i = 0; i < m_height; ++i) {
    for(int j = 0; j <= m_width; ++j) {

      if(j == 0 || j == m_width) {
        m_board[i][j] = '|';
      }

    }
  }
}
