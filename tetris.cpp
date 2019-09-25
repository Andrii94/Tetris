// Гра "Тетріс"
#include <GL/glut.h>
#include <cmath>
#include "game.h"

Game game;
int t = 500, r = 0;

void display () {
    /* Відображення поля */
    glClear(GL_COLOR_BUFFER_BIT);
    Painter p; // поле
    game.draw(p); // зообразити гру на полі
    glutSwapBuffers();
}

void timer(int) {
    game.tick();
    display(); // перемалюванна поля
    if (static_cast<int>(game.getRes()) != r){
        r = static_cast<int>(game.getRes());
        if (6 > r)
            t = 1000 - 100 * r;
        else if (100 > r)
            t = 400 - r*2;
        else
            t = 200 - log(r);
    }
    if (100 > t) t = 100;
    glutTimerFunc(t, timer, 0); // регулювання швиткості падіння елементів
}

void keyEvent(int key, int x, int y) {
    /* Обробка натисканна клавіш клавіатури */
    if (key == 27)
        exit(0);
    switch (key) {
    case GLUT_KEY_LEFT:
        game.keyEvent(Game::LEFT);
        break;
    case GLUT_KEY_RIGHT:
        game.keyEvent(Game::RIGHT);
        break;
    case GLUT_KEY_UP:
        game.keyEvent(Game::UP);
        break;
    case GLUT_KEY_DOWN:
        game.keyEvent(Game::DOWN);
        break;
    }
    display(); // перемалюванна зображення з новим положенням об'єкта
}

void processNormalKeys(unsigned char key, int x, int y) {
        if (key == 27)
                exit(0);
        else if (key==13){
            game.keyEvent(Game::FINISH);
        }
}

int main (int argc, char** argv) {
    /* Початок програми */
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(40*8, 80*8); // 10x20 розмір поля
    glutInitWindowPosition(200, 0);
    glutCreateWindow("Tetris");
    glClearColor(0, 0, 0, 1);
    glMatrixMode(GL_PROJECTION);
    //glLoadIndentity();
    glOrtho(0, 10 * 8, 20 * 8, 0, -1.0, 1.0);
    glutDisplayFunc(display);
    timer(0);
    glutSpecialFunc(keyEvent);
    glutKeyboardFunc(processNormalKeys);
    glutMainLoop();

    return 0;
}
