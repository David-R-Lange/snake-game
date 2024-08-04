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
  m_snake.push_front(headStart); 
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
  for(auto itr = this->m_snake.begin(); itr != this->m_snake.end(); ++itr) {
    mvaddch((*itr).y, (*itr).x, this->m_snakeSymbol);
  }
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
    moveSnake(gotFood);
    if(!gotFood) {
      move(m_snake[m_snake.size()-1].y, m_snake[m_snake.size()-1].x);
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
  if(this->m_food == this->m_snake[0]) {
    return true;
  }
  return false;
}

bool Game::checkForLoss() {
  if(this->m_snake[0].x == 0 || 
    this->m_snake[0].x == this->m_rowCount ||
    this->m_snake[0].y == 0 || 
    this->m_snake[0].y == this->m_colCount
    ) {
      return true;
    }
  return false;
}

void Game::moveSnake(bool gotFood) {
  position head_tmp(0,0);

  switch (this->m_userInput) {
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
  new_head.x = m_snake[0].x + head_tmp.x;
  new_head.y = m_snake[0].y + head_tmp.y;
  this->m_snake.push_front(new_head);

  if(!gotFood) {
    move(m_snake[m_snake.size()-1].y, m_snake[m_snake.size()-1].x);
    this->m_snake.pop_back();
    addch(' ');
    refresh();
  }
}