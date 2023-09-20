#ifndef PLAYER_ANIMATION_H
#define PLAYER_ANIMATION_H

#include <SFML/Graphics.hpp>
#include <iostream>

class PlayerAnimation {
private:
    sf::Texture texture;
    sf::Vector2f size;
    int length;
    float offset;
    int scene;

public:
    PlayerAnimation();
    void load(std::string filename, sf::Vector2f size, int length, float offset);
    sf::Texture* getTexture();
    sf::Vector2f getSize();
    int getLength();
    float getOffset();
    int getScene();
    void addScene();
};

#endif
