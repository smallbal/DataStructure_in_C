#include <stdio.h>
#include <stdlib.h>
#include "AVLtree.h"

/* static function declaration */

//transform X to P->element
static int transElementToPosition(Position P , ELementType X) ;
// X1>X2 return 1 ,X1<X2 return 0 , X1=X2 return -1
static int isLager(const ElementType X1, const ELementType X2) ;
static int Height(Position P , const AVLTree T) ;
static int higherOnesValue(Position X , Position Y) ;
static int subjectHeight(Postion P , AVLTree T) ;

static Position LL_singleRotation(Position P , AVLTree T) ; 	//case 1
static Position RR_singleRotation(Position P , AVLTree T) ;	//case 4
//实现left-left&&right-right 和 left-right&&right-left 这四种情况的单旋转
static Position singleRotation(Position P , AVLTree T) ;

static Position LR_doubleRotation(Position P , AVLTree T) ;	//case 2
static Position RL_doubleRotation(Position P , AVLTree T) ;	//case 3
static Position doubleRotation(Position P , AVLETree T) ;

/* static function routine */
static int transElementToPosition(Position P , ElementType X)
{
	if(isEmpty(P)!=1)
		P->element = X ;
}

static int isLager(const ElementType X1 , const ElementType X2)
{
	return (X1>X2)? 1 : ((X1 == X2)? (-1) : 0)
}

static int Height(Position P , const AVLTree T)
{
	if(isEmpty(P)!= 1 )
		return P->height;
	else
		return NOTEXIST ;
}

static int higherOnesValue(Position X , Position Y , const AVLTree T)
{
	int XsHeight , YsHeight ;
	XsHeight = Height(X , T);
	YsHeight = Height(Y , T);
	return XsHeight>YsHeight ? XsHeight : YsHeight ;
}

static void subjectHeight(Postion P , AVLTree T)
{
	if (P != NULL)
		if((isEmpty(P->leftChild) != isEmpty(P->rightChild))||(isEmpty(P->leftChild) == 0))
			P->height = higherOnesValue(P->leftChild , P->rightChild)+ 1 ;
		else 
			P->height = 0 ;
}
static Position LL_singleRotation(Position P , AVLTree T) 	//case 1
{
	Position PsChild;
	if(retrieveElement(P , T)!= NOTEXIST)
	{
		PsChild = P->leftChild ; 
		P->leftChild = PsChild->rightChild ; 
		PsChild->rightChild = P ;
		//P->height = higherOnesValue(P->leftChild , P->rightChild) + 1 ;
		//PsChild->height = higherOnesValue(PsChild->leftChild , PsChild->rightChild) + 1 ;
		subjectHeight(P , T);
		subjectHeight(PsChild , T);
	}
	else
		PsChild = NULL;
	return PsChild ; 
}

static Position RR_singleRotation(Position P , AVLTree T)	//case 4
{
	Position PsChild ; 
	if(retrieveElement(P , T) !=NOTEXIST)
	{
		PsChild = P->rightChild ;
		P->rightChild = PsChild ->leftChild ; 
		PsChild->leftChild = P ; 
		//P->height = higherOnesValue(P->leftChild , P->rightChild)  + 1 ;
		//PsChild->height  = higherOnesValue(PsChild->leftChild , PsChild->rightChild) + 1；
		subjectHeight(P , T) ;
		subjectHeight(PsChild , T) ;
	}
	else
		PsChild = NULL;
	return PsChild ; 
}
static Position LR_doubleRotation(Position P , AVLTree T)	//case 2
{
	Position PsChild ; 
	if(retrieveElement(P , T) != NOTEXIST)
	{
		P->leftChild = RR_sigleRotation(P->leftChild , T) ; 
		P = LL_singleRotation(P , T) ;
	//	P->leftChild->height = higherOnesValue(P->leftChild->leftChild, P->leftChild->rightChild , T) + 1 ;
	//	P->rightChild->height = higherOnesValue(P->rightChild->leftChild , P->rightChild->rightChild , T) + 1 ; 
	//	P->height = higherOnesValue(P->leftChild , P->rightChild , T) + 1 ；
		subjectHeight(P->leftChild , T) ;
		subjectHeight(P->rightChild, T) ;
		subjectHeight(P , T) ;
	}
	else 
		PsChild = NULL;
	return PsChild ;
}

static Position RL_doubleRotation(Position P , AVLTree T)	//case 4
{
	Position PsChild ; 
	if(retrieveElement(P , T) != NOTEXIST )
	{
		P->rightChild = LL_singleRotation(P->rightChild , T) ;
		P = RR_sigleRotation(P , T) ;
		//P->leftChild->height = higherOnesValue(P->leftChild->leftChild, P->leftChild->rightChild , T) + 1 ;
		//P->rightChild->height = higherOnesValue(P->rightChild->leftChild , P->rightChild->rightChild , T) + 1 ; 
		//P->height = higherOnesValue(P->leftChild , P->rightChild , T) + 1 ；
		subjectHeight(P->leftChild , T) ;
		subjectHeight(P->rightChild , T) ;
		subjectHeight(T , T) ;
	}
	else
		PsChild = NULL ;
	return PsChild ;
}


/*external function routine */
AVLTree makeAnAVLTree(ElementType X)
{
	AVLTree new_tree = (AVLTree)malloc(sizof(AVLNode));
	transElementToPosition(new_tree , X);
	new_tree->left = NULL;
	new_tree->right = NULL;
	int height = 0;
	return new_tree;
}

void makeEmpty(AVLTree T)
{
	if(T->left != NULL)
	{
		makeEmpty(T->left);
	}
	if(T->right !=NULL)
	{
		makeEmpty(T->right);
	}
	if(T != NULL)
	{
		free(T);
	}
	else
	{
		return ;
	}
	
}

int isEmpty(const AVLTree T)
{
	return T == NULL;
}

Position findMax(const AVLTree T)
{
	//this is an AVL search binary tree, so the deepest position
	//of the right subtree is the node that include the largest element.
	//The worst running time  in this algorithsm is O(log N).
	Position temp_node = T;
	while(temp_node->right !=NULL)
	{
		temp_node = T->right;
	}
	return temp_node;
}

Position findMin(const AVLTree T)
{
  Position temp_node = T;
  while(temp_node->left != NULL)
  {
    temp_node = T->left;
  }
  return temp_node;
}

ElementType retrieveElement(Position P , const AVLTree T)
{
  /* function body */
  if(findNode(P->element,T)!=NULL)
	  return P->element;
  else 
	  return NOTEXIST ;
}

Position findNode(const ElementType X, const AVLTree T)
{
  Position temp_node = NULL;
  if(T != NULL)
  {
    switch(isLager(X,T->element))
      {
	case 1:
	  P = findNode(X , T->rightChild);
	  break;
	case 0:
	  P = findNode(X , T->leftChild);
	  break;
	case -1:
	  P = T;
	  break;
      }
  }
  return P;
}
/* 晚上继续
AVLTree deleteAVLNode(const ElementType X , AVLTree T)
{
*/
