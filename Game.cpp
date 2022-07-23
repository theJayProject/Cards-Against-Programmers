#include "Game.h"

Game::Game() {
    this->initWindow();
    this->initShapes();
}

Game::~Game() {
    delete m_renderWindow;
}

void Game::update() {
    this->pollEvents();
    m_player.update();
    updateMousePos(m_renderWindow);
}

void Game::render() {
    m_renderWindow->clear();

    m_renderWindow->draw(m_player);
    m_renderWindow->display();
}

bool Game::isRunning() const {
    return m_renderWindow->isOpen();
}

void Game::initWindow() {
    m_videoMode.width = 800;
    m_videoMode.height = 600;

    m_style = sf::Style::Titlebar | sf::Style::Close;

    m_renderWindow = new sf::RenderWindow(m_videoMode, "Cards Against Programmers", m_style);
    m_renderWindow->setFramerateLimit(144);
}

void Game::initShapes() {
}

void Game::pollEvents() {

    while (m_renderWindow->pollEvent(m_event)) {
        if (m_event.type == sf::Event::Closed)
            m_renderWindow->close();
        if (m_event.type == sf::Event::KeyPressed) {
            if (m_event.key.code == sf::Keyboard::Escape) {
                m_renderWindow->close();
            }
        }
    }
}


void Game::updateMousePos(sf::RenderWindow *window) {
    m_mousePosWindow = sf::Mouse::getPosition(*window);

    if (m_player.getPlayerShape().getGlobalBounds().contains(m_mousePosWindow.x, m_mousePosWindow.y)) {
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            m_player.getPlayerShape().setFillColor(sf::Color::Red);
            m_player.getPlayerShape().setPosition(
                    m_mousePosWindow.x - (m_player.getPlayerShape().getSize().x / 2),
                    m_mousePosWindow.y - m_player.getPlayerShape().getSize().y / 2);
        }
    }
}


