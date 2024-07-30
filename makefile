all: snake_game
	./snake_game

snake_game: main.o game.o board.o snake.o food.o
	g++ *.o -o snake_game -g 

main.o: main.cc game.h board.hh snake.hh food.hh
	g++ -c -Wall main.cc -o snake_game

game.o: game.cc game.h board.hh snake.hh food.hh 
	g++ -c -Wall game.cc -g -lncurses

board.o: board.cc board.hh
	g++ -c -Wall board.cc -g

snake.o: snake.cc snake.hh
	g++ -c -Wall snake.cc -g

food.o: food.cc food.hh
	g++ -c -Wall food.cc -g

clean:
	rm *.o
	rm snake_game
	@echo "Removed object files"
