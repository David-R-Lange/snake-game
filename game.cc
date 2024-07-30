#include "game.h"

Game::Game(Board& b, Snake& s, Food& f) {
  m_board = b;
  m_snake = s;
  m_food = f;
}

Game::~Game() = default;

void Game::updateBoard() {
  initscr();
  this->m_board.setOnBoard(this->m_snake.getHeadPos(), this->m_snake.getHeadSymbol());
  for(int i = 1; i < this->m_snake.getBody.size(); ++i) {
    this->m_board.setOnBoard(this->m_snake.getBody()[i], this->m_snake.getTailSymbol());
  }
  this->m_board.setOnBoard(this->m_food.getPos(), this->m_food.getSymbol());
}

void Game::run() {  
  this->updateBoard();
  bool lostFlag = false;
  m_snakeDirection userInput = 0;

  while (!lostFlag) {
    userInput = getch();
    this->m_snake.move(userInput, checkForFood());
    refresh();
    lostFlag = checkForLoss();
  }
  endwin();
}

bool checkForFood() {
  if(this->m_food.getPos == this->m_snake.getHeadPos) {
    return true;
  }
  return false;
}

bool checkForLoss() {
  if(this->m_snake.getHeadPos().x == 0 || 
    this->m_snake.getHeadPos().x == this->m_board.getHeight() ||
    this->m_snake.getHeadPos().y == 0 || 
    this->m_snake.getHeadPos().y == this->m_board.getWidth()
    ) {
      return true;
    }
  return false;
}
