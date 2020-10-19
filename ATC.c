# include <stdio.h>
# pragma warning (disable : 4996)
# include <string.h>
# include <locale.h>
# include <stdbool.h>
#define size 100

struct ATS
{
	char data[10];  //Дату разговора
	char sity[10] ;   //Название города
	unsigned int time_call; //Время разговора
	unsigned int tarif;	 //Тариф
};

void add(struct ATS ATSS[], int* count);  //Процедура добавления 
char* dayCorrect(); //Процедура проверки правильности ввода даты
void sum(struct ATS ATSS[], int count, int* cash, int* time); //Общее время разговора и сумма

void main() //Точка входа
{	
	char c=1;
	setlocale(LC_ALL, "Rus");
	int count = 0; //Количество элементов
	struct ATS ATSS[size];  
	
	for (int i = 0; i < size; i++) //Обнуление структур
	{		
		strcpy(ATSS[i].data,"");
		strcpy(ATSS[i].sity, "");
		ATSS[i].time_call= 0;
		ATSS[i].tarif = 0;
	}		
	
	while (true) //Бесконечный цикл выбора меню
	{		
		if (c!= 0)
		{
			printf("Количество элементов: %d %s", count, "\n");
			printf("Для добавления звонка нажмите 1\n");
			printf("Для подсчета звонка нажмите 2\n");
			fflush(stdin);
		}
		c = getch();		
		if (c == 49) // 1 для добавления
		{			
			add(ATSS,&count);
		}

		else if (c== 50) // 2 для подсчета
		{		
			int cash = 0;
			int time = 0;
			sum(ATSS, count, &cash, &time);
			printf("Общее время разговора за 30 марта= %d%s %s %d%s", time, "с", "на сумму=", cash, "р\n");
		}
		else if(c!=0)
		{
			printf("Неправильный ввод\n");
		}
	}		
}

void add(struct ATS ATSS[],int* count)//Процедура добавления 
{
	char c = 1;
	int i = *count;
	 if (i<size)	
	 {
		 for (; i < size; i++) //Ввод данных в структуру
		 {
			 printf("Введите дату звонка вида: дд.мм.гггг\n");
			 strcpy(ATSS[i].data, dayCorrect());
			 printf("Введите город \n");
			 scanf("%10s", ATSS[i].sity);
			 printf("Введите время звонка в секундах \n");
			 scanf("%10u", &ATSS[i].time_call);
			 printf("Введите тариф \n");
			 scanf("%10u", &ATSS[i].tarif);
			 printf("\n");
			 printf("Для выхода нажмите esc \n");
			 printf("Для ввода любую клавишу \n");
			 printf("\n");
			 *count = *count + 1;
			 c = getch();
			 if (c==0)
			 {
				 c = getch();
			 }
			 if (c== 27) //esc выход
			 {
				 break;
			 }
		 }
	}
	 else
	 {
		 printf("Введено максимальное число элементов");
	 }
 }

char* dayCorrect() //Процедура проверки правильности ввода даты
 { 
	 bool cor = false;	
	 while (cor!=true)
	 {   
		 bool  formEr = false;
		 char mass[11];
		 int day, month, year;	 
		 fflush(stdin);
		 scanf("%10s", mass);		 		 			 
		 for (int i = 0; i < 10; i++)
			 {
				 if (mass[i]<48 && mass[i]>57 && mass[i] != 46)
				 {
					 formEr = true;
				 }			 		 			 
			 }	 		 
			 mass[10] = NULL;
			 if (mass[2] != '.' || mass[5] != '.' || formEr == true)  // Проверяем корректность формата
		 {
			 printf("Некорректный формат:\n");
			 continue;
		 }
		 // Преобразуем строковые символы в числа
		 day = atoi(mass);
		 month = atoi(mass + 3);
		 year = atoi(mass + 6);

		 if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30) // если слишком много дней в коротком месяце
		 {
			 printf("Слишком много дней в коротком месяце:\n");
			 continue;
		 }
		 if (month == 2 && day > 28)  // отдельно проверяем месяц февраль
		 {
			 printf("Много дней в феврале\n");
			 continue;
		 }
		 if (day > 31) // если введен слишком большой день
		 {
			 printf("Введен слишком большой день\n");
			 continue;
		 }
		 if (month > 12) // если введен слишком большой месяц
		 {
			 printf("Введен слишком большой месяц\n");
			 continue;
		 }	 
		 cor = true;
		 return mass;
	 }
	


 }



 void sum(struct ATS ATSS[], int  count, int* cash, int* time) //Общее время разговора и сумма

{	
	 int month = 3;
	 int day = 30;
	 for (int i = 0; i < count; i++)
	{
		if (atoi(ATSS[i].data) == day && atoi(ATSS[i].data + 3) == month)
		{
			*time += ATSS[i].time_call;
			*cash += ATSS[i].time_call*ATSS[i].tarif;
		}
	}
}