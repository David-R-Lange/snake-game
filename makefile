all: snake_game
	./snake_game

snake_game: main.cc game.cc game.h snake.cc snake.hh pos.h
	g++ -Wall -o snake_game main.cc game.cc snake.cc -lncurses -g

clean:
	rm snake_game