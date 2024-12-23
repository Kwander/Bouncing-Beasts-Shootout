#include "Quad.h"
#include "Level.h"
#include <iostream>

class MyGameApplication : public Quad::QuadApplication
{
	virtual void Initialize() override
	{
		QUAD_LOG("Starting...");
		SetKeyEventHandler([this](const Quad::KeyEvent &event)
						   { MyKeysHandler(event); });
		currentLevel = std::make_unique<GoblinLevel>();
	}

	virtual void Update() override
	{
		if (isStartScreen)
		{
			Quad::Renderer::Draw(startScreen);
			if (cursor.IsClickingOn(startScreen))
			{
				isStartScreen = false;
			}
		}
		else
		{
			currentLevel->Update();
			currentLevel->Draw();
			Quad::Renderer::Draw(hero);
		}
	}

private:
	bool isStartScreen{true};
	Quad::Unit startScreen{"Assets/START_SCREEN.png", 0, 0};
	Quad::Unit hero{"../Quad/QuadAssets/Images/cookie.jpg", 100, 100};
	Quad::Cursor cursor;
	std::unique_ptr<Level> currentLevel;

	void MyKeysHandler(const Quad::KeyEvent &event)
	{
		if (!isStartScreen && event.GetKeyAction() == Quad::KeyEvent::KeyAction::Press)
		{
			switch (event.GetKeyCode())
			{
			case QUAD_KEY_LEFT:
				hero.UpdateXCoord(-10);
				break;
			case QUAD_KEY_RIGHT:
				hero.UpdateXCoord(10);
				break;
			case QUAD_KEY_H: // Test health decrease
				currentLevel->SetPlayerHealth(currentLevel->GetPlayerHealth() - 10);
				break;
			}
		}
	}
};

QUAD_GAME_START(MyGameApplication)