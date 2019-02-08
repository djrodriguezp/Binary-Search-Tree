#include <stdio.h>
#include <stdlib.h> 

struct node {
	int data;
	struct node *left;
	struct node *right;
};

struct bst{
	struct node *root;
};

struct node * CreateNode(int data)
{
		struct node * node = (struct node *) malloc(sizeof(struct node)); 
		node->data = data;
		node->left = NULL;
	  node->right = NULL;
		return node;
}

void BSTPrint(struct bst * bst)
{
}

void BSTFreeNodes(struct node * currentNode)
{
	if(currentNode != NULL)
	{
		 if(currentNode->left != NULL)
		 {
			 BSTFreeNodes(currentNode->left);
			 currentNode->left = NULL;
		 }
		 
		 if(currentNode->right != NULL)
		 {
			 BSTFreeNodes(currentNode->right);
			 currentNode->right = NULL;
		 }
		 
		 if(currentNode->left == NULL && currentNode->right == NULL)
		 {
			 free(currentNode);
		 }
	}
}

struct node * BSTSearch(struct node * currentNode, int data)
{
	if(currentNode != NULL)
	{
		 if(currentNode->data == data)
		 {
				return currentNode;
		 }
		 else if (data < currentNode->data)
		 {
				return BSTSearch(currentNode->left, data);
		 }
		 else if (data > currentNode->data)
		 {
				return BSTSearch(currentNode->right, data);
		 }
	}
	return NULL;
}



struct node * BSTInsert(struct node * currentNode, int data)
{
	if(currentNode == NULL)
	{
		return CreateNode(data);
	}
	else if(data < currentNode->data )
	{
		currentNode->left = BSTInsert(currentNode->left,data);
	}
	else if(data > currentNode->data)
	{
		currentNode->right = BSTInsert(currentNode->right,data);
	}

	return currentNode;
}

int main()
{

		struct bst *bst = (struct bst *) malloc(sizeof(struct bst));
		bst->root = NULL;
		bst->root = BSTInsert(bst->root, 8);  //inicializamos el nodo raiz
		BSTInsert(bst->root, 12);
		BSTInsert(bst->root, 10);
		BSTInsert(bst->root, 9);
		BSTInsert(bst->root, 6);
		BSTInsert(bst->root, 7);
		BSTInsert(bst->root, 4);
	
	  struct node * node = BSTSearch(bst->root, 5);
	  if( node != NULL)
		{
			printf("Nodo encontrado: %d\n",node->data);
		}
		else
		{
			printf("Nodo no encontrado\n");
		}
		
		node = BSTSearch(bst->root, 10);
		if( node != NULL)
		{
			printf("Nodo encontrado: %d\n",node->data);
		}
		else
		{
			printf("Nodo no encontrado\n");
		}
		
		//liberamos la memoria alocada dinamicamente por el bst
		BSTFreeNodes(bst->root);
		free(bst);
	return 0;
}
