#include "stage.h"

struct Stage Stage_init()
{
	struct Stage self;

	self.currentStage = MENU;
	self.menu = Menu_init();
	self.game = Game_init();

	return self;
}

void Stage_update(struct Stage* self)
{
	switch (self->currentStage)
	{
	case MENU:
		Menu_update(&self->menu);
		if (Button_isPressed(&self->menu.button))
		{
			self->currentStage = GAME;
		}
		break;
	case GAME:
		Game_update(&self->game);
		Game_updateInput(&self->game);
		break;
	default:
		break;
	}
}

void Stage_render(struct Stage* self)
{
	switch (self->currentStage)
	{
	case MENU:
		Menu_render(&self->menu);
		break;
	case GAME:
		Game_render(&self->game);
		Game_UIRender(&self->game);
		break;
	default:
		break;
	}
}