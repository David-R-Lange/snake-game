#include "board.hh"
#include <iostream>

Board::Board(int& height, int& width, char symbol) {
  m_height = height;
  m_width = width;
  m_symbol = symbol;
  std::vector<std::vector<char>> tmp(height, std::vector<char> (width, symbol));
  for(int i = 0; i < height-1; ++i) {
    tmp.at(0).at(i) = '-';
    tmp.at(height-1).at(i) = '-';
  }
  for(int j = 0; j < width-1; ++j) {
    tmp.at(j).at(0) = '|';
    tmp.at(j).at(width-1) = '|';
  }
  m_board = tmp;
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


void Board::setOnBoard(position pos, char input) {
  this->m_board[pos.x][pos.y] = input;
}

void Board::showBoard() {
  for(int i = 0; i < m_height; ++i) {
    for(int j = 0; j < m_width; ++j) {
      std::cout << m_board[i][j] << " ";
    }
    std::cout << std::endl;
  }
}

void Board::clearBoard() {
  for(int i = 1; i < m_height-1; ++i) {
    for(int j = 1; j < m_width-1; ++j) {

      if(j == 0 || j == m_width) {
        m_board.at(i).at(j) = '|';
      }

    }
  }
}
