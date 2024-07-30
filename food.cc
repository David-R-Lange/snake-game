#include "food.hh"

Food::Food() {
  m_pos (2, 4);
  m_symbol = '*';
}


Food::Food(position pos, char s) {
  m_pos = pos;
  m_symbol = s;
}

Food::~Food() = default;

char Food::getSymbol() {
  return this->m_symbol;
}

int Food::getPos() {
  return this->m_pos;
}

void Food::setPos(position pos) {
  m_pos = pos;
}

