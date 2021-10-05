// Подключаем файл строго 1 раз
// (даже если будет несколько #include)
#pragma once

#include <fstream>
#include <vector>
#include "terminal_decorator.h" 
#include "drawer.h"
#include <string>

using namespace std;

/*******************************************************
 Класс, умеющий загружать изображение из файла .txt

 Формат файлов:
  пробел - пустой пиксель
  R - красный пиксель
  G - зеленый пиксель
  B - голубой пиксель
  C - пиксель цвета морской волны
  D - черный пиксель
  Y - желтый пиксель
  W - белый пиксель
  P - сиреневый пиксель
*******************************************************/
class Picture 
{
private:
	// вектор, для хранения строк тектового файла с картинкой
	vector <string> pic;
	// высота и ширина картинки
	int height = 0, width = 0;
public:
	Picture() {}
	Picture(string path) 
	{
		// открываем файл с картинкой в режиме чтения
		ifstream fin(path + ".txt");
		// сюда будем считывать по одной строке из файла,
		// потом помещать в вектор с помощью push_back()
		string tmp;
		
		// считываем строки из файла по одной до конца
		while (getline(fin, tmp))
		{
			// кладем считанную строку в вектор
			pic.push_back(tmp);

			// вычисляем ширину картинки, 
			// как максимальную длину строки
			if (width < tmp.length()) width = tmp.length();
		}

		// высота картинки = количество строк
		height = pic.size();

		// обязательно закрываем файл
		fin.close();
	}

	int getWidth()
	{
		return width;
	}
	int getHeight()
	{
		return height;
	}

	// метод для отрисовки изображения на териминале
	void draw(int x, int y)
	{
		// обходим вектор строк
		// (можно воспринимать его как двумерный массив символов)
		for (int i = 0; i < height; i++) 
		{
			for (int j = 0; j < width; j++) 
			{
				// В зависимости от встреченного символа красим пиксель в нужный цвет
				switch (pic[i][j]) 
				{
				case 'R':
					Drawer::point(x + j, y + i, TerminalDecorator::red);
					break;
				case 'G':
					Drawer::point(x + j, y + i, TerminalDecorator::green);
					break;
				case 'B':
					Drawer::point(x + j, y + i, TerminalDecorator::blue);
					break;
				case 'C':
					Drawer::point(x + j, y + i, TerminalDecorator::cyan);
					break;
				case 'D':
					Drawer::point(x + j, y + i, TerminalDecorator::black);
					break;
				case 'Y':
					Drawer::point(x + j, y + i, TerminalDecorator::yellow);
					break;
				case 'W':
					Drawer::point(x + j, y + i, TerminalDecorator::white);
					break;
				case 'P':
					Drawer::point(x + j, y + i, TerminalDecorator::purple);
					break;
				}
			}
		}
	}
};