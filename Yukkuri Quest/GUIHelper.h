#pragma once

#include <raylib.h>

void DrawButton(Rectangle rect, Color backColor, const char* text, int fontSize, Color textCol);
bool IsButtonClicked(Vector2 mousePos, Rectangle rect, MouseButton button);