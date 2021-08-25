#ifndef COLLISION_H
#define COLLISION_H

#include <raylib.h>

#include "button.h"
#include "player.h"
#include "enemy.h"
#include "ball.h"

int Button_isHovered(struct Button* self, Vector2 mouse);
int Player_isColliding(struct Ball* self, struct Player* other);
int Enemy_isColliding(struct Ball* self, struct Enemy* other);

#endif // !COLLISION_H
