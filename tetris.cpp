// Гра "Тетріс"
#include <GL/glut.h>
#include "game.h"

Game game;

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
    glutTimerFunc(500, timer, 0); // регулювання швиткості падіння елементів
}

void keyEvent(int key, int x, int y) {
    /* Обробка натисканна клавіш клавіатури */
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
    glutMainLoop();

    return 0;
}
