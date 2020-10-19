#include <stdio.h>
# pragma warning (disable : 4996)
# include <locale.h>
# include <stdbool.h>
# include <string.h>
# include <Windows.h>
#define count 100 //����� �������� � ������


int main() 
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);	
	char v;	
	FILE *F, *G;	
	F = NULL;  //���� ��� ���������
	G = NULL;  //������������ ����
	
	while (true) //���� �������� ����
	{
		printf("��� �������� � ������������� ����� ������� 1\n");
		printf("��� ��������� ����� ������� 2\n");
		printf("��� ��������� ����� ������� 3\n");
		v = getch();
		if (v==0)
		{
			v = getch();
		}
		switch (v)  //����� �������
		{
		case  49:  //1
			if (init(F) == -1) //��������� ����� ������ � ����
			{				
				printf("������\n");
			}
			break;
		case 50:	//2		
			if (change(F, G) == -1)  //��������� ��������� ��������
			{
				printf("������\n");
			}
			else
			{
				printf("������ ����������\n");
			}
			break;
		case 51:  //3
			while (true)
			{
				printf("��� �������� ����� ""F"" ������� 1\n");
				printf("��� �������� ����� ""G"" ������� 2\n");
				printf("��� ������ esc\n");
				char k = NULL; //���������� ������ �������
				k = getch();
				if (k == 0)
				{
					k = getch();
				}
				if (k == 49)  //1
				{
					if (readfile(F, "F.txt") == -1) //��������� ������ ����� F
					{
						printf("������\n");
					}					
				}
				else if (k == 50) //2
				{
					if (readfile(G, "G.txt") == -1)  //��������� ������ ����� G
					{
						printf("������\n");
					}
				}
				
				else if (k == 27) //esc
				{
					break;
				}
				
			}
			
			break;

		default:
			printf("������������ ����\n");

		}
	}
}


    int init(FILE *F)//��������� ����� ������ � ����
{ 
	char c[count];		
	F = fopen("F.txt", "wt");
		if (F != NULL)
		{
			printf("������� �������\n");
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
	
		char s[] = { '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�',
			'�', '�', '�', '�', '�', '�', '�', '�', '�' }; //���������
		char p[] = { '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�',
			'�', '�', '�', '�', '�', '�', '�', '�', '�' };   //��������
		F = fopen("F.txt", "rt");
		G = fopen("G.txt", "wt");
		if (F != NULL)
		{						
			char c=NULL;
			do  //���� ���� �� ����� �����
			{			
				bool q = false;			//���������� ������� ������ �������	
				c = fgetc(F);  //���������� �������� 
				if (c != EOF)
				{
					for (int t = 0; t < 34; t++) //����� �������� � ������
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

	int readfile(FILE *G,char* p)  //��������� ������ ����� 
	{
		char c=NULL;  //���������� ��� ���������� ��������
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