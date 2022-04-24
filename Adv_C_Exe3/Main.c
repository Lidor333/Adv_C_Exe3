#include <stdio.h>
#include "Stack.h"
#include "Queue.h"

void main()
{
	Stack stack;
	Stack* s = &stack;
	initStack(s);
	push(s, 'a');
	printf("pushed, expcets 'a'='%c'\n", s->head->data);
	printf("pop expects 'a'='%c'\n", pop(s));
	printf("isEmptyStack expects '1'='%d'\n", isEmptyStack(s));
	//STACKS EXE
	//Exe I
	char sentence1[] = "Remem#reb# thi#crap s#tice"; // Temp 1
	flipBetweenHashes(sentence1);
	printf("\n");
	
	destroyStack(s);

	//Exe II
	char sentence3[] = "NOON";
	for (int i = 0; i < strlen(sentence3); i++)
		push(s, sentence3[i]);
	if (isPalindrome(s))
		printf("Palindrome\n");
	else
		printf("Not Palindrome\n");

	char sentence4[] = "MADAM";
	for (int i = 0; i < strlen(sentence4); i++)
		push(s, sentence4[i]);
	if (isPalindrome(s))
		printf("Palindrome\n");
	else
		printf("Not Palindrome\n");

	//Exe III
	char sentence5[] = "ABCDEF";
	for (int i = 0; i < strlen(sentence5); i++)
		push(s, sentence5[i]);
	rotateStack(s, 3);
	display(s);
	

}