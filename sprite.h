// Подключаем файл строго 1 раз
// (даже если будет несколько #include)
#pragma once

#include "picture.h"

/*******************************************************
 Класс игрового объекта

 Отличается от обычной картинки (Picture) тем, что
 знает свои координаты и умеет определять коллизии (пересечения)
 с другими спрайтами
*******************************************************/
class Sprite
{
private:
	// Картинку спрайта будем хранить здесь
	Picture pic;

protected:
	int x = 0, y = 0;

public:
	// При создании объекта с параметрами будет
	// вызываться конструктор Picture, принимающий путь до картинки
	// (благодаря списку инициализации)
	Sprite(std::string spriteSrc, int x = 0, int y = 0) : pic(spriteSrc), x(x), y(y)
	{
		draw();
	}
	Sprite() {}

	// метод, отрисовывающий картинку спрайта в его координатах
	void draw() 
	{
		pic.draw(x, y);
	}

	// метод перемещает спрайт в новые координаты
	void relocate(int x, int y) 
	{
		this->x = x;
		this->y = y;
	}

	// проверка на пересечение с другим спрайтом (коллизия)
	bool hasCollisionWith(Sprite other) 
	{
		bool colCollision = false, rowCollision = false;
		if (x + getWidth() > other.x && x < other.x + other.getWidth()) colCollision = true;
		if (y + getHeight() > other.y && y < other.y + other.getHeight()) rowCollision = true;

		return colCollision && rowCollision;
	}

	// проверка на пересечение с каким-либо спрайтом из вектора
	bool HasAnyCollision(vector <Sprite> v)
	{
		for (int i = 0; i < v.size(); i++) if (this->hasCollisionWith(v[i])) return true;
		return false;
	}

	virtual int getWidth() { return pic.getWidth(); }
	virtual int getHeight() { return pic.getHeight(); }

	int getX() { return x; }
	int getY() { return y; }

};