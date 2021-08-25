#include "collision.h"

int Button_isHovered(struct Button* self, Vector2 mouse)
{
	if (mouse.x >= self->location.x &&
		mouse.x <= self->location.x + self->size.x &&
		mouse.y >= self->location.y &&
		mouse.y <= self->location.y + self->size.y)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int Player_isColliding(struct Ball* self, struct Player* other)
{
	if (self->location.x >= other->location.x &&
		self->location.x <= other->location.x + other->size.x &&
		self->location.y >= other->location.y &&
		self->location.y <= other->location.y + other->size.y)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int Enemy_isColliding(struct Ball* self, struct Enemy* other)
{
	if (self->location.x >= other->location.x &&
		self->location.x <= other->location.x + other->size.x &&
		self->location.y >= other->location.y &&
		self->location.y <= other->location.y + other->size.y)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}