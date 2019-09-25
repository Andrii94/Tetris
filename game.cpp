#include "game.h"

Game::Game(): tetromino_(static_cast<Tetromino::Name>(0)) {
    // створення випадкової фігури в грі
    srand(time(0));
    tetromino_ = Tetromino(static_cast<Tetromino::Name>(rand() % 7));
}

void Game::draw(Painter &p) {
    well_.draw(p); // зображення поля з фіксовиними елементами
    tetromino_.draw(p); // зображення рухомої фігури
}

void Game::tick() {
    Tetromino t = tetromino_;
    t.move(0, 1); // стандартний хід фігурки
    if (!well_.isCollision(t)) {
        // якщо фігуці є куди падати
        tetromino_ = t;
    }
    else {
        well_.unite(tetromino_);
        well_.removeSolidLines();
        tetromino_ = Tetromino(static_cast<Tetromino::Name>(rand() % 7));
        if (well_.isCollision(tetromino_))
            restart();
    }
}

void Game::restart() {
    well_ = Well();
}

void Game::keyEvent(Direction d) {
    Tetromino t = tetromino_;
    switch (d) {
    case UP:
        t.rotate(Tetromino::LEFT);
        break;
    case DOWN:
        t.move(0, 1);
        break;
    case LEFT:
        t.move(-1, 0);
        break;
    case RIGHT:
        t.move(1, 0);
        break;
    }
    if (!well_.isCollision(t))
        tetromino_ = t;
}
