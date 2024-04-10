#include <stdio.h>
#include "raylib.h"
#include <deque>
#include <raymath.h>

using namespace std;

Color Red{ 255, 0, 0, 255 };
Color Green{ 0, 255, 0, 255 };
Color Blue{ 0, 0, 255, 255 };
Color DarkGreen{ 40, 55, 25, 255 };

int pixelsize = 25;
int pixelcount = 25;

class Food {
	
public:
	Vector2 position = { 5, 6 };

	void DrawFood()
	{
		DrawCircle(pixelsize * position.x, pixelsize * position.y, 12.0f, Red);
	}
};

class Snake {
public:
	deque<Vector2>Telo = { Vector2{ 7, 12 }, Vector2{ 8, 12}, Vector2{ 9, 12}};
	Vector2 direction = { 1, 0 };

	void DrawSnake()
	{
		for (int i = 0; i < Telo.size(); i++)
		{
			float x = Telo[i].x;
			float y = Telo[i].y;
			Rectangle segment = Rectangle{ x * pixelsize, y * pixelsize, (float)pixelsize, (float)pixelsize };
			DrawRectangleRounded(segment, 0.5, 6, DarkGreen);
		}
	}

	void UpdateSnake()
	{
		Telo.pop_back();
		Telo.push_front(Vector2Add(Telo[0], direction));
	}
};


int main()
{
	InitWindow(pixelsize * pixelcount, pixelsize * pixelcount, "snake");
	SetTargetFPS(30);

	Food food = Food();

	Snake snake = Snake();
	while (WindowShouldClose() == false)
	{
		BeginDrawing();
		
		ClearBackground(Green);


		food.DrawFood();

		snake.DrawSnake();

		snake.UpdateSnake();

		EndDrawing();
	}

	CloseWindow();
	return 0;
}