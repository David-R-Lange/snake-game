#include "board.hh"
#include <chrono>
#include <thread>
#include <stdio.h>


int main() {
  std::size_t boardSize = 16;

  std::string playerName = "David";

  Board board(boardSize);

  bool isGameOver = false;

  while(!isGameOver) {
    board.drawBoard(playerName);

    std::this_thread::sleep_for(std::chrono::milliseconds(100));

  }
}
