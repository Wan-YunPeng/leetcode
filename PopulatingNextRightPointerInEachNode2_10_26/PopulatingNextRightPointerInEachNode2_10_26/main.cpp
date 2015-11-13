#include <iostream>

using namespace std;

struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode *next;
	TreeNode(int x) :val(x), left(nullptr), right(nullptr), next(nullptr){};
};

void connect(TreeNode *root);
void connect2(TreeNode *root);

int main()
{
	TreeNode root(1);
	root.left = &TreeNode(2);
	root.left->left = &TreeNode(4);
	root.left->right = &TreeNode(5);
	root.right = &TreeNode(3);
	root.right->right = &TreeNode(7);

	connect2(&root);
	TreeNode *p = &root;
	while (p != nullptr)
	{
		TreeNode *tmp = p;
		while (tmp != nullptr)
		{
			cout << tmp->val << " ";
			tmp = tmp->next;
		}
		cout << endl;
		p = p->left;
	}
	return 0;
}


void connect(TreeNode *root)
{
	if (root == nullptr) return;
	//cout << "a" << endl;
	TreeNode dumpy(-1); // 作为每行的头节点
	for (TreeNode *cur = root, *prev = &dumpy; cur != nullptr; cur = cur->next) // 下一层的所有节点。 cur==root当前层的所有节点已经相连
	{
		if (cur->left != nullptr)
		{
			prev->next = cur->left;
			prev = prev->next;
		}
		if (cur->right != nullptr)
		{
			prev->next = cur->right;
			prev = prev->next;
		}
	}
	connect(dumpy.next);
}

void connect2(TreeNode *root)
{
	TreeNode *p = root;
	while (p)
	{
		TreeNode *next = nullptr;
		TreeNode *prev = nullptr;
		for (; p; p = p->next)
		{
			if (!next) next = p->left ? p->left : p->right;

			if (p->left)
			{
				if (prev) prev->next = p->left;
				prev = p->left;
			}

			if (p->right)
			{
				if (prev) prev->next = p->right;
				prev = p->right;
			}
		}
		p = next;
	}

}