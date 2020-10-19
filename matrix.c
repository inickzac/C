#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#define size 50 //������ �������

void MinInt(int val); //��������� ������ ������������ �����
int initMas2(int mas[][size]); //����� � ������� ������� 2
void newMas(int mas[][size]);  //���������� ������� ���������� �������
int work(int* offsetLeft, int* offsetRight, int mas[][size], const int i); //������� ��������� ����� � ������� 1
int initmas( int mas[][size]); //����� � ������� ������� 1
HANDLE hstdout;

int main() //����� ����� � ���������
{
	hstdout = GetStdHandle(STD_OUTPUT_HANDLE);	//���������� ��� ��������� ����� � �������
	char v=1;  //���������� ������ ����
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int mas[size][size]; //��������� ������ ��� ��������
	while (1) //����������� ���� ������ ����
	{
		
		SetConsoleTextAttribute(hstdout, FOREGROUND_INTENSITY);  //����� ���� �������
		newMas(mas); //���������� ������� ���������� �������
		if (v != 0)
		{
			printf("��� ������ � �������� ������� 1 ������: 1\n");
			printf("��� ������ � �������� ������� 2 ������: 2\n");
		}
		v = getch();
		if (v == 49) //������� ������� 1-1
		{
			
			printf("%s%d%s%s","����������� ����� � �������: ", initmas(mas),"\n", "\n");
		}
		
		if (v == 50) //������� ������� 2-2
		{			
			printf("%s%d%s%s", "����������� ����� � �������: ", initMas2(mas), "\n", "\n");
		}
		
		
	}

}//����� � ������� ������� 1

int initmas(int mas[][size]) //����� � ������� ������� 1
{
	int ResultMin=100; //���������� ��� �������� ������������ �����
	int ResultMin2; //���������� ��� �������� ������������ ����� � ������ �������� ������� 	
	int offsetLeft = 0; //���������� �������� �����
	int offsetRight = size; //���������� �������� ������
	for (int i = 0; i < size/2; i++, offsetLeft++, offsetRight--) //���� ��������� ������ �������� �������� �������
	{		
		ResultMin2=work(offsetLeft, offsetRight, mas, i); //������� ��������� ����� � �������
		MinInt(ResultMin2, &ResultMin);
		printf("\n");
	}
	 offsetLeft = size/2-1;
	 offsetRight = size / 2+1;
	for (int i = size / 2; i < size; i++, offsetLeft--, offsetRight++)//���� ��������� ������ �������� �������� �������
	{		
		ResultMin2=work(offsetLeft, offsetRight, mas, i);//������� ��������� ����� � �������
		printf("\n");
		MinInt(ResultMin2, &ResultMin);
	}
	SetConsoleTextAttribute(hstdout, FOREGROUND_INTENSITY);
	return ResultMin;
	
	}

int work(int offsetLeft, int offsetRight, int *mas [size][size], const int i) //������� ��������� ����� � ������� 1
{
	int ResultMin=100; //���������� ��� �������� ������������ �����
	for (int j = 0; j < size; j++)
	{
		if (j >= offsetLeft && j < offsetRight) //���� ��������� ������ �������
		{
			
			SetConsoleTextAttribute(hstdout,  FOREGROUND_BLUE); //����� ����� ������ ��������
			printf("%2d ", mas[i][j]);
			MinInt(mas[i][j],&ResultMin);
		}
		else {
			SetConsoleTextAttribute(hstdout,  FOREGROUND_GREEN);//����� ������� �� ������ ��������
			printf("%2d ", mas[i][j]);
		}

	}
	return ResultMin;
}

void newMas(int mas[][size]) //���������� ������� ���������� �������
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

int initMas2(int mas[][size]) //����� � ������� ������� 2
{	
	int ResultMin = 100;  //���������� ��� �������� ������������ �����
	int offsetLeft1 = 1; //���������� �������� ����� ������ ��������
	int offsetLeft2 = size/2; //���������� �������� ����� ������ ��������
	for (int i = 0; i < size; i++) //���� ���������  �������� �������
	{
		
		for (int j = 0; j < size; j++) //���� ���������  ����� �������
		{
			if (i<size / 2 && j<offsetLeft1 )
			{
				SetConsoleTextAttribute(hstdout, FOREGROUND_BLUE);
				printf("%2d ", mas[i][j]);
			
			}
			else if(i>=size/2 && j<offsetLeft2)
			{
				SetConsoleTextAttribute(hstdout, FOREGROUND_BLUE);//����� ����� ������ ��������
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

void MinInt(int val,int* ResultMin)//��������� ������ ������������ �����
{
	if (val < *ResultMin)
	{
		*ResultMin = val;
	}

}