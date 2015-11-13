#include <iostream>

using namespace std;

struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) :val(x), left(nullptr), right(nullptr){};
};

bool isBST(TreeNode *root);
// ÖÐÐò±éÀúÅÐ¶ÏÊÇ·ñÉýÐòÊä³ö
bool isBstInorder(TreeNode *root);

int main()
{
	TreeNode root(2);
	root.left = &TreeNode(1);
	root.right = &TreeNode(4);
	root.right->left = &TreeNode(3);
	root.right->right = &TreeNode(5);
	bool re = isBST(&root);
	cout << re << endl;
	return 0;
}

bool isBST(TreeNode *root)
{
	if (root == nullptr) return true;
	int left = root->left ? root->left->val : INT_MIN;
	int right = root->right ? root->right->val : INT_MAX;
	if (left > root->val || root->val > right)
		return false;
	return isBST(root->left) && isBST(root->right);
}

bool isBstInorder(TreeNode *root)
{
	TreeNode *prev = root, *cur;
	cur = root;
	int p, c;

	while (!cur)
	{
		if (cur->left == nullptr)
		{
			p = prev->val;
			if (p > cur->val) return false;
			prev = cur;
			cur = cur->right;
		}
		else
		{
			TreeNode *node = cur->left;
			while (node->right != nullptr && node->right != cur)
			{
				node = node->right;
			}

			if (node->right == nullptr)
			{
				node->right = cur;
				cur = cur->left;
			}
			else
			{
				node->right = nullptr;
				p = prev->val;
				if (p > cur->val) return false;
				prev = cur;
				cur = cur->right;
			}
		}
	}
	return true;
}