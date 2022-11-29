#pragma once

#include "Menu.h"

class Option
{
public:
	Option();

	void Open();
	void Close(Menu nextMenu);

	void HandleInputs();
	void Update();
	void Draw();
private:
	int BGM_vol;
	int SE_vol;

	Rectangle TitleButtonRect;
};

