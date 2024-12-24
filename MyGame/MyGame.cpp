#include "Quad.h"
#include "Level.h"
#include "GoblinLevel.h"
#include "Gun.h"
#include "CatLevel.h"
#include "MonsterLevel.h"
#include <vector>
#include <memory>

class MyGameApplication : public Quad::QuadApplication
{
	virtual void Initialize() override
	{
		startScreen = Quad::Unit("Assets/goblin lvl/START_SCREEN.png", 0, 0);
		SetKeyEventHandler([this](const Quad::KeyEvent &event)
						   { MyKeysHandler(event); });

		guns.push_back(std::make_unique<Gun>("Assets/guns/gun1hold.png", "Assets/guns/gun1fire.png", 0.4f, 1));
		guns.push_back(std::make_unique<Gun>("Assets/guns/gun2hold.png", "Assets/guns/gun2fire.png", 0.2f, 1));
		guns.push_back(std::make_unique<Gun>("Assets/guns/gun3hold.png", "Assets/guns/gun3fire.png", 0.7f, 3));
		guns.push_back(std::make_unique<Gun>("Assets/guns/gun4hold.png", "Assets/guns/gun4fire.png", 0.1f, 1));
		currentGunIndex = 0;
	}

	virtual void Update() override
	{
		if (isStartScreen)
		{
			startScreenTimer += 1.0f / 60.0f;
			Quad::Renderer::Draw(startScreen);
			if (cursor.IsClicking() && startScreenTimer >= SCREEN_DELAY)
			{
				isStartScreen = false;
				currentLevel = std::make_unique<GoblinLevel>();
			}
			return;
		}

		currentLevel->Update();
		currentLevel->Draw();

		if (!currentLevel->IsGameOver() && !currentLevel->IsLevelCleared())
		{
			guns[currentGunIndex]->Update();
			guns[currentGunIndex]->Draw();
		}
		else if (currentLevel->CanTransition() && cursor.IsClicking())
		{
			if (currentLevel->IsGameOver())
			{
				isStartScreen = true;
				startScreenTimer = 0.0f;
				currentLevel = std::make_unique<GoblinLevel>();
			}
			else if (currentLevel->IsLevelCleared())
			{
				switch (currentLevel->GetType())
				{
				case Level::LevelType::GOBLIN:
					currentLevel = std::make_unique<CatLevel>();
					break;
				case Level::LevelType::CAT:
					currentLevel = std::make_unique<MonsterLevel>();
					break;
				}
			}
		}

		if (cursor.IsClicking())
		{
			currentLevel->HandleClick(cursor, guns[currentGunIndex]->CanFire(),
									  guns[currentGunIndex]->GetDamage());
			guns[currentGunIndex]->TriggerFire();
		}
	}

private:
	bool isStartScreen{true};
	Quad::Unit startScreen{"Assets/goblin lvl/START_SCREEN.png", 0, 0};
	Quad::Cursor cursor;
	std::unique_ptr<Level> currentLevel;
	std::vector<std::unique_ptr<Gun>> guns;
	size_t currentGunIndex;
	float startScreenTimer{0.0f};
	static constexpr float SCREEN_DELAY{2.0f};

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
			case QUAD_KEY_H: // health decrease test
				currentLevel->SetPlayerHealth(currentLevel->GetPlayerHealth() - 10);
				break;
			}
		}
	}
};

QUAD_GAME_START(MyGameApplication)