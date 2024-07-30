#include "board.hh"
#include <iostream>

Board::Board() {
  m_height = 16;
  m_width = 16;
  std::vector<std::vector<char>> tmp(m_height, std::vector<char> (m_width, ' '));
  for(int i = 0; i < m_height-1; ++i) {
    tmp.at(0).at(i) = '-';
    tmp.at(m_height-1).at(i) = '-';
  }
  for(int j = 0; j < m_width-1; ++j) {
    tmp.at(j).at(0) = '|';
    tmp.at(j).at(m_width-1) = '|';
  }
  m_board = tmp;
}

Board::Board(int height, int width) {
  m_height = height;
  m_width = width;
  std::vector<std::vector<char>> tmp(height, std::vector<char> (width, ' '));
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
  for(int i = 1; i < m_height-2; ++i) {
    for(int j = 1; j < m_width-2; ++j) {
      m_board[i][j] = ' ';
    }
  }
}
