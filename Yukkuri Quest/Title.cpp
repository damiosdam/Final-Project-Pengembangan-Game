#include "Title.h"

#include "Game.h"

#include "GUIHelper.h"

Title::Title()
{
	PlayGameRect.width = 200;
	PlayGameRect.height = 50;
	PlayGameRect.x = 300;
	PlayGameRect.y = 300;

	OptionGameRect.width = 200;
	OptionGameRect.height = 50;
	OptionGameRect.x = 300;
	OptionGameRect.y = 300 + 10 + 50;

	ExitGameRect.width = 200;
	ExitGameRect.height = 50;
	ExitGameRect.x = 300;
	ExitGameRect.y = 300 + 10 + 50 + 10 + 50;
}

void Title::Open()
{
}

void Title::Close(Menu nextMenu)
{
	Game::setCurrentMenu(nextMenu);
}

void Title::HandleInputs()
{
	Vector2 mousePos = GetMousePosition();

	if (IsButtonClicked(mousePos, PlayGameRect, MOUSE_BUTTON_LEFT)) {
		Close(Menu::GameplayMenu);
	}

	if (IsButtonClicked(mousePos, OptionGameRect, MOUSE_BUTTON_LEFT)) {
		Close(Menu::OptionMenu);
	}

	if (IsButtonClicked(mousePos, ExitGameRect, MOUSE_BUTTON_LEFT)) {
		Game::ExitWindow();
	}
}

void Title::Update()
{
}

void Title::Draw()
{
	int x = MeasureText("YUKKURI QUEST", 60);
	DrawText("YUKKURI QUEST", 400 - x / 2, 150, 60, BLACK);

	DrawButton(PlayGameRect, LIGHTGRAY, "PLAY", 30, BLACK);
	DrawButton(OptionGameRect, LIGHTGRAY, "OPTION", 30, BLACK);
	DrawButton(ExitGameRect, LIGHTGRAY, "EXIT", 30, BLACK);
}
