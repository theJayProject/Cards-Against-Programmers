#ifndef CARDSAGAINSTPROGRAMMERS_GAME_H
#define CARDSAGAINSTPROGRAMMERS_GAME_H


#include "Player.h"

class Game {

public:
    Game();
    ~Game();

    void update();
    void render();

    bool isRunning() const;

private:
    Player m_player;
    sf::RenderWindow* m_renderWindow;
    sf::Event m_event{};
    sf::VideoMode m_videoMode{};
    sf::Uint32 m_style{};
    sf::Vector2i m_mousePosWindow;

    void initWindow();
    void initShapes();
    void updateMousePos(sf::RenderWindow* target);

    void pollEvents();
};

#endif //CARDSAGAINSTPROGRAMMERS_GAME_H
