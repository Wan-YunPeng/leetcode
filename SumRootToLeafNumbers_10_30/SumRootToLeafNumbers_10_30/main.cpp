#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

struct TreeNode
{
	int val;
	TreeNode *left, *right;
	TreeNode(int x) :val(x), left(nullptr), right(nullptr){};
};

void sumRoot2Leaf(TreeNode *root, vector<int> &re, int sum);

int main()
{
	TreeNode root(1);
	root.left = &TreeNode(2);
	root.right = &TreeNode(3);
	root.left->left = &TreeNode(4);
	vector<int> re;
	sumRoot2Leaf(&root, re, 0);
	int i = accumulate(re.begin(), re.end(), 0);
	cout << i << endl;
	return 0;
}

void sumRoot2Leaf(TreeNode *root, vector<int> &re, int sum)
{
	if (root == nullptr) return;
	if (root->left == nullptr && root->right == nullptr)
	{
		re.push_back(root->val + sum * 10);
		return;
	}
	sum = sum * 10 + root->val;
	sumRoot2Leaf(root->left, re, sum);
	sumRoot2Leaf(root->right, re, sum);
}