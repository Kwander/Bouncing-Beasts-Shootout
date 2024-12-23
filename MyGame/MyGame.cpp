#include "Quad.h"
#include "Level.h"
#include "GoblinLevel.h"
#include "Gun.h"
#include "CatLevel.h"
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

		// Initialize guns with different fire rates and damage
		guns.push_back(std::make_unique<Gun>("Assets/gun1hold.png", "Assets/gun1fire.png", 0.4f, 1)); // Faster pistol
		guns.push_back(std::make_unique<Gun>("Assets/gun2hold.png", "Assets/gun2fire.png", 0.2f, 1)); // Fast, 1 damage
		guns.push_back(std::make_unique<Gun>("Assets/gun3hold.png", "Assets/gun3fire.png", 0.7f, 3)); // Slower AWP
		guns.push_back(std::make_unique<Gun>("Assets/gun4hold.png", "Assets/gun4fire.png", 0.1f, 1)); // Fast, 1 damage UZI
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
		}
		else
		{
			currentLevel->Update();
			currentLevel->Draw();

			// Only draw gun if we're not in a game over or level cleared state
			if (GoblinLevel *goblinLevel = dynamic_cast<GoblinLevel *>(currentLevel.get()))
			{
				if (!goblinLevel->IsGameOver() && !goblinLevel->IsLevelCleared())
				{
					guns[currentGunIndex]->Update();
					guns[currentGunIndex]->Draw();
				}
			}
			else if (CatLevel *catLevel = dynamic_cast<CatLevel *>(currentLevel.get()))
			{
				if (!catLevel->IsGameOver() && !catLevel->IsLevelCleared())
				{
					guns[currentGunIndex]->Update();
					guns[currentGunIndex]->Draw();
				}
			}

			// Check for level completion or game over
			if (GoblinLevel *goblinLevel = dynamic_cast<GoblinLevel *>(currentLevel.get()))
			{
				if (goblinLevel->IsGameOver() && cursor.IsClicking() && goblinLevel->CanTransition())
				{
					isStartScreen = true;
					startScreenTimer = 0.0f;
					currentLevel = std::make_unique<GoblinLevel>();
				}
				else if (goblinLevel->IsLevelCleared() && cursor.IsClicking() && goblinLevel->CanTransition())
				{
					currentLevel = std::make_unique<CatLevel>();
				}
			}
			else if (CatLevel *catLevel = dynamic_cast<CatLevel *>(currentLevel.get()))
			{
				if (catLevel->IsGameOver() && cursor.IsClicking() && catLevel->CanTransition())
				{
					isStartScreen = true;
					startScreenTimer = 0.0f;
					currentLevel = std::make_unique<GoblinLevel>();
				}
			}

			// Handle shooting
			if (cursor.IsClicking())
			{
				if (GoblinLevel *goblinLevel = dynamic_cast<GoblinLevel *>(currentLevel.get()))
				{
					goblinLevel->HandleClick(cursor, guns[currentGunIndex]->CanFire(), guns[currentGunIndex]->GetDamage());
				}
				else if (CatLevel *catLevel = dynamic_cast<CatLevel *>(currentLevel.get()))
				{
					catLevel->HandleClick(cursor, guns[currentGunIndex]->CanFire(), guns[currentGunIndex]->GetDamage());
				}
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
			case QUAD_KEY_H: // Keep health test
				currentLevel->SetPlayerHealth(currentLevel->GetPlayerHealth() - 10);
				break;
			}
		}
	}
};

QUAD_GAME_START(MyGameApplication)