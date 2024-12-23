#include "Quad.h"
#include "Level.h"
#include "GoblinLevel.h"
#include "Gun.h"
#include <vector>
#include <memory>

class MyGameApplication : public Quad::QuadApplication
{
	virtual void Initialize() override
	{
		QUAD_LOG("Starting...");
		SetKeyEventHandler([this](const Quad::KeyEvent &event)
						   { MyKeysHandler(event); });
		currentLevel = std::make_unique<GoblinLevel>();

		// Initialize guns
		guns.push_back(std::make_unique<Gun>("Assets/gun1hold.png", "Assets/gun1fire.png"));
		guns.push_back(std::make_unique<Gun>("Assets/gun2hold.png", "Assets/gun2fire.png"));
		guns.push_back(std::make_unique<Gun>("Assets/gun3hold.png", "Assets/gun3fire.png"));
		guns.push_back(std::make_unique<Gun>("Assets/gun4hold.png", "Assets/gun4fire.png"));
		currentGunIndex = 0;
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
			guns[currentGunIndex]->Draw();

			if (cursor.IsClicking())
			{
				guns[currentGunIndex]->TriggerFire();
			}
			else
			{
				guns[currentGunIndex]->SetFiring(false);
			}
		}
	}

private:
	bool isStartScreen{true};
	Quad::Unit startScreen{"Assets/START_SCREEN.png", 0, 0};
	Quad::Cursor cursor;
	std::unique_ptr<Level> currentLevel;
	std::vector<std::unique_ptr<Gun>> guns;
	size_t currentGunIndex;

	void MyKeysHandler(const Quad::KeyEvent &event)
	{
		if (!isStartScreen && event.GetKeyAction() == Quad::KeyEvent::KeyAction::Press)
		{
			switch (event.GetKeyCode())
			{
			case QUAD_KEY_1:
				currentGunIndex = 0;
				break;
			case QUAD_KEY_2:
				currentGunIndex = 1;
				break;
			case QUAD_KEY_3:
				currentGunIndex = 2;
				break;
			case QUAD_KEY_4:
				currentGunIndex = 3;
				break;
			case QUAD_KEY_H: // Keep health test
				currentLevel->SetPlayerHealth(currentLevel->GetPlayerHealth() - 10);
				break;
			}
		}
	}
};

QUAD_GAME_START(MyGameApplication)