#ifndef __QUEUE_H__
#define __QUEUE_H__

struct Node{
	void *value;
	struct *next;
} Node;

struct Queue{
	Node *head;
	Node *tail;
	int len;
} Queue;

void enqueue(Queue *q, Node *n);

void dequeue(Queue *q,int count);

#endif
