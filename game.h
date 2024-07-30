#ifndef SNAKEGAME_GAME_H
#define SNAKEGAME_GAME_H

#include "board.hh"
#include "snake.hh"
#include "food.hh"
#include "pos.h"
#include <stdlib.h>
#include <ncurses.h>

class Game {

  public:
    Board m_board = Board(); 
    Snake m_snake = Snake();
    Food m_food = Food();
    Game(Board&, Snake&, Food&);
    ~Game();
    void updateBoard();
    void run();
    bool checkForFood();
    bool checkForLoss();
};

#endif // !SNAKE-GAME_GAME_H
