#ifndef ENEMY_H
#define ENEMY_H

#include <raylib.h>

#include "ball.h"

struct Enemy
{
	Vector2 location;
	Vector2 velocity;
	Vector2 size;
};

struct Enemy Enemy_init(float x, float y);

void Enemy_setRelVelocity(struct Enemy* self, struct Ball* ball);

void Enemy_update(struct Enemy* self, struct Ball* ball);
void Enemy_render(struct Enemy* self);

#endif // !ENEMY_H
