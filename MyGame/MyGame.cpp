#include "Quad.h"
#include <iostream>

class MyGameApplication : public Quad::QuadApplication
{
	virtual void Initialize() override
	{
		QUAD_LOG("Starting...");

		SetKeyEventHandler([this](const Quad::KeyEvent& event) {MyKeysHandler(event);  });
	}

	virtual void Update() override
	{
		Quad::Renderer::Draw(hero);
		// std::cout << "Running " << std::endl;
	}
private:
	Quad::Unit hero{ "../Quad/QuadAssets/Images/cookie.jpg", 100,100 };

	void MyKeysHandler(const Quad::KeyEvent& event) {
		if (event.GetKeyAction() == Quad::KeyEvent::KeyAction::Press) {
			switch (event.GetKeyCode()) {
			case QUAD_KEY_LEFT:
				hero.UpdateXCoord(-10);
				break;
			case QUAD_KEY_RIGHT:
				hero.UpdateXCoord(10);
				break;
			}
		}
	}

};

QUAD_GAME_START(MyGameApplication)