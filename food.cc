#include "food.hh"

Food::Food() {
  position tmp (2, 4);
  m_pos = tmp;
}


Food::Food(position pos) {
  m_pos = pos;
}

Food::~Food() = default;

position Food::getPos() {
  return this->m_pos;
}

void Food::setPos(position pos) {
  m_pos = pos;
}

