CPPFLAGS=-Wall -g
OBJECTS=tetris.o painter.o
%.o: %.cpp
        g++ -c $(CPPFLAGS) -o $@ $<
tetris: $(OBJECTS)
        g++ $(OBJECTS) -o tetris -g -lglut
tetris.o: tetris.cpp painter.h
painter.o: painter.cpp painter.h
