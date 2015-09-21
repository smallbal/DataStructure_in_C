#ifndef _STACK_H_
#define _STACK_H_

#define Stack_Capacity 20
#define Stack_True 1
#define Stack_False 0
#define Stack_Empty 0
#define Stack_OverFlow -1
#define Stack_BelowBottle -2
#define GetFlagsAddress(X) (&(X))
typedef int StackElement;
typedef struct _Node
{
	StackElement element;
	struct _Node *next;
}Node;
typedef Node * PtrNode;
typedef struct _Stack
{
	PtrNode stack;
	int capacity ; 
	int size ;
	// PtrNode topOfStack ;
}*Stack;

/*---------------function prototypes---------------*/

//Operation: test whether the Stack inputed is empty
// Before:   input a Stack variable 
// After :   return Stack_True if the Stack is enmpty
// 		     otherwise return Stack_false.
int IsEmpty(const Stack S);
//Operation: test whether the Stack inputed is full.
//Before   : input a Stack variable.
//After    : return Stack_True if the Stack is full
// 		     otherwise return Stack_false. 
int IsFull(const Stack S);
//Operation: Create a empty Stack implementation.
//Before   : call this function.
//After    : return a Stack virable with a empty Stack.
Stack CreateStack(void );
//Operation: Pop one element from the stack
//Before   : input the stack being used.
//After    : the stack inputed poped an element and return
//			 the element that was on the top of the stack.
StackElement Pop(Stack S);
//Operation: Push one element on the stack.
//Before   : X is the element to push;
//           S is the stack being operation.
//After    : the element X is pushed on the top of the stack.
void Push(StackElement X , Stack S);
//Operation: free the stack.
//Before   : S is the stack to be deleted 
//After    : return Stack_True if the operation is successful,
//           otherwise return Stack_False.
int  DisposeStack(Stack S);

#endif