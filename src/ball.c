#include "ball.h"

struct Ball Ball_init(float x, float y)
{
	struct Ball self = { {x, y}, {2.5f, 2.5f}, 8 };
	return self;
}

void Ball_update(struct Ball* self)
{
	self->location.x += self->velocity.x;
	self->location.y += self->velocity.y;
	if (self->location.y >= 400)
	{
		self->velocity.y *= -1;
	}
	if (self->location.y <= 0)
	{
		self->velocity.y *= -1;
	}
}

void Ball_render(struct Ball* self)
{
	DrawCircleV(self->location, self->radius, WHITE);
}