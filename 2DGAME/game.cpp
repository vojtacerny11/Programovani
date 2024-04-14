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

Texture2D sprite;
Texture2D spriteJablko;

Rectangle source = (Rectangle{ 0, 0, 235, 250 });
Rectangle source2 = (Rectangle{ 705, 250, 235, 250 });

Vector2 charPos = { SCREENWIDTH / 2 - CellWidth / 2, SCREENHEIGHT / 2 - CellHeight / 2 - 10 };

Music music;

bool foodVisible = 1;
bool facingRight = 1;
int nScore = 0;

int colNum = 0;

class Food
{
	public:
	int x = rand() % 5;
	int y = rand() % 3;
	Vector2 foodPos = { (float)x * CellWidth, (float)y * CellHeight };
	void DrawFood()
	{
		DrawTextureRec(spriteJablko, source, foodPos, WHITE);
	}
};

void GameOver()
{
	while (WindowShouldClose() == 0)
	{
		UpdateMusicStream(music);
		BeginDrawing();
		const char* cScore = TextFormat("SCORE: %d", nScore);
		DrawText("YOU LOST", SCREENWIDTH / 2 - 225 / 2, SCREENHEIGHT / 2 - 50, 50, BLACK);
		DrawText(cScore, SCREENWIDTH / 2 - 200 / 2, SCREENHEIGHT / 2, 50, BLACK);
		ClearBackground(RAYWHITE);
		EndDrawing();
	}
}

int main()
{
	InitWindow(SCREENWIDTH, SCREENHEIGHT, "SLAYER2D");
	InitAudioDevice();
	sprite = LoadTexture("assets/person2.png");
	spriteJablko = LoadTexture("assets/Jablko2.png");
	SetTargetFPS(240);
	srand(time(0));
	Food food = Food();
	music = LoadMusicStream("audio/Night.mp3");
	PlayMusicStream(music);
	while (WindowShouldClose() == 0)
	{
		UpdateMusicStream(music);
		BeginDrawing();
		if ((food.foodPos.x != charPos.x || food.foodPos.y != charPos.y))
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
			if (charPos.x < 0 || charPos.y < 0 || charPos.x == SCREENWIDTH || charPos.y >= SCREENHEIGHT - CellHeight)
			{
				break;
			}
			if (food.foodPos.x == charPos.x && food.foodPos.y == charPos.y && colNum % 2 == 0)
			{
				nScore = +1;
				foodVisible = 0;
			}
			if (food.foodPos.x == charPos.x && food.foodPos.y == charPos.y && colNum % 2 == 1)
			{
				nScore = +1;
				foodVisible = 0;
			}
		ClearBackground(GREEN);

		EndDrawing();
	}
	GameOver();

	CloseAudioDevice();

	CloseWindow();
}