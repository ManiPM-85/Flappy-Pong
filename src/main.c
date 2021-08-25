#include <raylib.h>

#include "stage.h"

int main()
{
	InitWindow(600, 400, "Flappy Pong!");

	SetTargetFPS(60);

	struct Stage stage = Stage_init();

	while (!WindowShouldClose())
	{
		Stage_update(&stage);

		BeginDrawing();

		ClearBackground(BLACK);

		Stage_render(&stage);

		EndDrawing();
	}

	CloseWindow();

	return 0;
}