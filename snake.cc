#include "snake.hh"

using namespace std;

Snake::Snake(size_t posX, size_t posY, size_t snakeSize) {
  m_posX = posX;
  m_posY = posY;
  m_snakeSize = snakeSize;
}

Snake::~Snake() = default;

void Snake::move(SnakeDirection dir) {
  switch (dir) {
    case LEFT:
      this->m_posX--;
      break;
    case RIGHT:
      this->m_posX++;
      break;
    case UP:
      this->m_posY--;
      break;
    case DOWN:
      this->m_posY++;
      break;
  }
}

void Snake::grow() {
  this->m_snakeSize++;
}

size_t Snake::getPosX() {
  return this->m_posX;
}

size_t Snake::getPosY() {
  return this->m_posY;
}
