#include <iostream>
#include <ctime> // для функции time(), исп. для рандома
#include <vector>
#include "directed_sprite.h"
#include "player.h"

using namespace std;

int getRandomInt(int min, int max){
  return min + random() % max;
}

int main() {
  srand(time(0)); // это для рандома
  int score = 0; // здесь будем хранить счет
  int i = 0;
  // в эту переменную будем считывать символы
  // и реагировать на ввод W, A, S, D
  char key; 

  // Очищаем терминал
  TerminalDecorator::clrscr();
  // DirectedSprite player("sprites/dino", 4, 1, 1);
  Player player("sprites/dino", 4, 10, 10);
  AnimSprite christmassTree("sprites/christmass_tree", 2, 5, 5);
  Sprite gift("sprites/gift", 25, 10);
  Sprite spike1("sprites/spike", 25, 20);
  Sprite spike2("sprites/spike", 35, 10);
  Sprite spike3("sprites/spike", 45, 15);
  Sprite spike4("sprites/spike", 10, 20);
  Sprite spike5("sprites/spike", 55, 30);
  Sprite spike6("sprites/spike", 45, 21);
  Sprite spike7("sprites/spike", 15, 17);
  Sprite spike8("sprites/spike", 32, 21);
  Sprite spike9("sprites/spike", 11, 24);
  Sprite spike10("sprites/spike", 28, 17);
  // Позволяем читать символы без нажатия Enter 
  TerminalDecorator::setNeedEnter(false);
  // Отключить вывод вводимых символов
  // (вы не видите, что печатаете в консоли)
  TerminalDecorator::setEcho(false);

  while (true) {
    cin >> key;

    // очищаем терминал
    TerminalDecorator::clrscr();

    // рисуем следующий кадр елки
    christmassTree.drawNext();
    // рисуем подарок
    gift.draw();
    spike1.draw();
    spike2.draw();
    spike3.draw();
    spike4.draw();
    spike5.draw();
    spike6.draw();
    spike7.draw();
    spike8.draw();
    spike9.draw();
    spike10.draw();
    // обрабатываем введенный символ,
    // чтобы понять, куда двигаться
    // странные числа - это то, что получается при вводе 
    // кириллицы (ц, Ц, ы, Ы, ф, Ф, а, А)
    if(tolower(key) == 'w' || key == -122 || key == -90) {
      player.goUp();
    }
    if(tolower(key) == 's' || key == -85 || key == -117) {
      player.goDown();
    }
    if(tolower(key) == 'a' || key == -92 || key == -124) {
      player.goLeft();
      player.setDirection("left");
    }
    if(tolower(key) == 'd' || key == -78 || key == -110) {
      player.goRight();
      player.setDirection("right");
    }
    player.drawNext();

    if(player.hasCollisionWith(gift)){
      gift.relocate(getRandomInt(1, 50), getRandomInt(1, 15));
      score++;
    }
    
    if(player.hasCollisionWith(spike1) || player.hasCollisionWith(spike2) || player.hasCollisionWith(spike3) || player.hasCollisionWith(spike4) || player.hasCollisionWith(spike5) || player.hasCollisionWith(spike6) || player.hasCollisionWith(spike7) || player.hasCollisionWith(spike8) || player.hasCollisionWith(spike9) || player.hasCollisionWith(spike10))
    {
        cout << "YOU DIED, GG";
        exit(0);
    }

    // Перемещаемся в позицию 50 по горизонтали и 1 по вертикали
    TerminalDecorator::gotoxy(50, 1);
    // Выставляем красный фон и белый шрифт
    TerminalDecorator::setColors(TerminalDecorator::white, TerminalDecorator::red);
    // печатаем на экран счет (как результат он всегда 
    // будет печататься в позиции 50 по горизонтали и 1 по вертикали)
    cout << "Score: " << score;
    TerminalDecorator::gotoxy(50, 2);
    cout << "DINO: " << player.hp<<" " << player.speed<<" " <<player.hungry;
  }

  // Возвращаем терминал в обычный режим работы.
  // (видим вводимые символы и после ввода ожидаем нажатия Enter)
  TerminalDecorator::setNeedEnter(true);
  TerminalDecorator::setEcho(true);

  return 0;
}