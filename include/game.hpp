#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include "player.hpp"

class Game {
private:
    sf::Time TimePerFrame;
    sf::RenderWindow window;
    sf::Texture texture;
    sf::Sprite background;
    sf::View view;
    sf::RectangleShape ground;

    Player player;

    void processEvents();
    void update(sf::Time deltaTime);
    void render();
    void handlePlayerInput(sf::Keyboard::Key key, bool isPressed);
    bool touchTheGround(sf::Vector2f objectPosition);

public:
    Game();
    void run();
};

#endif
