#include <stdio.h>
#include "raylib.h"
#include "raymath.h"
#include <vector>

using namespace std;

#define SCREENHEIGHT 192
#define SCREENWIDTH 192

int nHrac = 0;

const int PIXELHEIGHT = SCREENHEIGHT / 3;
const int PIXELWIDTH = SCREENWIDTH / 3;

Texture2D sprite;
Rectangle source = (Rectangle{ 64, 64, 64, 64 });
Rectangle source2 = (Rectangle{ 128, 128, 64, 64 });
Color Red{ 255, 0, 0, 255 };
Color Green{ 0, 255, 0, 255 };
Color Blue{ 0, 0, 255, 255 };
Color DarkGreen{ 40, 55, 25, 255 };

int MouseX;
int MouseY;

typedef struct Pole
{
	int i;
	int j;
	bool notrevealed;
	char value;
}Pole;

Pole grid[3][3];

void vypisPole(Pole pole)
{
	if (pole.notrevealed)
	{
		if (nHrac == 0)
		{
			DrawTextureRec(sprite, source, (Vector2{ (float)MouseX * PIXELWIDTH, (float)MouseY * PIXELHEIGHT }), BLACK);
		}
		else
		{
			DrawTextureRec(sprite, source2, (Vector2{ (float)MouseX * PIXELWIDTH, (float)MouseY * PIXELHEIGHT }), BLACK);
		}
	}
	DrawRectangleLines(pole.i * PIXELWIDTH, pole.j * PIXELHEIGHT, PIXELHEIGHT, PIXELHEIGHT, BLACK);
}

void PoleReveal(int i, int j)
{
	grid[i][j].notrevealed = 1;
}

int main()
{
	InitWindow(SCREENHEIGHT, SCREENWIDTH, "TicTacToe");
	SetTargetFPS(240);
	sprite = LoadTexture("assets/tic-tac.png");
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			grid[i][j] = (Pole{ .i = i, .j = j });
		}
	}
	while (WindowShouldClose() == 0)
	{
		BeginDrawing();
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				vypisPole(grid[i][j]);
			}
		}
		
		switch (nHrac)
		{
		case 0:
			if (IsMouseButtonPressed(0))
			{
				Vector2 MousePos = GetMousePosition();
				MouseX = MousePos.x / 64;
				MouseY = MousePos.y / 64;

				PoleReveal(MouseX, MouseY);
			}
			nHrac++;
			break;
		case 1:
			if (IsMouseButtonPressed(0))
			{
				Vector2 MousePos = GetMousePosition();
				MouseX = MousePos.x / 64;
				MouseY = MousePos.y / 64;

				PoleReveal(MouseX, MouseY);
			}
			nHrac--;
			break;
		}

		ClearBackground(RAYWHITE);

		EndDrawing();
	}
	CloseWindow();
	return 0;
}