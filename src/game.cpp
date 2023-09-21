#include "game.hpp"

Game::Game()
: window(sf::VideoMode(600, 400), "Point Picker")
{
    TimePerFrame = sf::seconds(1.f / 60.f);
    texture.loadFromFile("assets/Background.png");
    background.setTexture(texture);

    view.setCenter(sf::Vector2f(600.f, 550.f));
    view.setSize(600, 400);

    player.setPosition(sf::Vector2f(600.f, 400.f));

    ground = sf::RectangleShape(sf::Vector2f(900.f, 20));
    ground.setFillColor(sf::Color::Transparent);
    ground.setPosition(sf::Vector2f(0.f, 730.f));

    window.setView(view);
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
    player.falling(!touchTheGround(player.getPosition()));
}

void Game::render() {
    window.clear();
    window.draw(background);
    window.draw(player);
    window.draw(ground);
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
        
        case sf::Keyboard::Space:
            player.running(isPressed);
            break;
    }
}

bool Game::touchTheGround(sf::Vector2f objectPosition) {
    return objectPosition.y >= (ground.getPosition().y - ground.getSize().y);
}