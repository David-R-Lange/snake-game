#include "game.h"

Game::Game(Snake& s, char sSym, char fS, uint32_t dif) {
  initscr();
  cbreak();
  noecho();
  curs_set(0);
  m_snake = Snake(s.getHeadPos(), s.getLength());
  m_snakeSymbol = sSym;
  m_foodSymbol = fS;
  m_difficulty = dif;
}

Game::~Game() {
  curs_set(1);
  endwin();
} 

position Game::spawnFoodRand() {
  position tmp (0, 0);

  return tmp;
}

void Game::run() {  
  bool lostFlag = false;
  uint32_t userInput = 0;

  while (!lostFlag) {
    system("clear");
    // this->m_board.showBoard();
    userInput = getch();
    this->m_snake.move(userInput, checkForFood());
    lostFlag = checkForLoss();
    sleep(m_difficulty);
  }
}

bool Game::checkForFood() {
  if(this->m_food == this->m_snake.getHeadPos()) {
    return true;
  }
  return false;
}

bool Game::checkForLoss() {
  if(this->m_snake.getHeadPos().x == 0 || 
    //this->m_snake.getHeadPos().x == this->m_board.getHeight() ||
    this->m_snake.getHeadPos().y == 0 // || 
    //this->m_snake.getHeadPos().y == this->m_board.getWidth()
    ) {
      return true;
    }
  return false;
}
