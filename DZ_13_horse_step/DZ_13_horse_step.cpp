

#include <iostream>
#include <Windows.h>

using namespace std;

//Задание 1. Дана шахматная доска размером 8×8 и шахматный конь. Программа должна запросить у пользователя
//координаты клетки поля и поставить туда коня.Задача
//программы найти и вывести путь коня, при котором он
//обойдет все клетки доски, становясь в каждую клетку
//только один раз. (Так как процесс отыскания пути для
//разных начальных клеток может затянуться, то рекомендуется сначала опробовать задачу на поле размером
//6×6).В программе необходимо использовать рекурсию.

//P.S Так мне и трансцендентно: должен ходить пользователь: "Программа должна запросить у пользователя координаты клетки
//и поля и поставить туда коня". Или же программа должна обойти всё поле самолично: "Задача
//программы найти и вывести путь коня, при котором он обойдет все клетки доски, становясь в каждую клетку только один раз".
//Поэтому я предоставил ходить пользователю по доске, пока ему не опостылет.






char desk[8][8];
void FillingDesk(char(*arr)[8]);
void DrawDesk(char(*arr)[8]);
void PositionOfHorse(char(*arr)[8]);
void StepOfHorse(char(*arr)[8], int x, int y);
bool TermsOfStep(char(*arr)[8], int x, int y, int Hx, int Hy);


int main()
{
	FillingDesk(desk);
	PositionOfHorse(desk);
	DrawDesk(desk);
	char r;
	cout << "Do you want to make a step? (y/n)\n";
	cin >> r;
	while (r == 'y') {
		cout << endl;
		int x, y;
		cout << "Coordinate y - "; cin >> x; //Я всё напутал, поэтому далее x - это y, а y - это x
		cout << "Coordinate x - "; cin >> y;
		StepOfHorse(desk, x, y);
		DrawDesk(desk);
		cout << endl;
		cout << "Do you want to make a step? (y/n)\n";
		cin >> r;
	}
	cout << "Good bye!";
}

// Заполнение поля, поставнока Коня, отображение поля
void FillingDesk(char(*arr)[8]) {
	int g = 0;
	for (int i = 0; i < 8; i++) {
		g += 1;
		for (int j = 0; j < 8; j += 2) {
			if (g % 2 != 0) {
				desk[i][j] = '#'; desk[i][j + 1] = 'o';
			}
			else {
				desk[i][j] = 'o'; desk[i][j + 1] = '#';
			}
		}
	}
}
void DrawDesk(char(*arr)[8]) {
	cout << "  ";
	for (int i = 0; i < 8; i++) {
		cout << i << " ";
	}
	cout << endl << "  --------";
	cout << endl;
	for (int i = 0; i < 8; i++) {
		cout << i << "|";
		for (int j = 0; j < 8; j++) {
			cout << desk[i][j] << " ";
		}
		cout << endl;
	}
}
void PositionOfHorse(char(*arr)[8]) {
	desk[4][3] = 'H';
}
// Ход коня
void StepOfHorse(char(*arr)[8], int x, int y) {
	//Выясняем местоположение коня
	//a, b - координаты коня
	int a, b;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (desk[i][j] == 'H') {
				a = i;
				b = j;
			}
		}
	}
	if (TermsOfStep(arr, x, y, b, a) == true) {
		FillingDesk(desk);
		desk[x][y] = 'H';
	}
	else {
		cout << "Wrong step\n";
		cout << "Coordinate y - "; cin >> x;
		cout << "Coordinate x - "; cin >> y;
		StepOfHorse(arr, x, y);
	}
}
bool TermsOfStep(char(*arr)[8], int x, int y, int Hx, int Hy) {
	//Условия хода коня в двух массивах
	int HorseMove1[8] = { -2, -1, 1, 2, 2, 1, -1, -2 };
	int HorseMove2[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };

	for (int i = 0; i < 7; i++) {
		if ((Hx - HorseMove1[i]) == y and (Hy + HorseMove2[i]) == x) {
			return true;
		}
		else continue;
	}

}