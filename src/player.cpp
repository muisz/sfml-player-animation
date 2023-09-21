#include <iostream>
#include "player.hpp"


Player::Player() {
    idleAnimation.load("assets/Owlet_Monster_Idle_4.png", sf::Vector2f(32, 32), 4, 0.3);
    walkingAnimation.load("assets/Owlet_Monster_Walk_6.png", sf::Vector2f(32, 32), 6, 0.1);
    runningAnimation.load("assets/Owlet_Monster_Run_6.png", sf::Vector2f(32, 32), 6, 0.1);
    
    player.setTexture(*idleAnimation.getTexture());
    player.setTextureRect(sf::IntRect(0, 0, 32, 32));
    player.setOrigin(32 / 2, 32 / 2);

    isMovingLeft = false;
    isMovingRight = false;
    isMovingUp = false;
    isMovingDown = false;
    isRunning = false;
    isFalling = false;

    animationScene = 0;
}

void Player::setPosition(sf::Vector2f position) {
    player.setPosition(position);
}

void Player::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(player, states);
}

void Player::update(sf::Time deltaTime) {
    updatePlayerMovement(deltaTime);
    updatePlayerAnimation(deltaTime);
}

void Player::updatePlayerMovement(sf::Time deltaTime) {
    sf::Vector2f movement;
    int movementSteps = 50;

    if (isRunning)
        movementSteps *= 2;
    
    if (isMovingLeft)
        movement.x -= movementSteps;
    if (isMovingRight)
        movement.x += movementSteps;
    if (isMovingUp)
        movement.y -= movementSteps;
    if (isMovingDown)
        movement.y += movementSteps;

    if (isMovingLeft)
        player.setScale(-1.f, 1);
    else if (isMovingRight)
        player.setScale(1.f, 1.f);
    
    if (isFalling)
        movement.y += movementSteps;
        
    player.move(movement * deltaTime.asSeconds());
}

void Player::updatePlayerAnimation(sf::Time deltaTime) {
    if (isIdle()) {
        animate(idleAnimation);
    }
    else if (isWalking()) {
        if (isRunning)
            animate(runningAnimation);
        else
            animate(walkingAnimation);
    } else {
        player.setTextureRect(sf::IntRect(0, 0, 32, 32));
        clock.restart();
    }
}

void Player::animate(PlayerAnimation& animation) {
    int index = animation.getScene() * animation.getSize().x;

    player.setTexture(*animation.getTexture());
    player.setTextureRect(sf::IntRect(index, 0, animation.getSize().x, animation.getSize().y));
    if (clock.getElapsedTime().asSeconds() > animation.getOffset()) {
        animation.addScene();
        clock.restart();
    }
}

bool Player::isIdle() {
    return !(isMovingLeft || isMovingRight || isMovingUp || isMovingDown);
}

bool Player::isWalking() {
    return (isMovingLeft || isMovingRight || isMovingUp || isMovingDown);
}

void Player::moveLeft(bool isPressed) {
    isMovingLeft = isPressed;
}

void Player::moveRight(bool isPressed) {
    isMovingRight = isPressed;
}

void Player::moveUp(bool isPressed) {
    isMovingUp = isPressed;
}

void Player::moveDown(bool isPressed) {
    isMovingDown = isPressed;
}

void Player::running(bool isPressed) {
    isRunning = isPressed;
}

void Player::falling(bool state) {
    isFalling = state;
}

sf::Vector2f Player::getPosition() {
    return player.getPosition();
}
