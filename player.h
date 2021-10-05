#pragma once

#include "anim_sprite.h"

using namespace std;

class Player : public DirectedSprite
{
public:
	int hp, speed, hungry;
	Player() : hp(100), speed(1), hungry(0) {}
	Player(string spriteSrc,
		int frameCount,
		int x = 0, int y = 0,
		string direction = "right",
		int hp = 100, int sp = 1, int hun = 0)
		:DirectedSprite(spriteSrc, frameCount, x, y, direction),
		hp(hp), speed(sp), hungry(hun)
	{}

	void goLeft()
	{
		if (x > speed) 
		{
			x -= speed;
			hungry++;
		}
		if (hungry == 10) hp--;
	}
	void goRight()
	{
		x += speed; hungry++;
		if (hungry == 10) hp--;
	}
	void goUp()
	{
		if (y > speed) 
		{
			y -= speed;
			hungry++;
		}
		if (hungry == 10) hp--;
	}
	void goDown()
	{
		y += speed; hungry++;
		if (hungry == 10) hp--;
	}
};