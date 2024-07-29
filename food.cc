#include "food.hh"

using namespace std;

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

