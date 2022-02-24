#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	struct node* left;
	struct node* right;
} node;

node* newNode(int data)
{
	node* nod;
    nod = (node*)malloc(sizeof(node));
	nod->data = data;
	nod->left = NULL;
	nod->right = NULL;

	return nod;
}

void printPostorder(node* node)
{
	if (node == NULL)
		return;

	printPostorder(node->left);
	printPostorder(node->right);
	printf("%d ", node->data);
}

void printInorder(node* node)
{
	if (node == NULL)
		return;
	printInorder(node->left);
	printf("%d ", node->data);
	printInorder(node->right);
}

void printPreorder(node* node)
{
	if (node == NULL)
		return;

	printf("%d ", node->data);
	printPreorder(node->left);
	printPreorder(node->right);
}

int main()
{
	node* root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);

	printf("\nPreorder traversal of binary tree is \n");
	printPreorder(root);

	printf("\nInorder traversal of binary tree is \n");
	printInorder(root);

	printf("\nPostorder traversal of binary tree is \n");
	printPostorder(root);

	return 0;
}
