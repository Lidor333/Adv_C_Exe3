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
	if ((q->head) != (q->tail)) {
		free(q);
		q->head = q->head->next;
	}                                 //free all the elements
}

void enqueue(Queue* q, unsigned int data)
{
	intNode* newnode = (intNode*)malloc(sizeof(intNode)); // new allocation
	if (newnode == NULL) {
		printf("push: memory allocation problem\n");   // check if the allocation exists    
		return;
	}
	newnode->data = data;       //check in information
	newnode->next = NULL;

	if (q->head = q->tail = NULL) {  //put a first item to the queue
		q->tail = q->head = newnode;
	}
	else
		q->tail->next = newnode; //put item in the queue
	q->tail = newnode; //put the item in the first place in the queue
}

unsigned int dequeue(Queue* q)
{
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
	Queue* temp2 = (Queue*)malloc(sizeof(Queue)); // new allocation
	if (temp2 == NULL) { // check if the allocation exists
		printf("push: memory allocation problem\n");
		return;
	}

	if ((q->head) != (q->tail)) { //move all the elements to a new queue except the last one
		enqueue(temp1, dequeue(q));
	}
	enqueue(temp2, dequeue(q)); //move the last element to temp2
	enqueue(temp2, dequeue(temp1)); //move all the remain elements to temp2
}

void cutAndReplace(Queue* q)
{
	int count, avg = 0,i = 0;
	for (count = 0; q->head->next != NULL; q->head = q->head->next) {
		count++;
	}
	if(count%2==0){
		Queue* temp1 = (Queue*)malloc(sizeof(Queue)); // new allocation
		if (temp1 == NULL) {  // check if the allocation exists
			printf("push: memory allocation problem\n");
			return;
		}
		Queue* temp2 = (Queue*)malloc(sizeof(Queue)); // new allocation
		if (temp2 == NULL) { // check if the allocation exists
			printf("push: memory allocation problem\n");
			return;
		}

		for (; i = !count / 2; i++) { 
			enqueue(temp1, dequeue(q));
		}
		for (; i = !count; i++) {
			enqueue(temp2, dequeue(q));
		}
		while (temp2->head != temp2->tail != NULL) {
			enqueue(temp1, dequeue(temp2));
		}

		
	
	}
	else {
		for (; q->head->next != NULL; q->head = q->head->next) {
			avg += q->head->data;
			avg /= count;
			intNode* add = (intNode*)malloc(sizeof(intNode));
			if (!add) {
				add->data = avg;
				add->next = NULL;
			}
		}
	}

}

void sortKidsFirst(Queue* q)
{
	Queue* temp1 = (Queue*)malloc(sizeof(Queue)); // new allocation
	if (temp1 == NULL) {  // check if the allocation exists
		printf("push: memory allocation problem\n");
		return;
	}
	Queue* temp2 = (Queue*)malloc(sizeof(Queue)); // new allocation
	if (temp2 == NULL) { // check if the allocation exists
		printf("push: memory allocation problem\n");
		return;
	}
	int count, k = 0;
	for (count = 0; q->head->next != NULL; q->head = q->head->next) {
		count++;                       //count the items in the queue
	}

	for (int i = 0; i < count; i++) {
		if ((q->head->data) < (q->tail->data)) {  //check if the tail bigger than the head
			q->head = q->head->next;
		}
		if ((q->head->data) > (q->tail->data)) { //check if the head bigger than the tail
			k = q->tail->data;
			q->tail->data = q->head->data;
			q->head->data = k;
		}
		if ((q->head->data) == (q->tail->data)) { //check if the tail and the head equal
			enqueue(temp2, dequeue(q));
			for (; (count - 1) != 0; count--) {
				enqueue(temp1, dequeue(q));
			}
			enqueue(temp1, dequeue(temp2));
			for (; q->head->next != NULL; q->head = q->head->next) {
				enqueue(q, dequeue(temp1));
			}
		}
	}
}

