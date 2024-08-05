#ifndef SNAKEGAME_GAME_H
#define SNAKEGAME_GAME_H

#include <deque>
#include <ncurses.h>
#include <unistd.h>
#include <random>
#include <ctime>

#include "pos.h"

class Game {
  private:
    char m_snakeSymbol;
    char m_foodSymbol;
    int m_userInput;
    uint32_t m_difficulty;
    int m_row;
    int m_col;
    uint32_t m_score;
    position m_food;
    std::deque<position> m_snake;
    enum m_direction {UP, DOWN, LEFT, RIGHT};
    m_direction m_dir;
    
    void initGame();
    void spawnFoodRand();
    void drawBoard() const;
    void drawSnake() const;
    void printScore() const;
    [[nodiscard]] bool checkForFood() const;
    [[nodiscard]] bool checkForLoss() const;
    void moveSnake(bool);

  public:
    Game(char, char, uint32_t);
    ~Game();
    void run();
};

#endif // !SNAKEGAME_GAME_H
