#pragma once
#include "painter.h"

class Tetromino {
public:
    enum Direction { LEFT = -1, RIGHT = 1 }; // відповідає за обертання фігури
    enum Name { I, J, L, O, S, Z, T }; // Перелік назв типів вігур
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
    // перевірка чи займає фігура данну координату
    bool map(int x, int y) const;
    // повернення координати фівгури
    int x() const { return x_; }
    int y() const { return y_; }
private:
    Name name_; // тип фігури
    int angel_; // як вона попернена
    int x_; // координата x
    int y_; // координата y
};
