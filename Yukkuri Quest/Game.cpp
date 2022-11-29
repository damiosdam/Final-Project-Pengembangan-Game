#include "Game.h"

Menu Game::currentMenu = Menu::TotalMenu;
bool Game::exitWindow = false;

void Game::setCurrentMenu(Menu menu)
{
	currentMenu = menu;
}

void Game::ExitWindow()
{
	exitWindow = true;
}

void Game::Init(const char* windowTitle, int width, int height, int FPS)
{ 
	InitWindow(width, height, windowTitle);
	gameplay.loadTexture();

	SetTargetFPS(FPS);

	SetExitKey(0);

	this->setCurrentMenu(Menu::TitleMenu);
}

void Game::Run()
{
	while (!exitWindow) {
		if (WindowShouldClose())
			exitWindow = true;

		HandleInputs();
		Update();
		Draw();
	}
}

void Game::Clean()
{
	CloseWindow();
}

void Game::HandleInputs()
{
	switch (currentMenu)
	{
	case Menu::GameplayMenu:
		gameplay.HandleInputs();
		break;
	case Menu::TitleMenu:
		title.HandleInputs();
		break;
	case Menu::OptionMenu:
		option.HandleInputs();
		break;
	default:
		break;
	}
}

void Game::Update()
{
	// Update Game
	switch (currentMenu)
	{
	case Menu::GameplayMenu:
		gameplay.Update();
		break;
	case Menu::TitleMenu:
		title.Update();
		break;
	case Menu::OptionMenu:
		option.Update();
		break;
	default:
		break;
	}
}

void Game::Draw()
{
	BeginDrawing();

	ClearBackground(RAYWHITE);

	switch (currentMenu)
	{
	case Menu::GameplayMenu:
		gameplay.Draw();
		break;
	case Menu::TitleMenu:
		title.Draw();
		break;
	case Menu::OptionMenu:
		option.Draw();
		break;
	default:
		break;
	}

	EndDrawing();
}
