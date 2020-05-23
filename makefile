CC=gcc
SRC=Main.c 
OBJ= $(SRC:.c=.o) 
FLAGS=-Wall
Tetris: $(OBJ) tetris.h 
	$(CC) -o $@ $(OBJ)
%.o: %.c
	$(CC) -c $< $(CFLAGS)

clean:
	rm *.o ./Tetris