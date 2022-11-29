#pragma once

#include <raylib.h>

const int TINGGI_KARAKTER = 50;
const int LEBAR_KARAKTER = 50;

enum PLAYER_STATE {
	GROUND,
	FALLING,
	JUMPING
};

class Character
{
public:
	Character();

	void loadTexture(const char* filepath);

	void HandleInputs();
	void Update();
	void Draw();

	Rectangle CharRect();

	void SetVelocityX(float val);
	void SetVelocityY(float val);

	void SetState(PLAYER_STATE state);
	bool OnGround();

private:
	Texture texture;

	Vector2 position;
	Vector2 velocity;
	
	PLAYER_STATE playerState;
};