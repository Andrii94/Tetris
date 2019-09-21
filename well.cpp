#include "well.h"

Well::Well() {
    for (int y = 0; y < SIZE_Y_; ++y )
        for (int x = 0; x < SIZE_X_; ++x)
            map_[y][x] = false;
}

void Well::draw(Painter &p) const {
    p.setColor(Painter::WHITE);
    for (int y = 0; y < SIZE_Y_; ++y )
        for (int x = 0; x < SIZE_X_; ++x)
            if (map_[y][x])
                p.rect(x * 8 + 1, y * 8 + 1,
                       (x + 1) * 8 - 1, (y + 1) * 8 - 1);
            else
                p.rect(x * 8 + 3, y * 8 + 3,
                       (x + 1) * 8 - 4, (y + 1) * 8 - 4);
}

bool Well::isCollision(const Tetromino &t) const {
    for (int y = 0; y < 4; ++y )
        for (int x = 0; x < 4; ++x)
            if (t.map(x, y)) {
                int wx = x + t.x();
                int wy = y + t.y();
                if (wx < 0 || wx >= SIZE_X_ || wy < 0 || wy >= SIZE_Y_)
                    return true;
                if (map_[wy][wx])
                    return true;
            }
    return false;
}

void Well::unite(const Tetromino &t) {
    for (int y = 0; y < 4; ++y )
        for (int x = 0; x < 4; ++x) {
            int wx = x + t.x();
            int wy = y + t.y();
            if (wx >= 0 && wx < SIZE_X_ && wy >= 0 && wy < SIZE_Y_)
                map_[wy][wx] = map_[wy][wx] || t.map(x, y);
        }
}

int Well::removeSolidLines() {
    int res = 0;
    for (int y = 0; y < SIZE_Y_; ++y) {
        bool solid = true;
        for (int x = 0; x < SIZE_X_; ++x)
            if (!map_[y][x]) {
                solid = false;
                break;
            }
        if (solid) {
            ++res;
            for (int yy = y - 1; yy >= 0; --yy)
                for (int x = 0; x < SIZE_X_; ++x)
                    map_[yy + 1][x] = map_[yy][x];
        }
        for (int x = 0; x < SIZE_X_; ++x)
            map_[0][x] = false;
    }
    return res;
}
