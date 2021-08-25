#ifndef PLAYER_H
#define PLAYER_H

#include <stdio.h>

#include <raylib.h>

struct Player
{
	Vector2 location;
	Vector2 velocity;
	Vector2 size;
};

struct Player Player_init(float x, float y);

void Player_jump(struct Player* self);

void Player_update(struct Player* self);
void Player_render(struct Player* self);

#endif // !PLAYER_H
