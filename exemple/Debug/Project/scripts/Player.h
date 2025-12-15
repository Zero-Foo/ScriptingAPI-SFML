#pragma once

#include <object.h>

#include <SFML/Graphics/RectangleShape.hpp>

class Player : public Object {
public:
	void start() override;
	void update(float dt) override;
	void draw(sf::RenderTarget& target) override;
private:
	sf::RectangleShape shape;
};

