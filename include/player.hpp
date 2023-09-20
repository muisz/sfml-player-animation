#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>
#include "playerAnimation.hpp"

class Player : public sf::Drawable {
private:
    sf::Texture texture;

    sf::Sprite player;
    sf::Clock clock;

    PlayerAnimation idleAnimation;
    PlayerAnimation walkingAnimation;
    PlayerAnimation runningAnimation;

    int animationScene;

    bool isMovingLeft;
    bool isMovingRight;
    bool isMovingUp;
    bool isMovingDown;
    bool isRunning;

    void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    void updatePlayerMovement(sf::Time deltaTime);
    void updatePlayerAnimation(sf::Time deltaTime);
    void animate(PlayerAnimation& animation);
    bool isIdle();
    bool isWalking();

public:
    Player();
    void update(sf::Time deltaTime);
    void moveLeft(bool isPressed);
    void moveRight(bool isPressed);
    void moveUp(bool isPressed);
    void moveDown(bool isPressed);
    void running(bool isPressed);
};

#endif
