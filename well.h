#pragma once
#include "painter.h"
#include "tetromino.h"

const int SIZE_Y_ = 20;
const int SIZE_X_ = 10;
class Well {
public:
    Well();
    // малюємо поле на Painter
    void draw(Painter &) const;
    /* первірка на зіткнення тетроміно з
     * фігурами на полі
     */
    bool isCollision(const Tetromino &) const;
    // перемішення тетроміни на полі
    void unite(const Tetromino &);
    // видалення повністю заповненої ліній
    int removeSolidLines();
private:
    bool map_[20][10];
};
