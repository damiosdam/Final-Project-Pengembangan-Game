#include "Character.h"
#include <string>

Character::Character()
{
	position = { 0, 0 };
	velocity = { 0, 0 };

	playerState = FALLING;

	texture = Texture();
}

void Character::loadTexture(const char* filepath)
{
	texture = LoadTexture(filepath);
}

void Character::HandleInputs()
{
	velocity.x = 0;
	if (IsKeyDown(KEY_LEFT)) {
		velocity.x = -2;
	} else if (IsKeyDown(KEY_RIGHT)) {
		velocity.x = 2;
	}
	
	if (IsKeyDown(KEY_UP) && playerState == GROUND) {
		playerState = JUMPING;
	}
	else if (IsKeyDown(KEY_DOWN)) {
		velocity.y = 3;
	}
}

void Character::Update()
{
	switch (playerState)
	{
	case PLAYER_STATE::GROUND: 
		velocity.y = 0;
		break;
	case PLAYER_STATE::FALLING:
		if (velocity.y < 3) {
			velocity.y += 0.2f;
		}
		break;
	case PLAYER_STATE::JUMPING:
		if (velocity.y > -5 ) {
			velocity.y -= 0.2f;
		}
		else {
			playerState = FALLING;
		}
		break;
	default:
		break;
	}
	

	position.x += velocity.x;
	position.y += velocity.y;
}

void Character::Draw()
{
	DrawTexture(texture, position.x, position.y, WHITE);
}

Rectangle Character::CharRect()
{
	return { position.x, position.y, 50, 50 };
}

void Character::SetVelocityX(float val)
{
	velocity.x = val;
}

void Character::SetVelocityY(float val)
{
	velocity.y = val;
}

void Character::SetState(PLAYER_STATE state)
{
	playerState = state;
}

bool Character::OnGround()
{
	return playerState == PLAYER_STATE::GROUND;
}
