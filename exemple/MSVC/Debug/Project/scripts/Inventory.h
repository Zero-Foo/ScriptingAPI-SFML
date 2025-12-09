#pragma once

#include <object.h>

class Inventory : public Object {
public:
	void start() override;
	void update() override;
	void render() override;
};

