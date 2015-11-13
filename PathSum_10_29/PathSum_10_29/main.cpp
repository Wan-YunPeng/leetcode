#include <iostream>
using namespace std;

struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) :val(x), left(nullptr), right(nullptr){};
};

bool pathSum(TreeNode *root, int sum);

int main()
{
	TreeNode root(5);
	root.left = &TreeNode(4); root.right = &TreeNode(8);
	root.left->left = &TreeNode(11); root.right->left = &TreeNode(13); root.right->right = &TreeNode(4);
	root.left->left->right = &TreeNode(2);
	bool re = pathSum(&root, 22);
	cout << re << endl;
	return 0;
}

bool pathSum(TreeNode *root, int sum)
{
	if (root == nullptr) return false;
	bool left = false, right = false;
	if (root->val == sum && root->left == nullptr && root->right == nullptr)
		return true;
	else
	{
		left = pathSum(root->left, sum - root->val);
		right = pathSum(root->right, sum - root->val);
	}
	return left || right;
}