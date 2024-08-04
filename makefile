all: snake_game
	./snake_game

snake_game: main.cc game.cc game.h pos.h
	g++ -Wall -o snake_game main.cc game.cc -lncurses -g

clean:
	rm snake_game