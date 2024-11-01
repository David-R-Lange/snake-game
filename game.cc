#include "game.h"

Game::Game(char sSym, char fS, uint32_t dif) {
  m_snakeSymbol = sSym;
  m_foodSymbol = fS;
  m_difficulty = dif;
  m_score = 0;
  m_userInput = 0;
  m_col = 0;
  m_row = 0;
  m_dir = UP;

  initGame();
  drawBoard();
  drawSnake();
  spawnFoodRand();
  printScore();
  refresh();
  std::srand(time(nullptr));
}

Game::~Game() {
  getch();
  nodelay(stdscr, false);
  curs_set(1);
  endwin();
} 

void Game::initGame() {
  initscr();
  noecho();
  keypad(stdscr, true);
  nodelay(stdscr, true);
  curs_set(0);
  getmaxyx(stdscr, m_row, m_col);
  position headStart (m_col/2, m_row/2);
  m_snake.push_front(headStart);
  m_dir = UP;
}

void Game::spawnFoodRand() {

  position tmp (5 + (rand()%m_col-2), 5 + (rand()%m_row-2));
  mvaddch(tmp.y, tmp.x, m_foodSymbol);
  m_food = tmp;
}


void Game::drawBoard() const{
  // Drawing the top of the Board
  for(uint32_t i = 0; i < m_col; ++i) {
    mvaddch(0, i, '_');
  }

  // Drawing the bottom of the Board
  for(uint32_t i = 0; i < m_col; ++i) {
    mvaddch(m_row-2, i, '-');
  }

  // Drawing the left side of the Board
  for(uint32_t i = 0; i < m_row; ++i) {
    mvaddch(i, 0, '|');
  } 

  // Drawing the right side of the Board
  for(uint32_t i = 0; i < m_row; ++i) {
    mvaddch(i, m_col-1, '|');
  }
}

void Game::drawSnake() const{
  for(size_t i = 0; i < m_snake.size(); ++i) {
    mvaddch(m_snake[i].y, m_snake[i].x, m_snakeSymbol);
  }
}

void Game::printScore() const{
  move(m_row-1, 0);
  printw("Score %d", m_score);
}

void Game::run() {  
  bool gotFood = false;
  while (true) {
    gotFood = checkForFood();
    moveSnake(gotFood);
    if(m_userInput == 'q') {
      break;
    }
  
    if(gotFood) {
      m_score += 100;
      spawnFoodRand();
    }

    printScore();
    drawSnake();
    refresh();
    if(checkForLoss()) {
      break;
    }
    usleep(m_difficulty);
  }
  move(m_row/2, m_col/2);
  printw("Game Over!");
}

bool Game::checkForFood() const{
  if(m_food == m_snake[0]) {
    return true;
  }
  return false;
}

bool Game::checkForLoss() const{
  if(m_snake[0].x == 0 || m_snake[0].x == m_col-1 ||
    m_snake[0].y == 0 || m_snake[0].y == m_row-2) {
      return true;
    }

  for(size_t i = 1; i > m_snake.size(); ++i) {
    if(m_snake[0].x == m_snake[i].x || m_snake[0].y == m_snake[i].y) {
      return true;
    }
  }
  return false;
}

void Game::moveSnake(bool gotFood) {

  m_userInput = getch();
  switch (m_userInput) {
    case 97: // a
    case 65: // A
    case KEY_LEFT:
      if(m_dir != RIGHT) {
        m_dir = LEFT;
      }
    break;
    case 100: // d
    case 68: // D
    case KEY_RIGHT:
      if(m_dir != LEFT) {
        m_dir = RIGHT;
      }
      break;
    case 119: // w
    case 87: // W
    case KEY_UP:
      if(m_dir != DOWN) {
        m_dir = UP;
      }
      break;
    case 115: // s
    case 83: // S
    case KEY_DOWN:
      if(m_dir != UP) {
        m_dir = DOWN;
      }
      break;
    case 'q':
    case KEY_BACKSPACE:
    case KEY_EXIT:
      m_userInput = 'q';
    default:
      break;
  }

  if(!gotFood) {
    mvaddch(m_snake[m_snake.size()-1].y, m_snake[m_snake.size()-1].x, ' ');
    m_snake.pop_back();
    refresh();
  }

  switch (m_dir) {
    case UP:
      m_snake.emplace_front(m_snake[0].x, m_snake[0].y-1);
      break;
    case DOWN:
      m_snake.emplace_front(m_snake[0].x, m_snake[0].y+1);
      break;
    case LEFT:
      m_snake.emplace_front(m_snake[0].x-1, m_snake[0].y);
      break;
    case RIGHT:
      m_snake.emplace_front(m_snake[0].x+1, m_snake[0].y);
      break;
    default:
      break;
  }

  mvaddch(m_snake[0].x, m_snake[0].y, m_snakeSymbol);
  refresh();
}