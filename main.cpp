#include <iostream>
#include <ctime>
#include <vector>
#include "directed_sprite.h"
#include "player.h"

using namespace std;

int getRandomInt(int min, int max)
{
	return min + rand() % max;
}

int main()
{
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
	vector <Sprite> v_spikes;
	for (int i = 0; i < 10; i++)
	{
		Sprite spike("sprites/spike", getRandomInt(20, 30), getRandomInt(10, 20));
		v_spikes.push_back(spike);
	}
	// Позволяем читать символы без нажатия Enter 
	TerminalDecorator::setNeedEnter(false);
	// Отключить вывод вводимых символов
	// (вы не видите, что печатаете в консоли)
	TerminalDecorator::setEcho(false);

	while (true)
	{
		cin >> key;

		// очищаем терминал
		TerminalDecorator::clrscr();

		// рисуем следующий кадр елки
		christmassTree.drawNext();
		// рисуем подарок
		gift.draw();
		for (int i = 0; i < v_spikes.size(); i++) v_spikes[i].draw();
		// обрабатываем введенный символ,
		// чтобы понять, куда двигаться
		// странные числа - это то, что получается при вводе 
		// кириллицы (ц, Ц, ы, Ы, ф, Ф, а, А)
		if (tolower(key) == 'w' || key == -122 || key == -90) player.goUp();
		if (tolower(key) == 's' || key == -85 || key == -117) player.goDown();
		if (tolower(key) == 'a' || key == -92 || key == -124) 
		{
			player.goLeft();
			player.setDirection("left");
		}
		if (tolower(key) == 'd' || key == -78 || key == -110) 
		{
			player.goRight();
			player.setDirection("right");
		}
		player.drawNext();

		if (player.hasCollisionWith(gift)) 
		{
			gift.relocate(getRandomInt(1, 50), getRandomInt(1, 20));
			score++;
		}

		for (int i = 0; i < v_spikes.size(); i++)
		{
			if (player.hasCollisionWith(v_spikes[i]))
			{
        TerminalDecorator::clrscr();
				cout << "YOU DIED";
				exit(0);
			}
		}

		// Перемещаемся в позицию 50 по горизонтали и 1 по вертикали
		TerminalDecorator::gotoxy(50, 1);
		// Выставляем красный фон и белый шрифт
		TerminalDecorator::setColors(TerminalDecorator::white, TerminalDecorator::red);
		// печатаем на экран счет (как результат он всегда 
		// будет печататься в позиции 50 по горизонтали и 1 по вертикали)
		cout << "Score: " << score;
		//TerminalDecorator::gotoxy(50, 2);
		//cout << "DINO: " << player.hp << " " << player.speed << " " << player.hungry;
	}

	// Возвращаем терминал в обычный режим работы.
	// (видим вводимые символы и после ввода ожидаем нажатия Enter)
	TerminalDecorator::setNeedEnter(true);
	TerminalDecorator::setEcho(true);
}