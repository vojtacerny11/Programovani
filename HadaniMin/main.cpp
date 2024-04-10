#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "raylib.h"
#include <deque>

#define ScreenHeight 600
#define ScreenWidth 600
#define PixelSize 60
#define PixelCount 10

using namespace std;

Color Blue{ 0, 0, 255, 255 };
Color DarkGreen{ 40, 55, 25, 255 };
Color Black{ 0, 0, 0, 255 };

class Mine {
public:
	int random = rand() % 9 + 1;
	int random2 = rand() % 9 + 1;
	deque<Vector2> bomb = { Vector2{(float)random, (float)random2}, Vector2{(float)random2, (float)random} };
	void Draw()
	{
		for (int i = 0; i < 2; i++)
		{
			float x = bomb[i].x;
			float y = bomb[i].y;
			DrawCircle(PixelSize * x, PixelSize * y, 25.0f, Black);
		}
	}
};

int main()
{
	srand(time(NULL));
	InitWindow(ScreenHeight, ScreenWidth, "SnazSeNekliknoutNaMinu");
	SetTargetFPS(165);

	Mine bomb = Mine();

	while (WindowShouldClose() == 0)
	{
		BeginDrawing();

		ClearBackground(Blue);
		
		bomb.Draw();

		EndDrawing();
	}

	return 0;
}