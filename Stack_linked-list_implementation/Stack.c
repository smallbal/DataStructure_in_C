#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"
/*---------------function prototypes---------------*/
static void StackPopError(void);
static void StackPushError(void);
//Operaton: Copy one StackElement vairable to the other one.
//Before  : the element is copied from Y to X, and the Stack S is a
//          dummy parameter which Marks the type of the element.
//          Both X and Y are pointers to the StackElement type.      
//After   : the block of StackElement X is the same as the one
//          of Y.
static void StackElementCopy(StackElement X, const StackElement Y, const Stack S);


/*---------------function defination---------------*/

static void StackElementCopy(StackElement *X,const StackElement *Y,const Stack S)
{
	(*X) = (*Y);
}
int IsEmpty(const Stack S)
{
	return S->size == 0;
}

int IsFull(const Stack S) 
{
	return S->size == S->capacity ;
}

Stack CreateStack(void)
{
	Stack stacktmp = (Stack *)malloc(sizeof(Stack));
	if(stacktmp == NULL)
		return NULL;
	 stacktmp->stack = (Node *)malloc(sizeof(Node));
	 if(stacktmp->stack == NULL)
		 return NULL;
	 stacktmp->stack->next = NULL;
	 // StackElementCopy(&(stacktmp->stack->element),GetStackAddress(Stack_BelowBottle),stacktmp);
	 stacktmp->stack->element = Stack_BelowBottle;
	//stacktmp->stack = NULL;
	stacktmp->size = Stack_Empty;
	stacktmp->capacity = Stack_Capacity ; 
	// stacktmp->topOfStack = NULL;
	return stacktmp;
}


static void StackPopError()
{
	printf("The stack now is already empty\n");
}
StackElement Pop(Stack S)
{
	if(IsEmpty(S))
	{	StackPopError();
		return ;
	}
	PtrNode poptmp = S->stack->next;
	StackElement elementtmp = poptmp->element;//S->stack->next->element;
	// StackElementCopy(&(elementtmp),&(poptmp->element),S);
	S->stack->next = poptmp->next;
	poptmp->next = NULL;
	free(poptmp);
	S->size--;
	return elementtmp;
}

static void StackPushError(void)
{
	puts("The satck now is already full");
}
void Push(StackElement X , Stack S)
{
	if(IsFull(S))
	{
		StackPushError();
		return ; 
	}
	PtrNode pushtmp = (PtrNode )malloc(sizeof(Node));
	pushtmp->element = X; //I assume the X can use "=" directly
	// StackElementCopy(&(pushtmp->element),&X,S);
	//before: pushtmp->next = S->stack->next;
	pushtmp->next = S->stack->next;
	S->stack->next = pushtmp;
	S->size++;
}

int DisposeStack(Stack S)
{
	while(IsEmpty(S) == Stack_False)
		Pop(S);
	return Stack_True;
}