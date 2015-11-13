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
int max_sum = INT_MIN;
void maxPathSum(TreeNode *root);
int dsf(TreeNode *root);

int main()
{
	/*TreeNode root(5);
	root.left = &TreeNode(4); root.right = &TreeNode(8);
	root.left->left = &TreeNode(11); root.right->left = &TreeNode(13); root.right->right = &TreeNode(4);
	root.left->left->left = &TreeNode(7);  root.left->left->right = &TreeNode(2);
	root.right->right->left = &TreeNode(5); root.right->right->right = &TreeNode(1);*/
	TreeNode root(1);
	root.left = &TreeNode(2);
	root.right = &TreeNode(3);
	maxPathSum(&root);
	cout << max_sum << endl;
	return 0;
}

void maxPathSum(TreeNode *root)
{
	if (root == nullptr) return;
	dsf(root);
}

int dsf(TreeNode *root)
{
	if (root == nullptr) return 0;
	int l = dsf(root->left);
	int r = dsf(root->right);
	int sum = root->val;
	if (l > 0) sum += l;
	if (r > 0) sum += r;
	max_sum = max(max_sum, sum);
	return max(r, l) > 0 ? max(r, l) + root->val : root->val;
}