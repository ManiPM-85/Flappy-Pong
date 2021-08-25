#include "menu.h"

struct Menu Menu_init()
{
	struct Menu self;

	strcpy(self.title, "Flappy Pong");
	self.button = Button_init("PLAY", 230, 250);

	return self;
}

void Menu_update(struct Menu* self)
{
	Button_update(&self->button);
}

void Menu_render(struct Menu* self)
{
	DrawText(self->title, 110, 60, 65, WHITE);
	Button_render(&self->button);
	DrawText("Mani Mahmoudi 2020", 220, 375, 19, WHITE);
}