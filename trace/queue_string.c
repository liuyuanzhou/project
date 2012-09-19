#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "queue_string.h"

void enqueue(Queue *q,char *p)
{
	/*printf("ready to enqueue string : %s",p);*/
	char *c = malloc(strlen(p)+1);
	if(c == NULL)
	{
		printf("out of memory when malloc enqueue string\n");
		exit(1);
	}	
	Node *n = malloc(sizeof(Node));
	if(n == NULL)
	{
		printf("out of memory when malloc enqueue node\n");
		exit(1);
	}
	n->value = strcpy(c,p);
	n->next = NULL;
	if(q->len == 0)
		q->head = n;
	else
		q->tail->next = n;
	q->tail = n;
	q->len++;
}

char *dequeue(Queue *q)
{
	char *p = malloc(strlen(q->head->value)+1);
	if(q->len <= 0)
		p = NULL;
	else
	{
		p = strcpy(p,q->head->value);
		if(q->len == 1)
			q->head = q->tail = NULL;
		else
		{
			Node *n = q->head;
			q->head = q->head->next;
			free(n);
		}
		q->len--;
	}
	return p;
}

int main()
{
	Queue *q = malloc(sizeof(Queue));
	if(q == NULL)
	{
		printf("out of memory when main malloc Queue\n");
		exit(1);
	}
	enqueue(q,"first line!\n");
	enqueue(q,"second line!\n");
	enqueue(q,"third line!\n");

	printf("queue value:%s,%s,%s",q->head->value,q->head->next->value,q->head->next->next->value);
	char *p = dequeue(q);
	free(p);
	printf("queue value:%s,%s",q->head->value,q->head->next->value);
	/*int k = q->len;
	for(;k > 0 ;k--)
	{
		printf("%s",dequeue(q));
	}*/
	return 1;
}
