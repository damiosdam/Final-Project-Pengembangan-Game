#include "Tile.h"

#include <fstream>
#include <string>
#include <iostream>

Tile::Tile()
{
	texture = Texture();
}

void Tile::loadTexture(const char* filepath)
{
	texture = LoadTexture(filepath);
}

void Tile::Draw(int x, int y)
{
	DrawTexture(texture, x, y, WHITE);
}