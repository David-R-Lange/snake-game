#ifndef SNAKEGAME_GAME_H
#define SNAKEGAME_GAME_H

#include "board.hh"
#include "snake.hh"
#include "food.hh"
#include "pos.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

class Game {
  private:
    char m_headSymbol;
    char m_tailSymbol;
    char m_foodSymbol;
    char m_boardSymbol;
    int m_difficulty;

  public:
    Board m_board = Board(); 
    Snake m_snake = Snake();
    Food m_food = Food();
    Game(Board&, Snake&, Food&, char, char, char, int);
    ~Game();
    position spawnFoodRand();
    void updateBoard();
    void run();
    bool checkForFood();
    bool checkForLoss();
};

#endif // !SNAKE-GAME_GAME_H
