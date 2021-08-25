#ifndef STAGE_H
#define STAGE_H

#include "menu.h"
#include "game.h"

enum Stages
{
	GAME,
	MENU
};

struct Stage
{
	enum Stages currentStage;
	struct Menu menu;
	struct Game game;
};

struct Stage Stage_init();

void Stage_update(struct Stage* self);
void Stage_render(struct Stage* self);

#endif // !STAGE_H
