
CC=g++

CFLAGS=-Wall -lSDL_ttf -lSDL
CFLAGS=-lSDL_ttf -lSDL

DEPS = Block.cpp Shape.cpp GameBoard.cpp DrawSdl.cpp GameSdl.cpp   main.cpp
OBJ  = Block.o   Shape.o   GameBoard.o   DrawSdl.o   GameSdl.o     main.o   


all: tetris


tetris: $(OBJ)
	$(CC) $(CFLAGS) -o ../$@ $^ 


obj : $(DEPS)

clean:
	rm -f *.o

%.o: %.cpp 
	$(CC) -c -o $@ $< $(CFLAGS)


