#include "food.hh"

using namespace std;

Food::Food(int x, int y) {
  m_posX = x;
  m_posY = y;
}

Food::~Food() = default;

int Food::getPosX() {
  return this->m_posX;
}

int Food::getPosY() {
  return this->m_posY;
}
