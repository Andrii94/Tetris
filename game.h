#pragma once
#include <cstdlib>
#include <ctime>
#include "painter.h"
#include "well.h"
#include "tetromino.h"

class Game {
public:
    // зміна полодення елемента
    enum Direction { UP, DOWN, LEFT, RIGHT };
    Game ();
    // зображення гри
    void draw(Painter &);
    // один крок
    void tick();
    // нова гра
    void restart();
    // зміна положення фігури гравцем
    void keyEvent(Direction);
private:
    Well well_; //
    Tetromino tetromino_; // нова фігура на полі
};
