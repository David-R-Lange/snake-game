#include "snake.hh"

Snake::Snake() {
}

Snake::Snake(position pos) {
  this->m_headPos = pos;
  this->m_body.push_front(pos);

  this->m_headPos = this->m_body[0];
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
    case 97: // a
    case 65: // A
    case KEY_LEFT:
      head_tmp.x = -1;
      break;
    case 100: // d
    case 68: // D
    case KEY_RIGHT:
      head_tmp.x = 1;
      break;
    case 119: // w
    case 87: // W
    case KEY_UP:
      head_tmp.y = -1;
      break;
    case 115: // s
    case 83: // S
    case KEY_DOWN:
      head_tmp.y = 1;
      break;
    default:
      break;
  }
  
  position new_head(0,0);
  new_head.x = m_body[0].x + head_tmp.x;
  new_head.y = m_body[0].y + head_tmp.y;
  this->m_body.push_front(new_head);

  if(!eatFood) {
    this->m_body.pop_back();
  }
  this->m_headPos = this->m_body[0];
}