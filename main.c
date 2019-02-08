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

void DisposeBTS(struct node * currentNode)
{
	if(currentNode != NULL)
	{
		 if(currentNode->left != NULL)
		 {
			 DisposeBTS(currentNode->left);
			 currentNode->left = NULL;
		 }
		 
		 if(currentNode->right != NULL)
		 {
			 DisposeBTS(currentNode->right);
			 currentNode->right = NULL;
		 }
		 
		 if(currentNode->left == NULL && currentNode->right == NULL)
		 {
			 free(currentNode);
		 }
	}
}

struct node * BSTLowestNode(struct node * currentNode)
{
	if(currentNode->left == NULL)
		return currentNode;
	else
		return  BSTLowestNode(currentNode->left);
}


struct node * BSTDelete(struct node * currentNode, int data)
{
	if (currentNode != NULL)
	{
		if(data == currentNode->data) 
		{
			if(currentNode->left == NULL && currentNode->right == NULL)//es nodo hoja
			{
				free(currentNode);
				return NULL;
			}
			else if(currentNode->left != NULL && currentNode->right != NULL) //el nodo tiene referencia a 2 nodos
			{
				struct node * lowestNode = BSTLowestNode(currentNode->right);
				currentNode->data = lowestNode->data;
				currentNode->right = BSTDelete(currentNode->right,lowestNode->data);
			}
			else
			{ 
				struct node * childNode = NULL;
				if(currentNode->left != NULL)
				{
					childNode = currentNode->left;
					free(currentNode);
					return childNode;
				}
				else
				{
					childNode = currentNode->right;
					free(currentNode);
				}
				return childNode;
			}
		}
		else if(data < currentNode->data)
		{
			currentNode->left = BSTDelete(currentNode->left, data);
		}
		else if(data > currentNode->data)
		{
			currentNode->right = BSTDelete(currentNode->right, data);
		}
	}
	return currentNode;
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
		bst->root = BSTInsert(bst->root, 50);  //inicializamos el nodo raiz
		BSTInsert(bst->root, 30);
		BSTInsert(bst->root, 75);
		BSTInsert(bst->root, 35);
		BSTInsert(bst->root, 25);
		BSTInsert(bst->root, 33);
		BSTInsert(bst->root, 40);
		BSTInsert(bst->root, 39);
		BSTInsert(bst->root, 45);
		BSTInsert(bst->root, 70);
		BSTInsert(bst->root, 60);
		BSTInsert(bst->root, 85);
		BSTInsert(bst->root, 70);
		BSTInsert(bst->root, 90);
		BSTInsert(bst->root, 80);
	
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
		
		BSTDelete(bst->root, 25);
		BSTDelete(bst->root, 70);
		BSTDelete(bst->root, 35);
		//liberamos la memoria alocada dinamicamente por el bst
		DisposeBTS(bst->root);
		free(bst);
	return 0;
}
