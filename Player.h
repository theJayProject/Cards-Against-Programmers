#ifndef CARDSAGAINSTPROGRAMMERS_PLAYER_H
#define CARDSAGAINSTPROGRAMMERS_PLAYER_H

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>


class Player : public sf::Drawable {
public:
    explicit Player(float x = 0.f, float y = 0.f);

    ~Player();

    void update(const sf::RenderWindow* window);

    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

private:
    sf::RectangleShape m_shape;
    float m_movementSpeed;

    void initVariables();
    void initShapes();
    void updateMousePosition(const sf::RenderWindow* window);
    void updateWindowBoundsCollision(const sf::RenderTarget* target);
    void updateInput();
};


#endif //CARDSAGAINSTPROGRAMMERS_PLAYER_H
