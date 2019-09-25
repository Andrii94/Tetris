#include "game.h"

Game::Game(): tetromino_(static_cast<Tetromino::Name>(0)), res(0) {
    // створення випадкової фігури в грі
    srand(time(0));
    tetromino_ = Tetromino(static_cast<Tetromino::Name>(rand() % 7));
    res = 0;
    finish = false;
}

void Game::draw(Painter &p) {
    if (!finish) {
        well_.draw(p); // зображення поля з фіксовиними елементами
        tetromino_.draw(p); // зображення рухомої фігури
    } else {
        p.showFinish(res);
    }
}

void Game::tick() {
    Tetromino t = tetromino_;
    t.move(0, 1); // стандартний хід фігурки
    if (!well_.isCollision(t)) {
        // якщо фігуці є куди падати
        tetromino_ = t;
    }
    else {
        // фіксування вігури на полі як його частина
        well_.unite(tetromino_);
        // перевірка на заповнені ліній
        res += static_cast<uint64_t>(well_.removeSolidLines());
        // створення новой фігури
        tetromino_ = Tetromino(static_cast<Tetromino::Name>(rand() % 7));
        if (well_.isCollision(tetromino_)) {
            // фігурки досягли верха
            finish = true;
//            restart();
            // зробити вивід результату
        }
    }
}

void Game::restart() {
    // почати спочатку
    well_ = Well();
}

void Game::keyEvent(Direction d) {
    // рух елемента взалежності від натискання клавіші
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
    case FINISH:
        if (finish) restart();
        finish = false;
        break;
    }
    if (!well_.isCollision(t))
        tetromino_ = t;
}
