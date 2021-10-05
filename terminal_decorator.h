// Подключаем файл строго 1 раз
// (даже если будет несколько #include)
#pragma once

#include <stdio.h>

// Оформление терминала
class TerminalDecorator
{
public:
	// COLORS
	static const int black = 0;
	static const int red = 1;
	static const int green = 2;
	static const int yellow = 3;
	static const int blue = 4;
	static const int purple = 5;
	static const int cyan = 6;
	static const int white = 7;

	// STYLES
	static const int bright = 1;
	static const int italic = 3;
	static const int underlined = 4;
	static const int reversed = 7;
	static const int invisible = 8;

	static void setColors(int font, int bg)
	{
		printf("\033[3%d;4%dm", font, bg);
	}

	static void setStyle(int style)
	{
		printf("\033[0%dm", style);
	}

	static void reset()
	{
		printf("\033[00m");
	}
	static void goHome()
	{
		printf("\033[H");
	}
	static void clrscr()
	{
		reset();
		printf("\033[2J");
	}
	static void gotoxy(int x, int y)
	{
		printf("\033[%d;%dH", y, x);
	}

	// Включить/отключить вывод вводимых символов
	// (вы не видите, что печатаете в консоли, если передать false)
	static void setEcho(bool status)
	{
		system(status ? "stty echo" : "stty -echo");
	}

	// Позволяем читать символы без нажатия Enter, 
	// если передать false (нужно для управления игроком, 
	// нажатие на кнопку обрабатывается сразу)
	static void setNeedEnter(bool status)
	{
		system(status ? "stty -cbreak" : "stty cbreak");
	}
};