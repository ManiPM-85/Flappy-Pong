#ifndef BUTTON_H
#define BUTTON_H

#include <raylib.h>

#include <string.h>

#include "collision.h"

struct Button
{
	Vector2 location;
	Vector2 size;
	Color color;
	char text[10];
	int isMousePressed;
};

struct Button Button_init(const char* text, int x, int y);

int Button_isPressed(struct Button* self);

void Button_update(struct Button* self);
void Button_render(struct Button* self);

#endif // !BUTTON_H
