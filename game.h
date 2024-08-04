#ifndef SNAKEGAME_GAME_H
#define SNAKEGAME_GAME_H

#include "snake.hh"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <random>
#include <ctime>

class Game {
  private:
    char m_snakeSymbol;
    char m_foodSymbol;
    char m_userInput;
    uint32_t m_difficulty;
    uint32_t m_rowCount;
    uint32_t m_colCount;
    uint32_t m_score;
    position m_food;
    Snake m_snake;
    
    void initGame();
    void spawnFoodRand();
    void drawBoard();
    void drawSnake();
    void printScore();
    bool checkForFood();
    bool checkForLoss();

  public:
    Game(char, char, uint32_t);
    ~Game();
    void run();
};

#endif // !SNAKE-GAME_GAME_H
