#include <stdio.h>
# pragma warning (disable : 4996)
# include <locale.h>
# include <stdbool.h>
# include <string.h>
# include <Windows.h>
#define count 100 //Число символов в строке


int main() 
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);	
	char v;	
	FILE *F, *G;	
	F = NULL;  //Файл для обработки
	G = NULL;  //Обработанный файл
	
	while (true) //Цикл главного меню
	{
		printf("Для создания и инициализации файла нажмите 1\n");
		printf("Для обработки файла нажмите 2\n");
		printf("Для просмотра файла нажмите 3\n");
		v = getch();
		if (v==0)
		{
			v = getch();
		}
		switch (v)  //Выбор команды
		{
		case  49:  //1
			if (init(F) == -1) //Процедура ввода строки в файл
			{				
				printf("Ошибка\n");
			}
			break;
		case 50:	//2		
			if (change(F, G) == -1)  //Процедура обработки символов
			{
				printf("Ошибка\n");
			}
			else
			{
				printf("Строка обработана\n");
			}
			break;
		case 51:  //3
			while (true)
			{
				printf("Для открытия файла ""F"" нажимте 1\n");
				printf("Для открытия файла ""G"" нажимте 2\n");
				printf("Для выхода esc\n");
				char k = NULL; //Переменная выбора подменю
				k = getch();
				if (k == 0)
				{
					k = getch();
				}
				if (k == 49)  //1
				{
					if (readfile(F, "F.txt") == -1) //Процедура цтения файла F
					{
						printf("Ошибка\n");
					}					
				}
				else if (k == 50) //2
				{
					if (readfile(G, "G.txt") == -1)  //Процедура цтения файла G
					{
						printf("Ошибка\n");
					}
				}
				
				else if (k == 27) //esc
				{
					break;
				}
				
			}
			
			break;

		default:
			printf("Неправильный ввод\n");

		}
	}
}


    int init(FILE *F)//Процедура ввода строки в файл
{ 
	char c[count];		
	F = fopen("F.txt", "wt");
		if (F != NULL)
		{
			printf("Введите символы\n");
			scanf("%s100", c);
			fprintf(F, c);
		}
		else
		{
			return -1;
		}
		fclose(F);
		return 1;	
	}
	
	int change(FILE *F, FILE*G)
	{
	
		char s[] = { 'А', 'Б', 'В', 'Г', 'Д', 'Е', 'Ё', 'Ж', 'З', 'И', 'Й', 'К', 'Л', 'М', 'Н', 'О', 'П', 'Р', 'С', 'Т', 'У', 'Ф', 'Х', 'Ц',
			'Ч', 'Ш', 'Щ', 'Ь', 'Ы', 'Ь', 'Э', 'Ю', 'Я' }; //Прописные
		char p[] = { 'а', 'б', 'в', 'г', 'д', 'е', 'ё', 'ж', 'з', 'и', 'й', 'к', 'л', 'м', 'н', 'о', 'п', 'р', 'с', 'т', 'у', 'ф', 'х', 'ц',
			'ч', 'ш', 'щ', 'ъ', 'ы', 'ь', 'э', 'ю', 'я' };   //строчные
		F = fopen("F.txt", "rt");
		G = fopen("G.txt", "wt");
		if (F != NULL)
		{						
			char c=NULL;
			do  //Цикл пока не конец файла
			{			
				bool q = false;			//Переменная статуса замены символа	
				c = fgetc(F);  //Считывание символов 
				if (c != EOF)
				{
					for (int t = 0; t < 34; t++) //Поиск символов в строке
					{
						if (c == s[t])
						{
							fputc(p[t], G);
							q = true;
							break;
						}
					}
					if (q == false)
					{
						fputc(c, G);
					}
				}
			}
				
			while (c!=EOF);
		}
		
		else
		{
			return -1;
		
		}
		fclose(F);
		fclose(G);
		return 1;
	}

	int readfile(FILE *G,char* p)  //Процедура цтения файла 
	{
		char c=NULL;  //Переменная для считывания символов
		G = fopen(p, "rt");		
		if (G != NULL)		
		{			
			c = fgetc(G);
			while (c != EOF)
			{
				printf("%c", c);
				c = fgetc(G);
			}
			printf("\n");
		}
		else
		{
			return -1;
		}
		fclose(G);
		return 1;
	}