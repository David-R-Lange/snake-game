#include "game.h"

Game::Game(char sSym, char fS, uint32_t dif) {
  this->m_snakeSymbol = sSym;
  this->m_foodSymbol = fS;
  this->m_difficulty = dif;
  this->m_score = 0;

  initGame();
  drawBoard();
  drawSnake();
  spawnFoodRand();
  printScore();
  refresh();
  std::srand(time(NULL));
}

Game::~Game() {
  getch();
  curs_set(1);
  endwin();
} 

void Game::initGame() {
  initscr();
  cbreak();
  noecho();
  curs_set(0);
  getmaxyx(stdscr, this->m_rowCount, this->m_colCount);
  keypad(stdscr, true);
  position headStart (this->m_colCount/2, this->m_rowCount/2);
  m_snake = Snake(headStart); 
}

void Game::spawnFoodRand() {
  position tmp (rand()%this->m_colCount+1, rand()%this->m_rowCount+1);
  mvaddch(tmp.y, tmp.x, this->m_foodSymbol);
  this->m_food = tmp;
}

void Game::drawBoard() {
  // Drawing the top of the Board
  for(uint32_t i = 0; i < this->m_colCount; ++i) {
    mvaddch(0, i, '-');
  }

  // Drawing the bottom of the Board
  for(uint32_t i = 0; i < this->m_colCount; ++i) {
    mvaddch(this->m_rowCount-2, i, '-');
  }

  // Drawing the left side of the Board
  for(uint32_t i = 0; i < this->m_rowCount; ++i) {
    mvaddch(i, 0, '|');
  } 

  // Drawing the right side of the Board
  for(uint32_t i = 0; i < this->m_rowCount; ++i) {
    mvaddch(i, this->m_colCount-1, '|');
  }
}

void Game::drawSnake() {
  for(auto itr = this->m_snake.getBody().begin(); itr != this->m_snake.getBody().end(); ++itr) {
    mvaddch((*itr).y, (*itr).x, this->m_snakeSymbol);
  }
  refresh();
}

void Game::printScore() {
  move(this->m_rowCount-1, 0);
  printw("Score %d", this->m_score);
}

void Game::run() {  
  bool gotFood = false;
  while (true) {
    this->m_userInput = getch();
    gotFood = checkForFood();
    this->m_snake.move(this->m_userInput, gotFood);
    if(!gotFood) {
      move(m_snake.getBody()[m_snake.getBody().size()-1].y, m_snake.getBody()[m_snake.getBody().size()-1].x);
      addch(' ');
      refresh();
    }
    if(this->m_userInput == 'q') {
      break;
    }
  
    if(gotFood) {
      spawnFoodRand();
    }

    drawSnake();
    refresh();
    if(checkForLoss()) {
      break;
    }
    usleep(this->m_difficulty);
  }
  move(this->m_rowCount/2, this->m_colCount/2);
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
    this->m_snake.getHeadPos().x == this->m_rowCount ||
    this->m_snake.getHeadPos().y == 0 || 
    this->m_snake.getHeadPos().y == this->m_colCount
    ) {
      return true;
    }
  return false;
}