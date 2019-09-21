#pragma once
#include <cstdlib>
#include "painter.h"
#include "well.h"
#include "tetromino.h"

class Game {
public:
    enum Direction { UP, DOWN, LEFT, RIGHT };
    Game ();
    void draw(Painter &);
    void tick();
    void restart();
    void keyEvent(Direction);
private:
    Well well_;
    Tetromino tetromino_;
};
