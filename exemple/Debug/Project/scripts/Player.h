#pragma once

#include <object.h>

class Player : public Object {
public:
	void start() override;
	void update() override;
	void render() override;
};

void Start();
