#include "Stack.h"
#include <stdio.h>
#include<stdlib.h>
#include<string.h>

/***************** Stack ADT Implementation *****************/

void initStack(Stack* s) 
{ 
	s->head = NULL; // check it the stack is exists
}

void destroyStack(Stack* s)
{
	charNode* tmp = s->head; 
	while (s->head != NULL)
	{
		s->head = s->head->next;
		free(tmp);
		tmp = s->head;                //free stack
	}

}

void push(Stack* s, char data)
{
	charNode* newnode = (charNode*)malloc(sizeof(charNode)); // new allocation 
	if (newnode == NULL) // check if the allocation exists
	{
		printf("push: memory allocation problem\n");
		return;
	}
	newnode->data = data; //push data
	newnode->next = s->head; // connect to stack s
	s->head = newnode; // move the head to the new head

}

char pop(Stack* s)
{
	char res;
	if(s->head==NULL)
	{
		printf("\nSTACK IS EMPTY");
		return 0; //check if the stack is empty
	}
	res = s->head->data; //pop it from the stack
	charNode* tmp = s->head; //Now remove used node
	s->head = s->head->next;
	free(tmp);
	return res;
}


int isEmptyStack(const Stack* s)
{
	if (s->head == NULL)
		return 1;
	else
		return 0;
	
}

/*************** Functions using stacks - Implementation/definition **************************/

void flipBetweenHashes(const char* sentence)
{
	int i = 0,num=0;
	Stack* temp1 = (Stack*)malloc(sizeof(Stack)); // new allocation 
	if (temp1 == NULL) // check if the allocation exists
	{
		printf("push: memory allocation problem\n");
		return;
	}
	Stack* temp2 = (Stack*)malloc(sizeof(Stack)); // new allocation 
	if (temp2 == NULL) // check if the allocation exists
	{
		printf("push: memory allocation problem\n");
		return;
	}

	for (; i < strlen(sentence); i++) { //pass all the sentence
		num++;
		if (*(sentence+i) == '#') { //getting to the first hash
 			i++;
			push(temp1, pop(sentence)); //move the items between the hashes to temp1
			if (*(sentence+i) == '#') { //stop when getting to the second hash
				return;
			}
			while (temp1->head != NULL) { //move the items from temp1 to temp2
				push(temp2, pop(temp1));
			}
			while (temp2->head != NULL) { //move the items from temp2 to sentence
				push(*(sentence+num), pop(temp2));
			 }
		}
	}
	printf("%s", sentence);
}

int isPalindrome(Stack* s)
{
	int count = 0;
	Stack* temp1 = (Stack*)malloc(sizeof(Stack)); // new allocation 
	if (temp1 == NULL) // check if the allocation exists
	{
		printf("push: memory allocation problem\n");
		return 0;
	}

	for (; s->head != NULL; s->head = s->head->next) { //count items
		count++;
	}

	for (int i = 0; i < count / 2; i++) { 
		push(temp1, pop(s));               //move to temp1(another stack)
	}

	if (count % 2 == 1) {                 //extreme case of odd number
		s->head = s->head->next;
	}

	while ((s->head != NULL) && (temp1->head != NULL)) { //compere the items in the two stacks
		if ((s->head->data) == (temp1->head->data)) {
			s->head = s->head->next;
			temp1->head = temp1->head->next;
		}
		else return 0;
	}
	return 1;
}

void rotateStack(Stack* s, int n)
{
	Stack* temp1 = (Stack*)malloc(sizeof(Stack)); // new allocation 
	if (temp1 == NULL) // check if the allocation exists
	{
		printf("push: memory allocation problem\n");
		return;
	}
	Stack* temp2 = (Stack*)malloc(sizeof(Stack)); // new allocation 
	if (temp2 == NULL) // check if the allocation exists
	{
		printf("push: memory allocation problem\n");
		return;
	}
	int count = 0; 
	if (n < 0) {    //check if the N is negative
		return;
	}

	for (; s->head != NULL; s->head = s->head->next) { //count items
		count++;
	}
	if (n > count) {  //check if the N are bigger than the number of the items on the stack
		return;
	}

	while (s->head != NULL) { //move all the items to temp1
		push(temp1, pop(s)); 
	}

	while (n < 0) {  //move N items from temp1 to temp2 
		push(temp2, pop(temp1));
		n--;
	}
	
	while (temp1->head != NULL) { //move the remain items from temp1 to s 
		push(s, pop(temp1));
	}

	while (temp2->head != NULL) { //move N items from temp2 to temp1
		push(temp1, pop(temp2));
	}

	while (temp1->head != NULL) {  //move N items from temp1 to s
		push(s, pop(temp1));
	}
}