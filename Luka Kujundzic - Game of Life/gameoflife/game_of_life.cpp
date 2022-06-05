#include"game_of_life.h"
#include <iostream>
#include <chrono>

using namespace std;

// Private


int game_of_life::susjedi(int i, int j)
{
	int n = 0;


	if (i - 1 >= 0) //provjeri jesi u prvom redu
	{
		if (j - 1 >= 0) {
			if (_generacija[i - 1][j - 1] == 1)//gornji lijevi
			{
				n++;
			}
		}
		if (_generacija[i - 1][j] == 1)//gornji
		{
			n++;
		}

		if (j + 1 < STUPACA) {
			if (_generacija[i - 1][j + 1] == 1)//gornji desni
			{
				n++;
			}
		}
	}

	if (j - 1 >= 0)//lijevi
	{
		if (_generacija[i][j - 1] == 1)
		{
			n++;
		}
	}
	if(j + 1 < STUPACA)//desni
	{
		if (_generacija[i][j + 1] == 1)
		{
			n++;
		}
	}
	if(i + 1 < REDAKA)//provjeri jesi u zadnjem redu
	{
		if (j - 1 >= 0) {
			if (_generacija[i + 1][j - 1] == 1)//donji lijevi
			{
				n++;
			}
		}
		if (_generacija[i + 1][j] == 1)//donji
		{
			n++;
		}
		if (j + 1 < STUPACA) {
			if (_generacija[i + 1][j + 1] == 1)//donji desni
			{
				n++;
			}
		}
}
	return n;
}


// Public

game_of_life::game_of_life()
{
	srand(time(NULL));
	for (int i = 0; i < REDAKA; i++)
	{
		for (int j = 0; j < STUPACA; j++)
		{
			if (rand() % 4 == 0) {
				_generacija[i][j] = 1;
			}
			else
			{
				_generacija[i][j] = 0;
			}
		}
	}

}

void game_of_life::sljedeca_generacija()
{
	for (int i = 0; i < REDAKA; i++)
	{
		for (int j = 0; j < STUPACA; j++)
		{	
			int s = susjedi(i, j);
			if (_generacija[i][j] == 1) {
				
				if (s < 2 || s > 3)
				{
					_sljedeca_generacija[i][j] = 0;
				}
				else if (s == 2 || s == 3)
				{
					_sljedeca_generacija[i][j] = 1;
				}
			}
			else
			{
				if(s == 3) 
				{
					_sljedeca_generacija[i][j] = 1;
				}

			}
		}
	}

	for (int i = 0; i < REDAKA; i++)
	{
		for (int j = 0; j < STUPACA; j++)
		{
			_generacija[i][j] = _sljedeca_generacija[i][j];
		}
	}
}

void game_of_life::iscrtaj()
{	
	for (int i = 0; i < REDAKA; i++)
	{
		for (int j = 0; j < STUPACA; j++)
		{
			if (_generacija[i][j] == 1)
			{
				cout << "*";
			}
			else 
			{
				cout << "-";
			}
		}
		cout << endl;
	}
	cout << endl;
}
