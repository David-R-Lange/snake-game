#include "snake.hh"

Snake::Snake() {
  position tmp (8, 8);
  m_snakeSize = 2;

  m_body.push_back(tmp);

  m_headPos = m_body[0];
}

Snake::Snake(position pos, size_t len) {
  m_headPos = pos;
  m_snakeSize = len;

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

std::deque<position> Snake::getBody() {
  return this->m_body;
}

void Snake::setBody(std::deque<position> bod) {
  this->m_body = bod;
}

size_t Snake::getLength() {
  return this->m_snakeSize;
}

void Snake::setLength(size_t size) {
  this->m_snakeSize = size;
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