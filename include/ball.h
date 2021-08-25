#ifndef BALL_H
#define BALL_H

#include <raylib.h>

struct Ball
{
	Vector2 location;
	Vector2 velocity;
	float radius;
};

struct Ball Ball_init(float x, float y);

void Ball_update(struct Ball* self);
void Ball_render(struct Ball* self);

#endif // !BALL_H
