#ifndef _AVL_SEARCH_TREE_H_
#define _AVL_SEARCH_TREE_H_

#define NOTEXIST -100
typedef int ElementType;
struct AVLNode;
typedef struct AVLNode *AVLTree;
typedef AVLNode *AVLSubtree;
typedef AVLSubtree Position;
typedef struct AVLNode{
	ElementType element;
	AVLSubtree rightChild;
	AVLSubtree leftChild;
	int height;
}AVLNode;

// typedef enum {
	// ENUM_FALSE,
	// ENUM_TRUE
// }FUNCION_STATE;

//function prototype declaration

//Operation: make a new emptytree
//	   Before: nothing to trans
//		 After: the function return a AVLTree which is a pointer to AVLNode
AVLTree makeAnAVLTree(void);

//Operation: Make a AVLTree empty
//	   Before: T is a tree that should be already initilized
//		 After: T become a enmty tree which means all nodes in T have been
//				  been freed and T itself is a NULL pointer
void makeEmpty(AVLTree T);

//Operation: Judge if T is empty
//   Before: T is a pointer to an AVL tree and it shouldn't be changed in the
//           function.
//    After: If T is empty , it returns 1,
//           else it returns 0.
int isEmpty(const AVLTree T);

//Operation: Find the node where the max element is.
//   Before: T is a AVL tree which shouldn't be changed.
//    After: It will return the node which includes the max element.
Position findMax(const AVLTree T);

//Operation: Find the node where the min element is.
//   Before: T is a AVL tree which shouldn't be changed.
//    After: It will return the node which includes the min element.
Position findMin(const AVLTree T);

//Operation: Find what its element is in P of T.By the way the word "retrieve" means index?
//   Before: P is the node of T , and T is a parameter which is for structure clear
//           and not actually useful here.
//    After: The function return the element in P if P is actually in T.
//           Oterwise it will return -100 which is decided for now.
ElementType retrieveElement(Position P , const AVLTree T);//检索节点P并返回P中的值

//Operation: This function will find the node in T which node has the element equal to X.
//   Before: X is the element user wanna to find , and T is the tree where user looks for.j
//    After: The function returns the pointer to node which has the element equal to X in T.
//           It returns NULL if there is no such a node which includes element value equal to X.
Position findNode(const ElementType X , const AVLTree T);

//Operation: This function is used to find the node which has an element value equal to X in T
//           and delete the node from T.
//   Before: X is the element value to be deleted from T.
//    After: The function finds the node in T and frees it. Then it returns the pointer to the 
//           new AVL tree where ther is no node with element X included.
AVLTree deleteAVLNode(const ElementType X, AVLTree T);

//Operation: This function is used to insert a new element X to the tree T.
//   Before: X is the element value to be inserted to the tree T.
//    After: It returns a pointer to the new AVL tree which has getten the balance property after 
//           instering a new node with the element equal to X. 
AVLTree insertAVLNOde(const ElementType X,AVLTree T);

#endif