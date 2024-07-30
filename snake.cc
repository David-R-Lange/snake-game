#include "snake.hh"

Snake::Snake() {
  m_headSymbol = '@';
  m_tailSymbol = '0';
  m_headPos (8, 8);
  m_snakeSize = 2;

  position tmp(m_headPos.x+1, m_headPos.y+1);

  m_body.push_back(tmp);

  m_headPos = m_body[0];
}
Snake::Snake(char head, char tail, position pos, int len) {
  m_headSymbol = head;
  m_tailSymbol = tail;
  m_headPos = pos;
  m_snakeSize = len;

  position tmp(pos.x+1, pos.y+1);

  m_body.push_back(tmp);

  m_headPos = m_body[0];
}

Snake::~Snake() = default;

char Snake::getHeadSymbol() {
  return this->m_headSymbol;
}

char Snake::getTailSymbol() {
  return this->m_tailSymbol;
}

position Snake::getHeadPos() {
  return this->m_headPos;
}

std::vector<position> Snake::getBody() {
  return this->m_body;
}

void Snake::move(m_snakeDirection dir, bool eatFood) {

  position head_tmp(0,0);

  switch (dir) {
    case LEFT:
      this->head_tmp.x = -1;
      break;
    case RIGHT:
      this->head_tmp.x = 1;
      break;
    case UP:
      this->head_tmp.y = -1;
      break;
    case DOWN:
      this->head_tmp.y = 1;
      break;
    default:
      break;
  }
  
  // update the snake head info
  position head(0,0);

  head.x = body[0].x + head_tmp.x;
  head.y = body[0].y + head_tmp.y;

  // update the rest of the snakes body
  for(int i = m_snakeSize-1; i > 0; --i) {
    body[i] = body[i-1];
  }
  m_headPos = head;
  body[0] = head;
}