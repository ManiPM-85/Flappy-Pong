#include "button.h"

struct Button Button_init(const char* text, int x, int y)
{
	struct Button self = { {x, y}, {150, 70}, BLACK };

	strcpy(self.text, text);

	return self;
}

int Button_isPressed(struct Button* self)
{
	return self->isMousePressed;
}

void Button_update(struct Button* self)
{
	if (Button_isHovered(self, GetMousePosition()))
	{
		self->color = DARKGRAY;
		SetMouseCursor(MOUSE_CURSOR_POINTING_HAND);
	}
	else
	{
		self->color = BLACK;
		SetMouseCursor(MOUSE_CURSOR_ARROW);
	}

	if (Button_isHovered(self, GetMousePosition()) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
	{
		self->isMousePressed = 1;
		SetMouseCursor(MOUSE_CURSOR_ARROW);
	}
	else
	{
		self->isMousePressed = 0;
	}
}

void Button_render(struct Button* self)
{
	DrawRectangleV(self->location, self->size, self->color);
	DrawText(self->text, self->location.x + 10, self->location.y + 12, 50, WHITE);
	DrawRectangleLinesEx((Rectangle){ self->location.x, self->location.y, self->size.x, self->size.y }, 7, WHITE);
}