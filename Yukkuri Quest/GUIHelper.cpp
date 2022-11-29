#include "GUIHelper.h"

void DrawButton(Rectangle rect, Color backColor, const char* text, int fontSize, Color textCol)
{
	DrawRectangleRec(rect, backColor);
	DrawText(text, rect.x + (rect.width - MeasureText(text, fontSize)) / 2, rect.y + (rect.height - fontSize) / 2, fontSize, textCol);
}

bool IsButtonClicked(Vector2 mousePos, Rectangle rect, MouseButton button)
{
	if (CheckCollisionPointRec(mousePos, rect)) {
		return IsMouseButtonPressed(button);
	}

	return false;
}
