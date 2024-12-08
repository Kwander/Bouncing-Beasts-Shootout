#include "Quad.h"
#include <iostream>

class MyGameApplication : public Quad::QuadApplication {
	virtual void Initialize() override {
		std::cout << "Starting..." << std::endl;
	}

	virtual void Update() override {
		//std::cout << "Running " << std::endl;

	}
};

QUAD_GAME_START(MyGameApplication)