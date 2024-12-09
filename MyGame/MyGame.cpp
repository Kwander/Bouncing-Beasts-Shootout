#include "Quad.h"
#include <iostream>

class MyGameApplication : public Quad::QuadApplication {
	virtual void Initialize() override {
		QUAD_LOG("Starting...");
	}

	virtual void Update() override {
		//std::cout << "Running " << std::endl;
		

	}
};

QUAD_GAME_START(MyGameApplication)