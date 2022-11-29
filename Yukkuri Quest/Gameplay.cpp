#include "Gameplay.h"

#include "Game.h"

#include <string>

#include "GUIHelper.h"

Gameplay::Gameplay() : grass()
{
	isPaused = false;

	ToTitleRect.width = 300;
	ToTitleRect.height = 50;
	ToTitleRect.x = 250;
	ToTitleRect.y = 400;

	currentMap = std::vector<std::string>();

	loadMap(1);
}

void Gameplay::Open()
{
}

void Gameplay::Close(Menu nextMenu)
{
	isPaused = false;
	loadMap(1);

	Game::setCurrentMenu(nextMenu);
}

void Gameplay::HandleInputs()
{
	if (IsKeyPressed(KEY_ESCAPE)) {
		isPaused = !isPaused;
	}

	if (!isPaused) {
		player.HandleInputs();
	}
	else {
		HandleInputPausedMenu();
	}
}

void Gameplay::Update()
{
	if (!isPaused) {
		player.Update();
		UpdateMap();
	}
}

void Gameplay::Draw()
{
	DrawMap();
	player.Draw();
	if (isPaused) {
		DrawPausedMenu();
	}
}

void Gameplay::loadTexture()
{
	grass.loadTexture("resource/tile/grass.png");
	player.loadTexture("resource/tile/player.png");
}

void Gameplay::loadMap(int ID)
{
	switch (ID)
	{
	case 0: // PETA KOSONG
		currentMap.push_back("0000000000000000"); // Line 1
		currentMap.push_back("0000000000000000"); // Line 2
		currentMap.push_back("0000000000000000"); // Line 3
		currentMap.push_back("0000000000000000"); // Line 4
		currentMap.push_back("0000000000000000"); // Line 5
		currentMap.push_back("0000000000000000"); // Line 6
		currentMap.push_back("0000000000000000"); // Line 7
		currentMap.push_back("0000000000000000"); // Line 8
		currentMap.push_back("0000000000000000"); // Line 9
		currentMap.push_back("0000000000000000"); // Line 10
		currentMap.push_back("0000000000000000"); // Line 11
		currentMap.push_back("0000000000000000"); // Line 12
	case 1: // PETA Dasar
		currentMap.push_back("0000000000000000"); // Line 1
		currentMap.push_back("0000000000000000"); // Line 2
		currentMap.push_back("0000000000000000"); // Line 3
		currentMap.push_back("0000000000000000"); // Line 4
		currentMap.push_back("0000000000000000"); // Line 5
		currentMap.push_back("0000000000000000"); // Line 6
		currentMap.push_back("1111111111111111"); // Line 7
		currentMap.push_back("1111111111111111"); // Line 8
		currentMap.push_back("1111111111111111"); // Line 9
		currentMap.push_back("1111111111111111"); // Line 10
		currentMap.push_back("1111111111111111"); // Line 11
		currentMap.push_back("1111111111111111"); // Line 12
	default:
		break;
	}
}

void Gameplay::DrawMap()
{
	for (int i = 0; i < TINGGI_PETA; i++) {
		for (int j = 0; j < LEBAR_PETA; j++) {
			switch (currentMap[i][j]) {
			case '1':
				grass.Draw(50 * j, 50 * i);
				break;
			case '0':
			default:
				break;
			}
		}
	}
}

void Gameplay::UpdateMap()
{
	for (int i = 0; i < TINGGI_PETA; i++) {
		for (int j = 0; j < LEBAR_PETA; j++) {
			Rectangle curRect = { j * 50, i * 50, 50, 50 };
			std::string a = "" + currentMap[i][j];
			switch (currentMap[i][j]) {
			case '1':
				// Top Check
				
				// Bottom Check
				if (CheckCollisionRecs(player.CharRect(), curRect)) {
					player.SetState(PLAYER_STATE::GROUND);
				}
				// Side Check

				break;
			case '0':
			default:
				break;
			}
		}
	}
}

void Gameplay::HandleInputPausedMenu()
{
	Vector2 mousePos = GetMousePosition();

	if (IsButtonClicked(mousePos, ToTitleRect, MOUSE_BUTTON_LEFT)) {
		Close(Menu::TitleMenu);
	}
}

void Gameplay::DrawPausedMenu()
{
	DrawText("PRESS ESC TO RETURN", (800 - MeasureText("PRESS ESC TO RETURN", 20)) / 2, 100, 20, BLACK);
	DrawButton(ToTitleRect, LIGHTGRAY, "Return to Title", 30, BLACK);
}

bool Gameplay::CheckTopPlayer(Rectangle player, Rectangle tile)
{
	Vector2 playerLeftTop = { player.x, player.y };
	Vector2 playerRightTop = { player.x + player.width, player.y };

	Vector2 tileLeftBottom = { tile.x, tile.y + tile.height};
	Vector2 tileRightBottom = { tile.x + tile.width, tile.y + tile.height };
	return CheckCollisionLines(playerLeftTop, playerRightTop, tileLeftBottom, tileRightBottom, 0);
}

bool Gameplay::CheckBottomPlayer(Rectangle player, Rectangle tile)
{
	Vector2 playerLeftBottom = { player.x, player.y + player.height };
	Vector2 playerRightBottom = { player.x + player.width, player.y + player.height };

	Vector2 tileLeftTop = { tile.x, tile.y };
	Vector2 tileRightTop = { tile.x + tile.width, tile.y };
	
	return false;
}

bool Gameplay::CheckSidePlayer(Rectangle player, Rectangle tile)
{
	return false;
}