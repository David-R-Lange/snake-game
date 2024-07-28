#include "snake.hh"

using namespace std;

Snake::Snake() {
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

int Snake::getPosX() {
  return this->m_posX;
}

int Snake::getPosY() {
  return this->m_posY;
}
