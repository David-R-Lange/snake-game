#include "snake.hh"

Snake::Snake() {
}

Snake::Snake(position pos) {
  m_headPos = pos;
  m_body.push_front(pos);

  m_headPos = m_body[0];
}

Snake::~Snake() = default;

position Snake::getHeadPos() {
  return this->m_headPos;
}

void Snake::setHeadPos(position pos) {
  this->m_headPos = pos;
}

std::deque<position>& Snake::getBody() {
  return this->m_body;
}

void Snake::move(int dir, bool eatFood) {

  position head_tmp(0,0);

  switch (dir) {
    case KEY_LEFT: // Left
      head_tmp.x = -1;
      break;
    case KEY_RIGHT: // Right
      head_tmp.x = 1;
      break;
    case KEY_UP: // Up
      head_tmp.y = -1;
      break;
    case KEY_DOWN: // Down
      head_tmp.y = 1;
      break;
    default:
      break;
  }
  
  m_headPos += head_tmp;
  m_body.push_front(m_headPos);

  if(!eatFood) {
    m_body.pop_back();
  }
  m_headPos = m_body[0];
}