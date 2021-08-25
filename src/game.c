#include "game.h"

struct Game Game_init()
{
	struct Game self;

	self.score.player = 0;
	self.score.enemy = 0;

	self.player = Player_init(13, 100);
	self.enemy = Enemy_init(572, 100);
	self.ball = Ball_init(300, 200);

	return self;
}

void Game_update(struct Game* self)
{
	Player_update(&self->player);
	Ball_update(&self->ball);
	Enemy_update(&self->enemy, &self->ball);
	if (Player_isColliding(&self->ball, &self->player) || Enemy_isColliding(&self->ball, &self->enemy))
	{
		self->ball.velocity.x *= -1;
	}

	if (self->ball.location.x < (-2 * self->ball.radius) - 5)
	{
		self->score.enemy++;
		Game_reset(self);
	}
	else if(self->ball.location.x > 605)
	{
		self->score.player++;
		Game_reset(self);
	}
}

void Game_updateInput(struct Game* self)
{
	if (IsKeyPressed(KEY_SPACE))
	{
		Player_jump(&self->player);
	}
}

void Game_render(struct Game* self)
{
	DrawLine(300, 0, 300, 400, WHITE);
	Player_render(&self->player);
	Ball_render(&self->ball);
	Enemy_render(&self->enemy);
}

void Game_UIRender(struct Game* self)
{
	DrawText(TextFormat("%i  %i",self->score.player, self->score.enemy), 235, 0, 70, WHITE);
}

void Game_reset(struct Game* self)
{
	self->player.location.y = 100;
	self->enemy.location.y = 100;
	self->ball.location.x = 300;
	self->ball.location.y = 200;
}