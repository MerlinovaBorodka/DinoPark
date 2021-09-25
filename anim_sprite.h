// Подключаем файл строго 1 раз
// (даже если будет несколько #include)
#pragma once

#include "sprite.h"

using namespace std;



/*******************************************************
 Класс анимированного спрайта 

 Анимированный спрайт имеет несколько кадров (отдельные картинки)
 и умеет отрисовывать либо определенную картинку по ее 
 порядковому номеру, либо следующую по порядку. За счет
 этого и достигается эффект анимации.
*******************************************************/
class AnimSprite: public Sprite{
  private:
    // вектор для хранения кадров (картинок)
    vector<Picture> frames;

  protected:
    // здесь будем хранить текущий кадр
    int currentFrame = 1;

  public:
    AnimSprite(){}

    // в конструкторе с параметрами кроме уже знакомых
    // вещей мы принимаем также framesCount - это количество 
    // кадров
    // Также путь теперь указывает не на конкретный .txt файл, а
    // на папку, в которой лежат пронумерованные файлы изображений
    AnimSprite(string spriteSrc, int frameCount, int x = 0, int y = 0){
      this->x = x;
      this->y = y;

      // считываем все изображения по очереди и
      // добавляем их в вектор, где они и будут храниться
      frames.resize(frameCount);
      for(int i = 0; i < frameCount; i++){
        char num = i + 1 + '0';
        frames[i] = Picture(spriteSrc + "/" + num);
      }

      // сразу при создании объекта отрисовываем его
      drawFrame(currentFrame);
    }

    void drawFrame(int n){
      frames[n - 1].draw(x, y);
      currentFrame = n;
    }

    void drawNext(){
      currentFrame++;
      if(currentFrame > getFramesCount())
        currentFrame = 1;
      drawFrame(currentFrame);
    }

    int getCurFrame(){
      return currentFrame;
    }
    int getFramesCount(){
      return frames.size();
    }

    // Переопределяем логику получения размеров.
    // т.к. картинок теперь много, то размеры должны
    // соответствовать именно той картинке, которая на
    // данный момент является текущей
    int getWidth(){
      return frames[currentFrame - 1].getWidth();
    }
    int getHeight(){
      return frames[currentFrame - 1].getHeight();
    }
};