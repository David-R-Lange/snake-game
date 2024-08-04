#include "game.h"

Game::Game(char sSym, char fS, uint32_t dif) {
  m_snakeSymbol = sSym;
  m_foodSymbol = fS;
  m_difficulty = dif;
   m_lostFlag = false;
  m_score = 0;
  m_userInput = 0; 

  initGame();
  position tmp(m_colCount/2, m_rowCount/2);
  drawBoard();
  drawSnake();
  spawnFoodRand();
  printScore();
  m_snake = Snake (tmp);
  refresh();
  std::srand(time(NULL));
}

Game::~Game() {
  nodelay(stdscr, false);
  getch();
  curs_set(1);
  endwin();
} 

void Game::initGame() {
  initscr();
  cbreak();
  noecho();
  curs_set(0);
  getmaxyx(stdscr, m_rowCount, m_colCount);
  keypad(stdscr, true);
  position headStart (m_colCount/2, m_rowCount/2);
  m_snake.setHeadPos(headStart);
}

void Game::spawnFoodRand() {
  position tmp (rand()%m_colCount+1, rand()%m_rowCount+1);
  mvaddch(tmp.y, tmp.x, m_foodSymbol);
  m_food = tmp;
}

void Game::drawBoard() {
  // Drawing the top of the Board
  for(uint32_t i = 0; i < m_colCount; ++i) {
    mvaddch(0, i, '-');
  }

  // Drawing the bottom of the Board
  for(uint32_t i = 0; i < m_colCount; ++i) {
    mvaddch(m_rowCount-2, i, '-');
  }

  // Drawing the left side of the Board
  for(uint32_t i = 0; i < m_rowCount; ++i) {
    mvaddch(i, 0, '|');
  } 

  // Drawing the right side of the Board
  for(uint32_t i = 0; i < m_rowCount; ++i) {
    mvaddch(i, m_colCount-1, '|');
  }
}

void Game::drawSnake() {
  for(auto itr = m_snake.getBody().begin(); itr != m_snake.getBody().end(); ++itr) {
    mvaddch((*itr).y, (*itr).x, m_snakeSymbol);
  }
}

void Game::printScore() {
  move(m_rowCount-1, 0);
  printw("Score %d", m_score);
}

void Game::run() {  
  bool gotFood = false;
  while (!m_lostFlag) {
    m_userInput = getch();
    gotFood = checkForFood();
    this->m_snake.move(m_userInput, gotFood);
    m_lostFlag = checkForLoss();

    if(gotFood) {
      spawnFoodRand();
    }

    if(m_userInput == 'q') {
      m_lostFlag = true;
    }

    drawSnake();
    refresh();
    usleep(m_difficulty);
  }
  move(m_rowCount/2, m_colCount/2);
  printw("Game Over!");
}

bool Game::checkForFood() {
  if(this->m_food == this->m_snake.getHeadPos()) {
    return true;
  }
  return false;
}

bool Game::checkForLoss() {
  if(this->m_snake.getHeadPos().x == 0 || 
    this->m_snake.getHeadPos().x == m_rowCount-2 ||
    this->m_snake.getHeadPos().y == 0 || 
    this->m_snake.getHeadPos().y == m_colCount-1
    ) {
      return true;
    }
  return false;
}
