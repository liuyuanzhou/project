#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

void enqueue(Queue *q,Node *n)
{
	if(q->len == 0)
	{
		q->head = q->tail = n;
	}
	else
	{
		q->tail->next = n;
		q->tail = n;
	}
}

Node* dequeue(Queue *q)
{
	if(q->len == 0)
		return NULL;
	else
	{
		Node *n = q->head;
		q->len--;
		if(q->len == 0)
			q->head = q->tail = NULL;
		else if(q->len == 1)
			q->head = q->tail = n->next;
		else
			q->head = n->next;
		return n;
	}
}

int dequeueItems(Queue *q,int count,Node *r)
{
	int getCount;
	if(q->len >= count)
		getCount = count;
	else 
		getCount = q->len;
	Node *n[getCount];
	int i;
	for(int i=0; i < getCount; i++)
	{
		n[i] = dqueue(q);
	}
	r = n[0];
	return getCount;
}

int main()
{
	Node *n = malloc(sizeof(Node));
	n->value = "liu";
	Node *m = malloc(sizeof(Node));
	n->value = "yuanzhou";
	Queue *q = malloc(sizeof(Queue));
	enqueue(q,n);
	qnqueue(q,m);
	Node *k;
	int count = dequeueItems(q,10,k);
	while(count>0)
	{
		printf("%s ",*(k+count-1))
	}


	return 1;
}
