all: snake_game
	./snake_game

snake_game: main.cc  board.o snake.o food.o
	g++ -c -Wall main.cc

board.o: board.cc board.hh
	g++ -c -Wall board.cc

snake.o: snake.cc snake.hh
	g++ -c -Wall snake.cc

food.o: food,cc food.hh
	g++ -c -Wall food.cc

clean:
	rm *.o
	rm snake_game
	@echo "Removed object files"
