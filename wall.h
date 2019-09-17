#pragma once

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
    int unite(const Tetromino &);
};
