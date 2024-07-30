#ifndef SNAKEGAME_GAME_H
#define SNAKEGAME_GAME_H

#include "board.hh"
#include "snake.hh"
#include "food.hh"
#include "pos.h"
#include <curses.h>

class Game {
  private:
    char m_headSymbol;
    char m_tailSymbol;
    char m_foodSymbol;
    char m_boardSymbol;

  public:
    Board m_board = Board(); 
    Snake m_snake = Snake();
    Food m_food = Food();
    Game(Board&, Snake&, Food&, char, char, char);
    ~Game();
    position spawnFoodRand();
    void updateBoard();
    void run();
    bool checkForFood();
    bool checkForLoss();
};

#endif // !SNAKE-GAME_GAME_H
