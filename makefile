all: snake_game
	./snake_game

snake_game: main.cc game.cc game.h board.cc board.hh snake.cc snake.hh food.cc food.hh pos.h
	g++ -Wall -o snake_game main.cc game.cc board.cc snake.cc food.cc -lncurses -g

clean:
	rm snake_game
	@echo "Removed object files"
