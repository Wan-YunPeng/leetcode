#include <iostream>
#include <algorithm>
using namespace std;

struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int val) :val(val), left(nullptr), right(nullptr){};
};

bool balancedTree(TreeNode *root);
int subTreeHeight(TreeNode *root);

int main()
{
	TreeNode root(1);
	root.left = &TreeNode(2);
	root.right = &TreeNode(3);
	root.right->left = &TreeNode(4);
	bool re = balancedTree(&root);
	cout << re << endl;
	return 0;
}

bool balancedTree(TreeNode *root)
{
	int re = subTreeHeight(root);
	cout << re << endl;
	return re >= 0;

}

int subTreeHeight(TreeNode *root)
{
	if (root == nullptr) return 0;
	if (root->left == nullptr && root->right == nullptr) return 0;
	
	int left = subTreeHeight(root->left), right = subTreeHeight(root->right);
	if (left < 0 || right < 0 || abs(left - right) > 1) return -1; // ºÙ÷¶
	return 1 + max(left, right);
}