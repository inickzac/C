#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#define size 50 //Размер массива

void MinInt(int val); //Процедура поиска минимального числа
int initMas2(int mas[][size]); //Вывод и подсчет матрицы 2
void newMas(int mas[][size]);  //Заполнение массива случайными числами
int work(int* offsetLeft, int* offsetRight, int mas[][size], const int i); //Функция обработки строк в матрице 1
int initmas( int mas[][size]); //Вывод и подсчет матрицы 1
HANDLE hstdout;

int main() //Точка входа в программу
{
	hstdout = GetStdHandle(STD_OUTPUT_HANDLE);	//Дискриптор для изменения цвета в консоли
	char v=1;  //Переменная выбора меню
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int mas[size][size]; //Двумерный массив для подсчета
	while (1) //Бесконечный цикл выбора меню
	{
		
		SetConsoleTextAttribute(hstdout, FOREGROUND_INTENSITY);  //Серый цвет консоли
		newMas(mas); //Заполнение массива случайными числами
		if (v != 0)
		{
			printf("Для вывода и подсчета матрицы 1 нажмие: 1\n");
			printf("Для вывода и подсчета матрицы 2 нажмие: 2\n");
		}
		v = getch();
		if (v == 49) //подсчет матрицы 1-1
		{
			
			printf("%s%d%s%s","Минимальное число в матрице: ", initmas(mas),"\n", "\n");
		}
		
		if (v == 50) //подсчет матрицы 2-2
		{			
			printf("%s%d%s%s", "Минимальное число в матрице: ", initMas2(mas), "\n", "\n");
		}
		
		
	}

}//Вывод и подсчет матрицы 1

int initmas(int mas[][size]) //Вывод и подсчет матрицы 1
{
	int ResultMin=100; //Переменная для хранения минимального числа
	int ResultMin2; //Переменная для хранения минимального числа в другой половине матрицы 	
	int offsetLeft = 0; //Переменная смещения слева
	int offsetRight = size; //Переменная смещения справа
	for (int i = 0; i < size/2; i++, offsetLeft++, offsetRight--) //Цикл обработки первой половины столбцов массива
	{		
		ResultMin2=work(offsetLeft, offsetRight, mas, i); //Функция обработки строк в массиве
		MinInt(ResultMin2, &ResultMin);
		printf("\n");
	}
	 offsetLeft = size/2-1;
	 offsetRight = size / 2+1;
	for (int i = size / 2; i < size; i++, offsetLeft--, offsetRight++)//Цикл обработки второй половины столбцов массива
	{		
		ResultMin2=work(offsetLeft, offsetRight, mas, i);//Функция обработки строк в массиве
		printf("\n");
		MinInt(ResultMin2, &ResultMin);
	}
	SetConsoleTextAttribute(hstdout, FOREGROUND_INTENSITY);
	return ResultMin;
	
	}

int work(int offsetLeft, int offsetRight, int *mas [size][size], const int i) //Функция обработки строк в матрице 1
{
	int ResultMin=100; //Переменная для хранения минимального числа
	for (int j = 0; j < size; j++)
	{
		if (j >= offsetLeft && j < offsetRight) //Цикл обработки строки массива
		{
			
			SetConsoleTextAttribute(hstdout,  FOREGROUND_BLUE); //Вывод синим нужные элементы
			printf("%2d ", mas[i][j]);
			MinInt(mas[i][j],&ResultMin);
		}
		else {
			SetConsoleTextAttribute(hstdout,  FOREGROUND_GREEN);//Вывод зеленым не нужные элементы
			printf("%2d ", mas[i][j]);
		}

	}
	return ResultMin;
}

void newMas(int mas[][size]) //Заполнение массива случайными числами
{
	srand(time(NULL));
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			mas[i][j] = rand() % 100;

		}

	}


}

int initMas2(int mas[][size]) //Вывод и подсчет матрицы 2
{	
	int ResultMin = 100;  //Переменная для хранения минимального числа
	int offsetLeft1 = 1; //Переменная смещения слева первой половины
	int offsetLeft2 = size/2; //Переменная смещения слева второй половины
	for (int i = 0; i < size; i++) //Цикл обработки  столбцов массива
	{
		
		for (int j = 0; j < size; j++) //Цикл обработки  строк массива
		{
			if (i<size / 2 && j<offsetLeft1 )
			{
				SetConsoleTextAttribute(hstdout, FOREGROUND_BLUE);
				printf("%2d ", mas[i][j]);
			
			}
			else if(i>=size/2 && j<offsetLeft2)
			{
				SetConsoleTextAttribute(hstdout, FOREGROUND_BLUE);//Вывод синим нужные элементы
				printf("%2d ", mas[i][j]);
				
			}
			else {
				SetConsoleTextAttribute(hstdout, FOREGROUND_GREEN);
				printf("%2d ", mas[i][j]);
				MinInt(mas[i][j], &ResultMin);
			}
		}
		if (i < size / 2) { offsetLeft1++; }
		if (i >= size / 2) { offsetLeft2--; }
		printf("\n");
	} 
	SetConsoleTextAttribute(hstdout, FOREGROUND_INTENSITY);
	return ResultMin;
}

void MinInt(int val,int* ResultMin)//Процедура поиска минимального числа
{
	if (val < *ResultMin)
	{
		*ResultMin = val;
	}

}