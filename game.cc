#include "game.h"

Game::Game(Board& b, Snake& s, Food& f, char hS, char tS, char fS, int dif) {
  m_board = Board(b.getHeight(), b.getWidth());
  m_snake = Snake(s.getHeadPos(), s.getLength());
  m_food = Food(f.getPos());
  m_headSymbol = hS;
  m_tailSymbol = tS;
  m_foodSymbol = fS;
  m_difficulty = dif;
}

Game::~Game() = default;

position Game::spawnFoodRand() {
  position tmp (0, 0);

  return tmp;
}

void Game::updateBoard() {
  this->m_board.setOnBoard(this->m_snake.getHeadPos(), m_headSymbol);
  for(size_t i = 1; i < this->m_snake.getLength(); ++i) {
      this->m_board.setOnBoard(this->m_snake.getBody()[i], m_tailSymbol);
  }
  this->m_board.setOnBoard(this->m_food.getPos(), m_foodSymbol);
}

void Game::run() {  
  bool lostFlag = false;
  int userInput = 75;

  while (!lostFlag) {
    system("clear");
    this->m_board.showBoard();
    // userInput = getPlayerInput();
    this->m_snake.move(userInput, checkForFood());
    this->updateBoard();
    lostFlag = checkForLoss();
    sleep(m_difficulty);
  }
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
