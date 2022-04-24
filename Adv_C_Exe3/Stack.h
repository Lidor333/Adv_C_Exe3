#include <stdio.h>

/***************** Stack ADT Declaration *****************/

typedef struct charNode 
{
	char data;
	struct charNode* next;
}charNode;

typedef struct Stack 
{
	charNode* head;
}Stack;

void initStack(Stack* s);
void destroyStack(Stack* s);
void push(Stack* s, char data);
char pop(Stack* s);
int isEmptyStack(const Stack* s);

/*************** Functions using Stacks - Declaration **************************/

/// <summary>
/// 
/// </summary>
/// <param name="sentence"></param>
void flipBetweenHashes(const char* sentence);

/// <summary>
/// 
/// </summary>
/// <param name="s"> a non null pointer to a struct Stack</param>
/// <returns></returns>
int isPalindrome(Stack* s);

/// <summary>
/// 
/// </summary>
/// <param name="s"> a non null pointer to a struct Stack</param>
/// <param name="n"></param>
void rotateStack(Stack* s, int n);