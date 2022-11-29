#pragma once

#include <raylib.h>

#include "Title.h"
#include "Option.h"
#include "Gameplay.h"

class Game
{
public:
	static void setCurrentMenu(Menu menu);

	static void ExitWindow();

public:
	void Init(const char* windowTitle, int width, int height, int FPS = 60);
	void Run();
	void Clean();

private:
	void HandleInputs();
	void Update();
	void Draw();

private:
	static Menu currentMenu;

	Title title;
	Option option;
	Gameplay gameplay;

	static bool exitWindow;
};