#pragma once

#include <object.h>

class Inventory : public Object {
public:
	void start() override;
	void update(float dt);
	void render(sf::RenderTarget& target);
};

