#include <iostream>
#include "Menu.h"
#include "Game.h"
#include "Windows.h"
using namespace std;

int main()
{
	srand(time(0));
	setlocale(LC_ALL, "ru");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	menu_move();
}