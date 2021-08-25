#ifndef GAME_H
#define GAME_H

#include <raylib.h>

#include "player.h"
#include "enemy.h"
#include "ball.h"

#include "collision.h"

struct Score
{
	int player;
	int enemy;
};

struct Game
{
	struct Score score;
	struct Player player;
	struct Enemy enemy;
	struct Ball ball;
};

struct Game Game_init();

void Game_update(struct Game* self);
void Game_updateInput(struct Game* self);

void Game_render(struct Game* self);
void Game_UIRender(struct Game* self);

void Game_reset(struct Game* self);

#endif // !GAME_H
