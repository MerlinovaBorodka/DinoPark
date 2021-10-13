#pragma once

#include "anim_sprite.h"

using namespace std;

class Player : public DirectedSprite
{
public:
	int speed;
	Player() : speed(1) {}
	Player(string spriteSrc,
		int frameCount,
		int x = 0, int y = 0,
		string direction = "right",
		int hp = 3, int sp = 1)
		:DirectedSprite(spriteSrc, frameCount, x, y, direction),
		speed(sp)
	{}

	void goLeft()
	{
		if (x > speed) x -= speed;
	}
	void goRight()
	{
		x += speed;
	}
	void goUp()
	{
		if (y > speed) y -= speed;
	}
	void goDown()
	{
		y += speed;
	}
};