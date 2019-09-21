#pragma once
#include "painter.h"

class Tetromino {
public:
    enum Direction { LEFT = -1, RIGHT = 1 };
    enum Name { I, J, L, O, S, Z, T };
    // стварення тетроміно за ім'ям
    Tetromino(Name);
    // малювання тетроміно на Painter
    void draw(Painter &) const;
    // переміщення тетроміно на dx, dy
    void move(int dx, int dy);
    /* поверненя тетроміно за годиниковою стрілкою або
     * проти годиниковой стрілки
     */
    void rotate(Direction);
    bool map(int x, int y) const;
    int x() const { return x_; }
    int y() const { return y_; }
private:
    Name name_;
    int angel_;
    int x_;
    int y_;
};
