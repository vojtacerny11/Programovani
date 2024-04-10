#include <stdio.h>
#include "raylib.h"
#include <vector>

#define PIXELHEIGHT 64
#define PIXELWIDTH 64

Texture2D atlas;
Rectangle source = (Rectangle{ 0, 0, 64, 64 });
Rectangle source2 = (Rectangle{ 64, 64, 64, 64 });
Rectangle source3 = (Rectangle{ 128, 128, 192, 292 });
Color Red{ 255, 0, 0, 255 };
Color Green{ 0, 255, 0, 255 };
Color Blue{ 0, 0, 255, 255 };
Color DarkGreen{ 40, 55, 25, 255 };

void Draw()
{
	DrawTextureRec(atlas, source, (Vector2{ 0, 0 }), WHITE);
	DrawTextureRec(atlas, source, (Vector2{ 64, 0 }), WHITE);
	DrawTextureRec(atlas, source, (Vector2{ 128, 0 }), WHITE);
	DrawTextureRec(atlas, source, (Vector2{ 0, 64 }), WHITE);
	DrawTextureRec(atlas, source, (Vector2{ 64, 64 }), WHITE);
	DrawTextureRec(atlas, source, (Vector2{ 128, 64 }), WHITE);
	DrawTextureRec(atlas, source, (Vector2{ 0, 128 }), WHITE);
	DrawTextureRec(atlas, source, (Vector2{ 64, 128 }), WHITE);
	DrawTextureRec(atlas, source, (Vector2{ 128, 128 }), WHITE);
}

int main()
{
	InitWindow(3 * PIXELWIDTH, 3 * PIXELHEIGHT, "TicTacToe");
	SetTargetFPS(30);
	atlas = LoadTexture("assets/tic-tac.png");

	while (WindowShouldClose() == 0)
	{
		BeginDrawing();

		ClearBackground(DarkGreen);
		Draw();

		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
		{
			DrawTextureRec(atlas, source2, (Vector2{ 0, 0 }), WHITE);
		}
		EndDrawing();
	}
	CloseWindow();
	return 0;
}