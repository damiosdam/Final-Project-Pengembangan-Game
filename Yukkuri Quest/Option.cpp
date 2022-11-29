#include "Option.h"

#include "Game.h"

#include "GUIHelper.h"

Option::Option()
{
    BGM_vol = 100;
    SE_vol = 100;

    TitleButtonRect.width = 150;
    TitleButtonRect.height = 50;
    TitleButtonRect.x = 400 - 75;
    TitleButtonRect.y = 600 - 80;
}

void Option::Open()
{
}

void Option::Close(Menu nextMenu)
{
    Game::setCurrentMenu(nextMenu);
}
void Option::HandleInputs()
{
    Vector2 mousePos = GetMousePosition();

    if (IsButtonClicked(mousePos, TitleButtonRect, MOUSE_BUTTON_LEFT)) {
        Close(Menu::TitleMenu);
    }
}

void Option::Update()
{
}

void Option::Draw()
{
    DrawText("OPTION", 400 - MeasureText("OPTION", 30) / 2, 50, 40, BLACK);

    DrawButton(TitleButtonRect, LIGHTGRAY, "Return", 30, BLACK);
}
