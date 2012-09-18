#ifndef __QUEUE_STRING_H__
#define __QUEUE_STRING_H__

typedef struct Node{
	char *value;
	struct Node *next;
} Node;

typedef struct Queue{
	Node *head;
	Node *tail;
	int len;
} Queue;

void enqueue(Queue *q, char *n);

char* dequeue(Queue *q);

#endif
