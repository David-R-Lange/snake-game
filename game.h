#ifndef SNAKEGAME_GAME_H
#define SNAKEGAME_GAME_H

#include "snake.hh"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

class Game {
  private:
    char m_snakeSymbol;
    char m_foodSymbol;
    uint32_t m_difficulty;
    position m_food;
    Snake m_snake;

  public:
    Game(Snake&, char, char, uint32_t);
    ~Game();
    position spawnFoodRand();
    void run();
    bool checkForFood();
    bool checkForLoss();
};

#endif // !SNAKE-GAME_GAME_H
