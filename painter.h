#pragma once
#include <cstdlib>
#include <cstdint>
#include <GL/gl.h>
#include <GL/glut.h>

class Painter {
public:
    // кольори якими дозволенно зоображати
    enum Color { RED, WHITE, MAGENTA, DARK_BLUE,
               GREEN, BROWN, CYAN, BLACK };
    // зображення частини фігури
    void rect(int x1, int y1, int x2, int y2);
    // задання кольору
    void setColor(Color);
    // зображення екрана після того як програв
    void showFinish(uint64_t);
};
