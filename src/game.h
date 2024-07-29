#ifndef SNAKE-GAME_GAME_H
#define SNAKE-GAME_GAME_H

#include "board.hh"
#include "snake.hh"
#include "food.hh"
#include "pos.h"

class Game {
  private:
    Board m_board;
    Snake m_snake;
    Food m_food;

  public:
    Game(Board&, Snake&, Food&);
    ~Game();
    void initBoard();
    void run();
    bool checkForFood();
    bool checkForLoss();
};

#endif // !SNAKE-GAME_GAME_H
