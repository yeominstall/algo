#include<iostream>
#include <cstdio>
using namespace std;

typedef struct Node {
	int data;
	struct Node* left;
	struct Node* right;

}Node;

void insert_Node(Node* node, int x)
{
	Node* parent;
	Node* tmp;
	Node* newNode;
	parent = NULL;
	tmp = node;

	while (tmp != NULL)
	{
		parent = tmp;
		if (tmp->data > x)
		{
			if (tmp->left != NULL)
				tmp = tmp->left;

			else
				break;
		}



		else
		{
			if (tmp->right != NULL)
				tmp = tmp->right;

			else
				break;
		}


	}

	newNode = new Node;

	if (parent->data > x)
		parent->left = newNode;

	else
		parent->right = newNode;

	newNode->data = x;
	newNode->left = NULL;
	newNode->right = NULL;

}
void postOrder(Node* node)
{
	if (node)
	{
		postOrder(node->left);

		postOrder(node->right);

		cout << node->data << ' ';

	}
}
int main()
{
	int root_data;
	cin >> root_data;

	Node* root = new Node;
	root->data = root_data;
	root->left = NULL;
	root->right = NULL;

	int x;

	while (cin >> x)
	{

		if (x != EOF)
			insert_Node(root, x);
	}
	postOrder(root);
}