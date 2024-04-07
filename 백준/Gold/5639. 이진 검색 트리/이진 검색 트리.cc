#include <iostream>
#include <unordered_map>

using namespace std;

struct node
{
	int key;
	node* left;
	node* right;
};

int input = 0;
node* root = nullptr;

void postorder(node* n)
{
	if (n == 0) return;

	postorder(n->left);
	postorder(n->right);
	cout << n->key << '\n';
}

void preorder_input(int val)
{
	node* n = new node{ val, 0, 0 };
	node* pos = root;

	while (1)
	{
		if (pos->key > val)
		{
			if (pos->left == nullptr)
			{
				pos->left = n;
				break;
			}
			else
				pos = pos->left;
		}
		else
		{
			if (pos->right == 0)
			{
				pos->right = n;
				break;
			}
			else
				pos = pos->right;
		}
	}
}

int main(void)
{
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
	cin >> input;
	node* btree = new node{ input, 0, 0 };
	root = btree;

	while (cin >> input)
	{
		if (input == cin.fail())
			break;
		preorder_input(input);
	}
	
	postorder(root);

	return 0;
}