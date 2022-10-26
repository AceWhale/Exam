#pragma once
#include <iostream>
#include "Game.h"
#include "Windows.h"
using namespace std;

void show_rules()
{
	cout << "����� ����������� ����� �� 5 ��� ����� ����, � ��������� �������� ���������� ������ �����.\n"
		<< "���� ����� ���� � ������ �����, ����� ������ �� � ������ � ��� �����,\n"
		 <<"��� ��� ������ ����, � ���� ����� ��� ���, �� �������� �������� ��������.\n\n";
	system("pause");
	system("cls");
}

int count_words()
{
	int c = 0;
	ifstream in;
	in.open("Word.txt");
	do
	{
		char buf[300];
		in.getline(buf, 300);
		if (!strstr(buf, "\n"))
		{
			c++;
		}
	} while (in);
	in.close();
	return c;
}

int menu_start()
{
	cout << "1. ������ ����\n2. �������� �������\n3. �����\n";
	int var;
	cin >> var;
	return var;
}

void play_game()
{
	time_t start_time = time(0);
	Game obj(count_words());
	obj.ShowGame();
	cout << endl;
	if((time(0) - start_time) >= 60)
		cout << (time(0) - start_time) / 60 << " ����� ";
	cout << (time(0) - start_time) % 60 << " ������\n";
	obj.Print();
}

void menu_move()
{
	while (true)
	{
		int var = menu_start();
		if (var == 1)
		{
			play_game();
			break;
		}
		else if (var == 2)
			show_rules();
		else if (var == 3)
			exit(0);
		else
		{
			cout << "�� ����� �������� ��������\n";
			Sleep(3000);
			system("cls");
		}
	}
}