#include "playerAnimation.hpp"


PlayerAnimation::PlayerAnimation() {
    scene = 0;
}

void PlayerAnimation::load(std::string filename, sf::Vector2f size, int length, float offset) {
    texture.loadFromFile(filename);
    this->size = size;
    this->length = length;
    this->offset = offset;
}

sf::Texture* PlayerAnimation::getTexture() {
    return &texture;
}

sf::Vector2f PlayerAnimation::getSize() {
    return size;
}

int PlayerAnimation::getLength() {
    return length;
}

float PlayerAnimation::getOffset() {
    return offset;
}

int PlayerAnimation::getScene() {
    return scene;
}

void PlayerAnimation::addScene() {
    scene++;

    if (scene == length) {
        scene = 0;
    }
}
