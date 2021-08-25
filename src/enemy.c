#include "enemy.h"

struct Enemy Enemy_init(float x, float y)
{
	struct Enemy self = { {x, y}, {0, 0}, {15, 120} };
	return self;
}

void Enemy_setRelVelocity(struct Enemy* self, struct Ball* ball)
{
	if (ball->location.y > (self->location.y + (self->size.y / 2)))
	{
		self->velocity.y = 2.1f;
	}
	else if (ball->location.y < (self->location.y + (self->size.y / 2)))
	{
		self->velocity.y = -2.1f;
	}
	else
	{
		self->velocity.y = 0;
	}
}

void Enemy_update(struct Enemy* self, struct Ball* ball)
{
	self->location.y += self->velocity.y;
	Enemy_setRelVelocity(self, ball);
}

void Enemy_render(struct Enemy* self)
{
	DrawRectangleV(self->location, self->size, WHITE);
}