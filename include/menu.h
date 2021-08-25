#ifndef MENU_H
#define MENU_H

#include <string.h>

#include "button.h"

struct Menu
{
	char title[20];
	struct Button button;
};

struct Menu Menu_init();

void Menu_update(struct Menu* self);
void Menu_render(struct Menu* self);

#endif // !MENU_H
