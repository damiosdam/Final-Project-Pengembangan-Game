#pragma once

#include <raylib.h>

class Tile
{
public:
	Tile();

	void loadTexture(const char* filepath);

	void Draw(int x, int y);

private:
	Texture texture;
};

