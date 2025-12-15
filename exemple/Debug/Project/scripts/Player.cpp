#include "Player.h"
#include <iostream>

void Player::start(){
    std::cout << "Player" << std::endl;
}

void Player::update(float dt){

}

void Player::draw(sf::RenderTarget& target){
    shape.setSize({50, 50});
    shape.setFillColor(sf::Color::Red);

    target.draw(shape);
}

