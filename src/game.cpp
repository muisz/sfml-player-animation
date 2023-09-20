#include "game.hpp"

Game::Game()
: window(sf::VideoMode(600, 400), "Point Picker")
{
    TimePerFrame = sf::seconds(1.f / 60.f);
}

void Game::run() {
    sf::Clock clock;
    sf::Time timeSinceLastUpdate = sf::Time::Zero;
    while (window.isOpen()) {
        processEvents();
        timeSinceLastUpdate += clock.restart();
        while (timeSinceLastUpdate > TimePerFrame) {
            timeSinceLastUpdate -= TimePerFrame;
            processEvents();
            update(TimePerFrame);
        }
        render();
    }
}

void Game::processEvents() {
    sf::Event event;
    while (window.pollEvent(event)) {
        switch (event.type) {
            case sf::Event::Closed:
                window.close();
                break;
            
            case sf::Event::KeyPressed:
                handlePlayerInput(event.key.code, true);
                break;
            
            case sf::Event::KeyReleased:
                handlePlayerInput(event.key.code, false);
                break;
        }
    }
}

void Game::update(sf::Time deltaTime) {
    player.update(deltaTime);
}

void Game::render() {
    window.clear();
    window.draw(player);
    window.display();
}

void Game::handlePlayerInput(sf::Keyboard::Key key, bool isPressed) {
    switch (key) {
        case sf::Keyboard::Left:
            player.moveLeft(isPressed);
            break;
        
        case sf::Keyboard::Right:
            player.moveRight(isPressed);
            break;

        case sf::Keyboard::Up:
            player.moveUp(isPressed);
            break;

        case sf::Keyboard::Down:
            player.moveDown(isPressed);
            break;
        
        case sf::Keyboard::Space:
            player.running(isPressed);
            break;
    }
}