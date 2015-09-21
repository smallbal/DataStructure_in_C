#include <stdlib.h>
#include  "binary_search_tree.h"

/* static function prototype */
static ElementType BinarySearchTreeCopyElement(const ElementType X);
static FUNCTIONSTATE BinarySearchTreeCmpElement(const ElementType X,const ElementType Y);
static Position FindNodesParent(const ElementType X , const BinarySearchTree T);
/*static function declaration */
static ElementType BinarySearchTreeCopyElement ( const ElementType X)
{
  return X ;
}

static FUNCTIONSTATE BinarySearchTreeCmpElement(const ElementType X ,const ElementType Y)
{
  FUNCTIONSTATE ReturnValue ; 
  if(X == Y)
    ReturnValue = FUNC_EQUAL;
  else 
     ReturnValue = X>Y?FUNC_BIGER:FUNC_SMALLER;
  return ReturnValue ;
}

static Position FindNodesParent(const ElementType X , BinarySearchTree T)
{
  Position PsFather = T;
  FUNCTIONSTATE State;
  while((State = BinarySearchTreeCmpElement(X , T->element))!= FUNC_EQUAL)
  {
    PsFather = T;
    T = (State == FUNC_BIGER)?T->rightnode:T->leftnode;
  }
  return PsFather;
}

/* extern functino declaratino */
BinarySearchTree MakeBinarySearchTree(const ElementType X)
{
  BinarySearchTree init_tree = (BinarySearchTree)malloc(sizeof(Node));
  if(init_tree == NULL)
    return NULL ; 
  init_tree->leftnode = NULL;
  init_tree->rightnode = NULL;
  init_tree->element = BinarySearchTreeCopyElement(X);
  return init_tree;
}



FUNCTIONSTATE IsEmpty(const BinarySearchTree T)
{
	return (T == NULL) ? FUNC_TRUE : FUNC_FAILURE;
}

FUNCTIONSTATE MakeBinarySearchTreeEmpty(BinarySearchTree T)
{
  /*
  if(IsEmpty(T)==FUNC_TRUE) 
    return FUNC_TRUE; 
  if(IsEmpty(T->leftnode)==FUNC_FAILURE)
  {
    MakeBinarySearchTreeEmpty(T->leftnode);
  }
  if(IsEmpty(T->rightndoe) == FUNC_FAILURE)
  {
    MakeBinarySearchTreeEmpty(T->rightnode);
  }
  free(T);
  return FUNC_TRUE;
  */
  if(IsEmpty(T) ==FUNC_FAILURE)
  {
    MakeBinarySearchTreeEmpty(T->leftnode);
    MakeBinarySearchTreeEmpty(T->rightnode);
    free(T);
  }
  return FUNC_TRUE;
  /*以上为书中代码*/
}

void InsertNode(ElementType X, BinarySearchTree *T)
{
  if(IsEmpty(*T)==FUNC_TRUE)	/*	element	2	int*/

  {
    (*T) = MakeBinarySearchTree(X);
  }
  else
  {
    switch(BinarySearchTreeCmpElement((*T)->element,X))
    {
      case FUNC_EQUAL:
	break;
      case FUNC_BIGER:
	InsertNode(X , &(*T)->leftnode);
	break;
      case FUNC_SMALLER:
	InsertNode(X , &(*T)->rightnode);
	break;
    }
  }
}

Position FindNode(const ElementType X, const BinarySearchTree T)
{
  Position P;
  if(IsEmpty(T) == FUNC_TRUE)
    P = NULL;
  switch(BinarySearchTreeCmpElement(T->element,X))
  {
    case FUNC_EQUAL:
      P = T;
      break;
    case FUNC_BIGER:
      P = FindNode(X , T->leftnode);
      break;
    case FUNC_SMALLER:
      P = FindNode(X , T->rightnode);
      break;
  }
  return P;
}


FUNCTIONSTATE DeleteNode(ElementType X, BinarySearchTree T)
{
  Position P = FindNode(X ,T);
  FUNCTIONSTATE ReturnValue;
  if(P == NULL)
    ReturnValue =  FUNC_FAILURE;
  else
  {
	Position Q = FindNodesParent(X , T);
	switch (BinarySearchTreeCmpElement(Q->element , P->element))
	{
	case FUNC_BIGER:
		Q->leftnode = P->leftnode;
		while(IsEmpty(P->leftnode) == FUNC_FAILURE)
			P->leftnode = P->leftnode->rightnode ; 
		P->leftnode = P->rightnode;
		break;
	case FUNC_SMALLER:
		Q->rightnode = P ->leftnode;
		while(IsEmpty(P->leftnode) == FUNC_FAILURE)
			P->leftnode = P->leftnode->rightnode;
		P->leftnode = P->rightnode;
		break;
	}
	free(P);
	ReturnValue = FUNC_TRUE;
  }
}

ElementType FindMaxElement(BinarySearchTree T)
{
  while(T->rightnode != NULL)
    T = T->rightnode;
  return T->element;
}


ElementType FindMinElement( BinarySearchTree T)
{
  while(T->leftnode != NULL)
    T = T->leftnode;
  return T->element;
}

//There are lots of problems
FUNCTIONSTATE Traversal(const BinarySearchTree T)
{
	if (IsEmpty(T) == FUNC_TRUE)
	{
		printf("\t");
		return FUNC_FAILURE;
	}
    
  printf("%d\t",T->element);
  Traversal(T->leftnode);
  Traversal(T->rightnode);
  printf("\n");
  return FUNC_TRUE;
}


