#include <stdio.h>
#include <stdlib.h>


typedef struct node_t //узел очереди
{
	int value; //Значение в очереди
	struct node_t* next; //Указатель на следующий узел
} Tnode;

typedef struct Queue_t //Очередь
{
	Tnode* head; //Голова
	Tnode* tail; //Хвост
}TQueue;
//Прототипы функций
TQueue* push(TQueue* queue, int value); //Фунукция вставки в очередь 7444 n r
TQueue* invert(TQueue* queue); //Функция инвертирования очереди
void ShowQ(TQueue* queue); //Процедра просмотра очереди без выталкивания

int main()
{
	TQueue* queu=malloc(sizeof(TQueue)); //Выделение памяти под очереди
	queu->head = NULL;
	queu->tail = NULL;
		
	
	for (int i = 0; i < 100; i++) //Заполнение очереди
	{
		push(queu, i);

	}
	

	ShowQ(queu); //Просмотр очереди
	printf("%s", "\n");
	queu=invert(queu); //Инвертирование очереди
	ShowQ(queu);	//Просмотр инвертированой  очереди
	printf("%s", "\n");
	getchar();
}

TQueue* push(TQueue* queue, int value) //Фунукция вставки в очередь
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

int pop(TQueue* queue) //Фунукция просмотра с вытеснением
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
	TQueue* tmpquel = malloc(sizeof(TQueue)); //Выделяем память под новую очередь 
	tmpquel->head = NULL;
	tmpquel->tail = NULL;
	Tnode* tmpnode=NULL; //Указатель вспомогательного узла
	Tnode* nodeoct=NULL; //Указатель основного узла
	
	nodeoct = queue->head;   //Присваиваем первый элемент очереди

	while (nodeoct != NULL)  //Пока не прошли все узлы
	{
		if (nodeoct->next != NULL)  //Двигаемся пока не последний элемент очереди 
		{
			tmpnode = nodeoct;  //Запоминаем предыдущий элемент для возврата к нему
			nodeoct = nodeoct->next;
		}
		else  //Если последний элемент очереди
		{
			push(tmpquel, nodeoct->value);  //Вставляем значение в новую очередь
			tmpnode->next = NULL;  //Делаем предпоследний элемент последним
			free(nodeoct);  //Освобождаем память последнего элемента
			if (nodeoct != queue->head)  //Если не последний оставшийся элемент в очереди
			{
				nodeoct = queue->head;  //Проходим очередь сначала
			}
			else  //Выходим с цикла т.к все элементы старой очереди удалены
			{
				nodeoct = NULL;
			}

		}
	}

	
	return tmpquel;
}

void ShowQ(TQueue* queue)  //Процедра просмотра очереди без выталкивания
{
	Tnode* node = queue->head;
	while (node!=NULL)
	{
		printf("%d ", node->value);
		node = node->next;
	}

}