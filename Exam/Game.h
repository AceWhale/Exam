#pragma once
#include <iostream>
#include <fstream>
#include "Windows.h"
using namespace std;

class Game
{
	int count; // кол-во попыток
	int count_n; // кол-во слов в словаре
	string word; // искомое слово
	string words_player; // буквы игрока
public:
	Game()
	{
		count = count_n = 0;
		word = words_player = "";
	}
	Game(int a):Game()
	{
		count_n = a;
		ifstream in;
		in.open("Word.txt");
		int c = rand() % (1 - count_n) + 1;
		for (int i = 0; i < c; i++)
		{
			char buf[300];
			in.getline(buf, 300);
			word = string(buf);
		}
		in.close();
		/*cout << GetWord();
		cout << endl;
		for (int i = 0; i < word.size(); i++)
		{
			cout << word[i];
			if (i != word.size() - 1)
			{
				cout << "|";
			}
		}*/
	}
	void ShowGame()
	{
		int lives = 5; // кол-во жизней
		int win_check = 0; // проверка на кол-во правильных введенных символов
		//string buf = GetWord();
		for (;;)
		{
			system("cls");
			cout << "Lives: " << lives << endl;
			if (lives < 4)
			{
				cout << "|";
				if (lives < 3)
					cout << "----";
			}
			cout << endl;
			if (lives < 4)
			{
				cout << "|";
				if (lives < 2)
					cout << "   O";
			}
			cout << endl;
			if (lives < 4)
				cout << "|";
			if (lives < 5 && lives != 0)
				cout << "   п";
			if (lives <= 0)
			{
				cout << "\nYou Lose\n";
				Sleep(2000);
				return;
			}
			char player;
			char buf[255];
			strcpy(buf, word.c_str());
			cout << endl;
			for (int i = 0; i < word.size(); i++)
			{
				if(words_player.find(buf[i]) !=-1)
					cout << word[i];
				if (i != word.size() - 1)
				{
					cout << "|";
				}
			}
			cout << endl;
			if (win_check == word.length())
			{
				cout << "You WIN\n";
				Sleep(2000);
				return;
			}
			cout << "\nИспользованные буквы: " << GetWordP();
			cout << "\n\nВведите символ: ";
			cin >> player;
			if (words_player.find(player) != -1)
			{
				cout << "\nДанная буква была использована\n\n";
				system("pause");
				continue;
			}
			if (word.find(player) != -1)
			{
				SetWordP(player);
				for (int j = 0; j < word.size(); j++)
				{
					if (word[j] == player)
						win_check++;
				}
			}
			else
			{
				SetWordP(player);
				SetCount();
				lives--;
			}
		}
	}
	string GetWord()
	{
		return word;
	}
	int GetCount()
	{
		return count;
	}
	string GetWordP()
	{
		return words_player;
	}
	void SetCount()
	{
		count++;
	}
	void SetWordP(char c)
	{
		words_player += c;
		words_player += " ";
	}
	void Print()
	{
		cout << "Попыток: " << GetCount() << endl;
		cout << "Искомое слово: " << GetWord() << endl;
		cout << "Буквы игрока: " << GetWordP() << endl;
	}
};