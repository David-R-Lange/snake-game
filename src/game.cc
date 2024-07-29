#include "game.h"
#include <stdlib.h>

Game::Game(Board& b, Snake& s, Food& f) {
  m_board = b;
  m_snake = s;
  m_food = f;
}

Game::~Game() = default;

void Game::initBoard() {
  system("clear");
  b.setOnBoard(m_snake.getHeadPos(), m_snake.getHeadSymbol());
  for(int i = 1; i < m_snake.getBody.size(); ++i) {
    b.setOnBoard(m_snake.getBody()[i], m_snake.getTailSymbol());
  }
  b.setOnBoard(m_food.getPos(), m_food.getSymbol());
}

void Game::run() {

}

bool checkForFood() {
  if(m_food.getPos == m_snake.getHeadPos) {
    return true;
  }
  return false;
}

bool checkForLoss() {
}
