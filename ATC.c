# include <stdio.h>
# pragma warning (disable : 4996)
# include <string.h>
# include <locale.h>
# include <stdbool.h>
#define size 100

struct ATS
{
	char data[10];  //���� ���������
	char sity[10] ;   //�������� ������
	unsigned int time_call; //����� ���������
	unsigned int tarif;	 //�����
};

void add(struct ATS ATSS[], int* count);  //��������� ���������� 
char* dayCorrect(); //��������� �������� ������������ ����� ����
void sum(struct ATS ATSS[], int count, int* cash, int* time); //����� ����� ��������� � �����

void main() //����� �����
{	
	char c=1;
	setlocale(LC_ALL, "Rus");
	int count = 0; //���������� ���������
	struct ATS ATSS[size];  
	
	for (int i = 0; i < size; i++) //��������� ��������
	{		
		strcpy(ATSS[i].data,"");
		strcpy(ATSS[i].sity, "");
		ATSS[i].time_call= 0;
		ATSS[i].tarif = 0;
	}		
	
	while (true) //����������� ���� ������ ����
	{		
		if (c!= 0)
		{
			printf("���������� ���������: %d %s", count, "\n");
			printf("��� ���������� ������ ������� 1\n");
			printf("��� �������� ������ ������� 2\n");
			fflush(stdin);
		}
		c = getch();		
		if (c == 49) // 1 ��� ����������
		{			
			add(ATSS,&count);
		}

		else if (c== 50) // 2 ��� ��������
		{		
			int cash = 0;
			int time = 0;
			sum(ATSS, count, &cash, &time);
			printf("����� ����� ��������� �� 30 �����= %d%s %s %d%s", time, "�", "�� �����=", cash, "�\n");
		}
		else if(c!=0)
		{
			printf("������������ ����\n");
		}
	}		
}

void add(struct ATS ATSS[],int* count)//��������� ���������� 
{
	char c = 1;
	int i = *count;
	 if (i<size)	
	 {
		 for (; i < size; i++) //���� ������ � ���������
		 {
			 printf("������� ���� ������ ����: ��.��.����\n");
			 strcpy(ATSS[i].data, dayCorrect());
			 printf("������� ����� \n");
			 scanf("%10s", ATSS[i].sity);
			 printf("������� ����� ������ � �������� \n");
			 scanf("%10u", &ATSS[i].time_call);
			 printf("������� ����� \n");
			 scanf("%10u", &ATSS[i].tarif);
			 printf("\n");
			 printf("��� ������ ������� esc \n");
			 printf("��� ����� ����� ������� \n");
			 printf("\n");
			 *count = *count + 1;
			 c = getch();
			 if (c==0)
			 {
				 c = getch();
			 }
			 if (c== 27) //esc �����
			 {
				 break;
			 }
		 }
	}
	 else
	 {
		 printf("������� ������������ ����� ���������");
	 }
 }

char* dayCorrect() //��������� �������� ������������ ����� ����
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
			 if (mass[2] != '.' || mass[5] != '.' || formEr == true)  // ��������� ������������ �������
		 {
			 printf("������������ ������:\n");
			 continue;
		 }
		 // ����������� ��������� ������� � �����
		 day = atoi(mass);
		 month = atoi(mass + 3);
		 year = atoi(mass + 6);

		 if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30) // ���� ������� ����� ���� � �������� ������
		 {
			 printf("������� ����� ���� � �������� ������:\n");
			 continue;
		 }
		 if (month == 2 && day > 28)  // �������� ��������� ����� �������
		 {
			 printf("����� ���� � �������\n");
			 continue;
		 }
		 if (day > 31) // ���� ������ ������� ������� ����
		 {
			 printf("������ ������� ������� ����\n");
			 continue;
		 }
		 if (month > 12) // ���� ������ ������� ������� �����
		 {
			 printf("������ ������� ������� �����\n");
			 continue;
		 }	 
		 cor = true;
		 return mass;
	 }
	


 }



 void sum(struct ATS ATSS[], int  count, int* cash, int* time) //����� ����� ��������� � �����

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