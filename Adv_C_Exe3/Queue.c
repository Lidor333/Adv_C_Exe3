#include "Queue.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/***************** Queue ADT Implementation *****************/

void initQueue(Queue* q)
{
	q->head = NULL;
	q->tail = NULL;      //initialize the queue
}

void destroyQueue(Queue* q)
{
	while (!isEmptyQueue(q)) {
		intNode* temp = q->head;
		q->head = q->head->next;
		free(temp);
	}                                 //free all the elements
}

void enqueue(Queue* q, unsigned int data)
{
	intNode* p = (intNode*)malloc(sizeof(intNode));
	p->data = data;
	p->next = NULL;
	if (!isEmptyQueue(q)) q->tail->next = p; // not Empty?
	//Add after last:
	else q->head = p; // Otherwise – it becomes
	//first
	q->tail = p; // update queue tail
}

unsigned int dequeue(Queue* q)
{
	if (isEmptyQueue(q)) {
		printf("Cannot dequeue empty queue");
		return 0;
	}

	int temp = q->head->data;
	intNode* temp1 = q->head;
	q->head = q->head->next;
	free(temp1);
	return temp;              //remove all the items
}

int isEmptyQueue(const Queue* q)
{
	if (q->head == NULL) {
		return 1;
	}
	else return 0;                //check if the queue is empty

}

/***************** Functions using Queues - Implementation/definition **************************/

void rotateQueue(Queue* q)
{
	Queue* temp1 = (Queue*)malloc(sizeof(Queue)); // new allocation
	if (temp1 == NULL) {  // check if the allocation exists
		printf("push: memory allocation problem\n");
		return;
	}
	initQueue(temp1);

	while (q->head != q->tail) { //move all the elements to a new queue except the last one
		enqueue(temp1, dequeue(q));
	}
	while (!isEmptyQueue(temp1))
		enqueue(q, dequeue(temp1)); //move all the remain elements to temp2
}

void cutAndReplace(Queue* q)
{
	int count;
	intNode* current = q->head;
	for (count = 0; current != NULL; current = current->next) {
		count++;
	}
	if (count % 2 != 0) {
		intNode* current = q->head;
		int sum = 0;
		for (; current != NULL; current = current->next) {
			sum += current->data;
		}
		enqueue(q, sum / count);
		count++;
	}

	int half = count / 2;

	Queue* temp1 = (Queue*)malloc(sizeof(Queue)); // new allocation
	if (temp1 == NULL) {  // check if the allocation exists
		printf("push: memory allocation problem\n");
		return;
	}
	initQueue(temp1);

	for (int i = 0; i < half; i++)
		enqueue(temp1, dequeue(q)); //from head need to go to tail

	Queue* temp2 = (Queue*)malloc(sizeof(Queue)); // new allocation
	if (temp2 == NULL) { // check if the allocation exists
		printf("push: memory allocation problem\n");
		return;
	}
	initQueue(temp2);

	for (int i = 0; i < half; i++) {
		rotateQueue(q);
		enqueue(temp2, dequeue(q));
	}

	for (int i = 0; i < half; i++) {
		enqueue(q, dequeue(temp2));
	}

	for (int i = 0; i < half; i++) {
		enqueue(q, dequeue(temp1));
	}
}

void sortKidsFirst(Queue* q)
{
	if (isEmptyQueue(q)) return;

	Queue* temp1 = (Queue*)malloc(sizeof(Queue)); // new allocation
	if (temp1 == NULL) {  // check if the allocation exists
		printf("push: memory allocation problem\n");
		return;
	}
	initQueue(temp1);
	
	int count;
	intNode* current = q->head;
	for (count = 0; current != NULL; current = current->next) {
		count++;                       //count the items in the queue
	}

	while (!isEmptyQueue(q)) {
		int min = dequeue(q);
		count--;
		
		for (int i = 0; i < count; i++) {
			int val = dequeue(q);
			if (min >= val) {
				enqueue(q, min);
				min = val;
			}
			else {
				enqueue(q, val);
			}
		}
		enqueue(temp1, min);
	}
	while (!isEmptyQueue(temp1)) {
		enqueue(q, dequeue(temp1));
	}
}

