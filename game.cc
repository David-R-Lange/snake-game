#include "game.h"

Game::Game(Board& b, Snake& s, Food& f, char hS, char tS, char fS) {
  m_board = Board(b.getHeight(), b.getWidth());
  m_snake = Snake(s.getHeadPos(), s.getLength());
  m_food = Food(f.getPos());
  m_headSymbol = hS;
  m_tailSymbol = tS;
  m_foodSymbol = fS;
}

Game::~Game() = default;

position Game::spawnFoodRand() {
  position tmp (0, 0);

  return tmp;
}

void Game::updateBoard() {
  initscr();
  this->m_board.setOnBoard(this->m_snake.getHeadPos(), m_headSymbol);
  for(int i = 1; i < this->m_snake.getLength(); ++i) {
      this->m_board.setOnBoard(this->m_snake.getBody()[i], m_tailSymbol);
  }
  this->m_board.setOnBoard(this->m_food.getPos(), m_foodSymbol);
}

void Game::run() {  
  curs_set(0);
  this->updateBoard();
  bool lostFlag = false;
  int userInput = 0;

  while (!lostFlag) {
    userInput = getch();
    this->m_snake.move(userInput, checkForFood());
    refresh();
    lostFlag = checkForLoss();
  }
  endwin();
}

bool Game::checkForFood() {
  if(this->m_food.getPos() == this->m_snake.getHeadPos()) {
    return true;
  }
  return false;
}

bool Game::checkForLoss() {
  if(this->m_snake.getHeadPos().x == 0 || 
    this->m_snake.getHeadPos().x == this->m_board.getHeight() ||
    this->m_snake.getHeadPos().y == 0 || 
    this->m_snake.getHeadPos().y == this->m_board.getWidth()
    ) {
      return true;
    }
  return false;
}
