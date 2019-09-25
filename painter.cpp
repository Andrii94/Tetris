#include "painter.h"

void Painter::rect(int x1, int y1, int x2, int y2) {
    glBegin(GL_QUADS);
    glVertex2f(x1, y1);
    glVertex2f(x2, y1);
    glVertex2f(x2, y2);
    glVertex2f(x1, y2);
    glEnd();
}

void Painter::setColor(Color color) {
    static const struct {
        float r, g, b;
    } colors[] =
        {
            { 1, 0, 0 }, // red
            { 1, 1, 1 }, // white
            { 1, 0, 1 }, // magenta
            { 0, 0, 0.5 }, // dark blue
            { 0, 1, 0 }, // green
            { 0.5, 0.5, 0 }, // brown
            { 0, 1, 1 }, // cyan
            { 0, 0, 0 }, // black
        };
    glColor3f(colors[color].r,
              colors[color].g,
              colors[color].b);
}

void Painter::showFinish(uint64_t r) {
    const char *res = "RESULT";
    int sizeResult = sizeof(res)/sizeof(*res);
    for (int i = 0; i < sizeResult; ++i) {
        glRasterPos2f(6 * 8 + ((i - sizeResult / 2) * 7), 10 * 8 - 5);
        setColor( static_cast<Painter::Color>(rand() % 7) );
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, res[i]);
    }
    uint64_t tmp = r;
    sizeResult = 0;
    while (tmp) {
        ++sizeResult;
        tmp /= 10;
    }
    tmp = r;
    for (int i = 0; tmp ; ++i) {
        glRasterPos2f(6 * 8 - ((i - (sizeResult / 2)) * 7), 10 * 8 + 5);
        setColor( static_cast<Painter::Color>(rand() % 7) );
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, static_cast<char>((tmp % 10) + '0'));
        tmp /= 10;
    }
//    glRasterPos2f(5 * 8 - 17, 10 * 8 - 15);
//    setColor(RED);
//    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'R');
//    glRasterPos2f(5 * 8 - 12, 10 * 8 - 15);
//    setColor(RED);
//    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'E');
    // resulr
    // number
}
