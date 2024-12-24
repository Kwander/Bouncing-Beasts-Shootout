# Brief Description

Fight evil scourges in this three-level with increasingly tougher boys. switch between four weapons (using keys 1-4) as you battle through waves of goblins, ferocious cats, and terrifying monsters. Each weapon offers different tactical advantages - from rapid-fire mayhem to heavy-hitting power shots. While the challenge is real, mastering your arsenal is the key to survival.

## Unique Game Features

This game features a dynamic combat system with 4 unique weapons, each with distinct fire rates and damage profile. Switch instantly between loadouts using keys 1-4 for precise mouse-driven combat. It has gunshot wounds as bullet impacts and has three levels.

- **Goblin Level**: Basic enemies with simple side-to-side movement
- **Cat Level**: Fast, erratic-moving enemies that bounce around the screen
- **Monster Level**: Final challenge with tougher enemies

Enemies have different movement patterns and health points. They deal dmg ever 4 seconds they remain on the screen. A strong unique point is the visual feedback of the game, with a health display at the bottom left, multiple screens following a basic plot, bullet wounds, and game over and clear screens for every level.

`MyGameApplication` manages the core game loop, handling the start screen, weapon switching between 4 types, level transitions, and screen updates. The `Level` class (with three specialized subclasses for each stage) handles enemy spawning, player health, and screen transitions. The `Enemy` class controls individual enemy behavior, including movement patterns, health tracking, damage timing, and screen boundaries.

##### Inspiration: During class, my professor mentioned his admiration for a previous semester’s project that incorporated mouse support. This feedback, combined with the project description highlighting that an A+ would be awarded to projects evoking an "Oh, that's cool" reaction, as well as the fact that I needed a perfect score to graduate and avoid an extra term, became a strong motivator for me to add plenty of features and ellicit that reaction, which I believe it achieves on first playthrough.
