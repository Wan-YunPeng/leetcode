#include <iostream>
#include <algorithm>
using namespace std;

struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) :val(x), left(nullptr), right(nullptr){};
};

int maxDepth(TreeNode *root);

int main()
{
	TreeNode root(1);
	root.left = &TreeNode(2);
	root.right = &TreeNode(3);
	root.right->left = &TreeNode(4);
	root.right->left->right = &TreeNode(5);
	int re = maxDepth(&root);
	cout << re << endl;
	return 0;
}

int maxDepth(TreeNode *root)
{
	if (root == nullptr) return 0;
	if (root->left == nullptr && root->right == nullptr) return 0;
	return 1 + max(maxDepth(root->left), maxDepth(root->right));
}