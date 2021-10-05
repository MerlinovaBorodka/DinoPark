// Подключаем файл строго 1 раз
// (даже если будет несколько #include)
#pragma once

#include "anim_sprite.h"

using namespace std;

/*******************************************************
  Направленный спрайт.

  Это разновиднойсть анимированного спрайта, который может
  содержать в себе не просто набор картинок, а еще и контролировать
  направление движения и выводить кадр из коллекции
  именно этого направления движения
*******************************************************/
class DirectedSprite : public AnimSprite
{
private:
	vector <Picture> framesRight;
	vector <Picture> framesLeft;

protected:
	string direction = "right";

public:
	DirectedSprite() {}
	DirectedSprite(string spriteSrc, int frameCount, int x = 0, int y = 0, string direction = "right")
	{
		this->x = x;
		this->y = y;

		framesRight.resize(frameCount);
		for (int i = 0; i < frameCount; i++)
		{
			char num = i + 1 + '0';
			framesRight[i] = Picture(spriteSrc + "/right/" + num);
		}
		framesLeft.resize(frameCount);
		for (int i = 0; i < frameCount; i++)
		{
			char num = i + 1 + '0';
			framesLeft[i] = Picture(spriteSrc + "/left/" + num);
		}
		drawFrame(direction, currentFrame);
	}

	void drawFrame(string direction, int n) 
	{
		if (direction == "right") framesRight[n - 1].draw(x, y);
		else framesLeft[n - 1].draw(x, y);
		currentFrame = n;
	}

	void drawNext() 
	{
		currentFrame++;
		if (currentFrame > getFramesCount()) currentFrame = 1;
		drawFrame(direction, currentFrame);
	}

	int getFramesCount() 
	{
		return framesRight.size();
	}

	void setDirection(string direction) 
	{
		if (direction == "right" || direction == "left") this->direction = direction;
	}


	int getWidth() 
	{
		if (direction == "right") return framesRight[currentFrame - 1].getWidth();
		if (direction == "left") return framesLeft[currentFrame - 1].getWidth();

	}
	int getHeight()
	{
		if (direction == "right") return framesRight[currentFrame - 1].getHeight();
		if (direction == "left") return framesLeft[currentFrame - 1].getHeight();
	}
};