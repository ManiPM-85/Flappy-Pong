#include "player.h"

struct Player Player_init(float x, float y)
{
	struct Player self = { {x, y}, {0, 0}, {15, 120} };
	return self;
}

void Player_jump(struct Player* self)
{
	self->velocity.y = -8.0f;
}

void Player_update(struct Player* self)
{
	self->velocity.y += 0.4f;
	self->location.y += self->velocity.y;
}

void Player_render(struct Player* self)
{
	DrawRectangleV(self->location, self->size, WHITE);
}