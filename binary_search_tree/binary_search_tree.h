#ifndef _BINARY_SEARCH_TREE_H_
#define _BINARY_SEARCH_TREE_H_ 

typedef enum FUNCTIONSTATE{
  FUNC_TRUE,
  FUNC_FAILURE,
  FUNC_BIGER,
  FUNC_SMALLER,
  FUNC_EQUAL
}FUNCTIONSTATE;

typedef int ElementType;
struct _node;
typedef struct _node *BinarySearchTree;
typedef BinarySearchTree Position;


typedef struct _node
{
  ElementType element;
  Position leftnode;
  Position rightnode;
}Node;
  
BinarySearchTree MakeBinarySearchTree(const ElementType X);
FUNCTIONSTATE MakeBinarySearchTreeEmpty(BinarySearchTree T);
FUNCTIONSTATE IsEmpty(const BinarySearchTree T);
void InsertNode(ElementType X, BinarySearchTree *T);
//Position FindNode(const ElementType X, const BinarySearchTree T);
Position FindNode(const ElementType X, BinarySearchTree T);
FUNCTIONSTATE DeleteNode(ElementType X, BinarySearchTree T);
//ElementType FindMaxElement(const BinarySearchTree T);
//ElementType FindMinElement(const BinarySearchTree T);
ElementType FindMaxElement(BinarySearchTree T);
ElementType FindMinElement(BinarySearchTree T);
FUNCTIONSTATE Traversal(const BinarySearchTree T);//There are lots of problems
#endif
