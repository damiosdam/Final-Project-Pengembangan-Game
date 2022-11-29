#pragma once

#include "Menu.h"

class Title
{
public:
	Title();

	void Open();
	void Close(Menu nextMenu);

	void HandleInputs();
	void Update();
	void Draw();
private:
	Rectangle PlayGameRect;
	Rectangle OptionGameRect;
	Rectangle ExitGameRect;
};

