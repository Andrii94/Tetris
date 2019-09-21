CPPFLAGS=-Wall -g
OBJECTS=tetris.o painter.o tetromino.o well.o game.o
%.o: %.cpp
	g++ -c $(CPPFLAGS) -o $@ $<
tetris: $(OBJECTS)
	g++ $(OBJECTS) -o tetris -g -lglut -lGLU -lGL
tetris.o: tetris.cpp game.h well.h painter.h tetromino.h
painter.o: painter.cpp painter.h
tetromino.o: tetromino.cpp tetromino.h painter.h
well.o: well.cpp well.h painter.h tetromino.h
game.o: game.cpp game.h well.h painter.o tetromino.h
