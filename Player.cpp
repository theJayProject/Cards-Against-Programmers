#include "Player.h"

Player::Player(float x, float y) {
    this->initVariables();
    this->initShapes();
    m_shape.setPosition(x, y);
}

Player::~Player() {

}

void Player::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(m_shape);
}

void Player::update(const sf::RenderWindow *window) {
    this->updateInput();
    this->updateMousePosition(window);
    this->updateWindowBoundsCollision(window);
}


void Player::initVariables() {
    m_movementSpeed = 10.f;
}

void Player::initShapes() {
    m_shape.setFillColor(sf::Color::Blue);
    m_shape.setSize(sf::Vector2f{100.f, 100.f});
    m_shape.setPosition(100.f, 100.f);
}

void Player::updateInput() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        m_shape.move(-m_movementSpeed, 0.f);
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        m_shape.move(m_movementSpeed, 0.f);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        m_shape.move(0.f, -m_movementSpeed);
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        m_shape.move(0.f, m_movementSpeed);
    }
}


void Player::updateWindowBoundsCollision(const sf::RenderTarget *target) {
    sf::FloatRect playerBounds = m_shape.getGlobalBounds();


    if (playerBounds.left < 0.f) {
        m_shape.setPosition(0, playerBounds.top);
    } else if (playerBounds.left + playerBounds.width >= target->getSize().x) {
        m_shape.setPosition(target->getSize().x - playerBounds.width, playerBounds.top);
    }

    if (playerBounds.top < 0.f) {
        m_shape.setPosition(playerBounds.left, 0);
    } else if (playerBounds.top + playerBounds.height > target->getSize().y) {
        m_shape.setPosition(playerBounds.left, target->getSize().y - playerBounds.height);
    }
}

void Player::updateMousePosition(const sf::RenderWindow *window) {
    sf::Vector2i mousePos = sf::Mouse::getPosition(*window);
    if (m_shape.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            m_shape.setFillColor(sf::Color::Green);
            m_shape.setPosition(
                    mousePos.x - m_shape.getSize().x / 2,
                    mousePos.y - m_shape.getSize().y / 2
            );
        }
    }
}









