#include <stdio.h>
#include "raylib.h"
#include "raymath.h"
#include <vector>
#include <time.h>

using namespace std;

#define SCREENWIDTH 1250
#define SCREENHEIGHT 725

#define CellHeight 235
#define CellWidth 250

Vector2 charPos = { SCREENWIDTH / 2 - CellWidth / 2, SCREENHEIGHT / 2 - CellHeight / 2 };
class Food
{
	public:
	int x = rand() % 5 + 1;
	int y = rand() % 3 + 1;
	Vector2 foodPos = { (float)x * CellWidth, (float)y * CellHeight };
	void DrawFood()
	{
		DrawCircle( x * CellWidth + CellWidth / 2, y * CellHeight + CellHeight / 2, 45.0f, RED);
	}
};


Texture2D sprite;

Rectangle source = (Rectangle{0, 0, 235, 250});
Rectangle source2 = (Rectangle{ 705, 250, 235, 250 });

bool facingRight = 1;

int main()
{
	InitWindow(SCREENWIDTH, SCREENHEIGHT, "SLAYER2D");
	sprite = LoadTexture("assets/person2.png");
	SetTargetFPS(240);
	srand(time(0));
	Food food = Food();
	while (WindowShouldClose() == 0)
	{
		BeginDrawing();
		food.DrawFood();
		if (facingRight)
			DrawTextureRec(sprite, source, charPos, WHITE);
		else
			DrawTextureRec(sprite, source2, charPos, WHITE);
			if (IsKeyPressed(KEY_D))
			{
				facingRight = 1;
				charPos.x += CellWidth;
				DrawTextureRec(sprite, source, charPos, WHITE);
				
			}
			if (IsKeyPressed(KEY_A))
			{
				facingRight = 0;
				charPos.x -= CellWidth;
				DrawTextureRec(sprite, source2, charPos, WHITE);
;
			}
			if (IsKeyPressed(KEY_S))
			{
				charPos.y += CellHeight;
				if (facingRight)
					DrawTextureRec(sprite, source, charPos, WHITE);
				else
					DrawTextureRec(sprite, source2, charPos, WHITE);
			}
			if (IsKeyPressed(KEY_W))
			{
				charPos.y -= CellHeight;
				DrawTextureRec(sprite, source, charPos, WHITE);
			}
		ClearBackground(GREEN);

		EndDrawing();
	}
	CloseWindow();
}