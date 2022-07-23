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

void Player::update() {
    this->updateInput();
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

sf::RectangleShape& Player::getPlayerShape() {
    return m_shape;
}









