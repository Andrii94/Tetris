#pragma once
#include <GL/gl.h>

class Painter {
public:
    // кольори якими дозволенно зоображати
    enum Color { RED, WHITE, MAGENTA, DARK_BLUE,
               GREEN, BROWN, CYAN, BLACK };
    // зображення частини фігури
    void rect(int x1, int y1, int x2, int y2);
    // задання кольору
    void setColor(Color);
};
