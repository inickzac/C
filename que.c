#include <stdio.h>
#include <stdlib.h>


typedef struct node_t //���� �������
{
	int value; //�������� � �������
	struct node_t* next; //��������� �� ��������� ����
} Tnode;

typedef struct Queue_t //�������
{
	Tnode* head; //������
	Tnode* tail; //�����
}TQueue;
//��������� �������
TQueue* push(TQueue* queue, int value); //�������� ������� � ������� 7444 n r
TQueue* invert(TQueue* queue); //������� �������������� �������
void ShowQ(TQueue* queue); //�������� ��������� ������� ��� ������������

int main()
{
	TQueue* queu=malloc(sizeof(TQueue)); //��������� ������ ��� �������
	queu->head = NULL;
	queu->tail = NULL;
		
	
	for (int i = 0; i < 100; i++) //���������� �������
	{
		push(queu, i);

	}
	

	ShowQ(queu); //�������� �������
	printf("%s", "\n");
	queu=invert(queu); //�������������� �������
	ShowQ(queu);	//�������� ��������������  �������
	printf("%s", "\n");
	getchar();
}

TQueue* push(TQueue* queue, int value) //�������� ������� � �������
{
	Tnode* node = malloc(sizeof(Tnode));
	node->value = value;
	node->next = NULL;
	if (queue->head && queue->tail)
	{
		queue->tail->next = node;
		queue->tail = node;

	}
	else
	{
		queue->head = queue->tail = node;
	}
	return queue;
}

int pop(TQueue* queue) //�������� ��������� � �����������
{
	int value = 0;
	Tnode* node;
	
		node = queue->head;
		value = node->value;
		queue->head = node->next;
		free(node);
	return value;
} 

TQueue* invert(TQueue* queue)
{
	TQueue* tmpquel = malloc(sizeof(TQueue)); //�������� ������ ��� ����� ������� 
	tmpquel->head = NULL;
	tmpquel->tail = NULL;
	Tnode* tmpnode=NULL; //��������� ���������������� ����
	Tnode* nodeoct=NULL; //��������� ��������� ����
	
	nodeoct = queue->head;   //����������� ������ ������� �������

	while (nodeoct != NULL)  //���� �� ������ ��� ����
	{
		if (nodeoct->next != NULL)  //��������� ���� �� ��������� ������� ������� 
		{
			tmpnode = nodeoct;  //���������� ���������� ������� ��� �������� � ����
			nodeoct = nodeoct->next;
		}
		else  //���� ��������� ������� �������
		{
			push(tmpquel, nodeoct->value);  //��������� �������� � ����� �������
			tmpnode->next = NULL;  //������ ������������� ������� ���������
			free(nodeoct);  //����������� ������ ���������� ��������
			if (nodeoct != queue->head)  //���� �� ��������� ���������� ������� � �������
			{
				nodeoct = queue->head;  //�������� ������� �������
			}
			else  //������� � ����� �.� ��� �������� ������ ������� �������
			{
				nodeoct = NULL;
			}

		}
	}

	
	return tmpquel;
}

void ShowQ(TQueue* queue)  //�������� ��������� ������� ��� ������������
{
	Tnode* node = queue->head;
	while (node!=NULL)
	{
		printf("%d ", node->value);
		node = node->next;
	}

}