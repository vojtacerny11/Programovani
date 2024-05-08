#include <stdio.h>
#include "raylib.h"
#include "raymath.h"
#include <vector>

#define ScreenHeight 900
#define ScreenWidth 1600

bool ShouldQuit = 0;

class ButtonPlay
{
	public:
		void Draw()
		{
			DrawRectangle(ScreenWidth / 2 - 75, ScreenHeight / 2 - 75, 150, 50, BLACK);
			DrawText("PLAY", ScreenWidth / 2 - 65, ScreenHeight / 2 - 75, 50, WHITE);
		}
};

class ButtonQuit
{
public:
	void Draw()
	{
		DrawRectangle(ScreenWidth / 2 - 75, ScreenHeight / 2 + 25, 150, 50, BLACK);
		DrawText("QUIT", ScreenWidth / 2 - 60, ScreenHeight / 2 + 25, 50, WHITE);
	}
};

int main()
{
	InitWindow(ScreenWidth, ScreenHeight, "Main Menu");
	SetTargetFPS(60);
	ButtonPlay play = ButtonPlay();
	ButtonQuit quit = ButtonQuit();
	while (!ShouldQuit && !WindowShouldClose())
	{
		BeginDrawing();
		play.Draw();
		quit.Draw();
		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
			int x = GetMouseX();
			int y = GetMouseY();
			if ((x > ScreenWidth / 2 - 75 && y > ScreenHeight / 2 - 75) && (x < ScreenWidth / 2 + 75 && y < ScreenHeight / 2 - 25))
				DrawText("CAU", 0, 0, 80, BLACK);
			if ((x > ScreenWidth / 2 - 75 && y > ScreenHeight / 2 + 25) && (x < ScreenWidth / 2 + 75 && y < ScreenHeight / 2 + 75))
				ShouldQuit = 1;
		}
		ClearBackground(RAYWHITE);
		EndDrawing();
	}
	CloseWindow();
}