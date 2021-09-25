// Подключаем файл строго 1 раз
// (даже если будет несколько #include)
#pragma once

#include <iostream>
#include "terminal_decorator.h"

using namespace std;


/*******************************************************
 Класс занимающийся рисованием в терминале.

 Умеет закрашивать цветом точки по координатам.
*******************************************************/
class Drawer{
  public: 
    static void point(int x, int y, int color){
      // перемещаем курсор в нужную точку
      TerminalDecorator::gotoxy(x, y);
      // Выставляем черный цвет текста и нужный цвет фона
      TerminalDecorator::setColors(TerminalDecorator::black, color);
      // печатаем пробел (получается квадратик, закрашенный 
      // выставленным только что цветом фона)
      cout << " ";
      // сбрасываем настройки (цвета и оформление)
      TerminalDecorator::reset();
    }
};