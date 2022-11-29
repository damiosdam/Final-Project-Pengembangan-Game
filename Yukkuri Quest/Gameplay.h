#pragma once

#include "Menu.h"

#include "Character.h"
#include "Tile.h"

#include <array>
#include <string>
#include <vector>

const int LEBAR_PETA = 16;
const int TINGGI_PETA = 12;

class Gameplay
{
public:
	Gameplay();

	void Open();
	void Close(Menu nextMenu);

	void HandleInputs();
	void Update();
	void Draw();

	void loadTexture();

private:
	void loadMap(int ID);
	void DrawMap();
	void UpdateMap();

	void HandleInputPausedMenu();
	void DrawPausedMenu();

private:
	bool CheckTopPlayer(Rectangle player, Rectangle tile);
	bool CheckBottomPlayer(Rectangle player, Rectangle tile);
	bool CheckSidePlayer(Rectangle player, Rectangle tile);

private:
	bool isPaused;

	Rectangle ToTitleRect;

	Tile grass;

	Character player;

	std::vector<std::string> currentMap;
	;
};

