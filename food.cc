#include "food.hh"

using namespace std;

Food::Food(size_t x, size_t y) {
  m_posX = x;
  m_posY = y;
}

Food::~Food() = default;

size_t Food::getPosX() {
  return this->m_posX;
}

size_t Food::getPosY() {
  return this->m_posY;
}
