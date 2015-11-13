#include <iostream>
#include <vector>
using namespace std;

struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) :val(x), left(nullptr), right(nullptr){};
};

vector<vector<int>> pathSum(TreeNode *root, int sum);
void isPath(TreeNode *root, int sum, vector<int> &cur,vector<vector<int>> &re);

int main()
{
	TreeNode root(5);
	root.left = &TreeNode(4); root.right = &TreeNode(8);
	root.left->left = &TreeNode(11); root.right->left = &TreeNode(13); root.right->right = &TreeNode(4);
	root.left->left->left = &TreeNode(7);  root.left->left->right = &TreeNode(2);
	root.right->right->left = &TreeNode(5); root.right->right->right = &TreeNode(1);
	vector<vector<int>> re = pathSum(&root, 22);
	for (auto row : re)
	{
		for (auto i : row)
		{
			cout << i << " ";
		}
		cout << endl;
	}
	return 0;
}

vector<vector<int>> pathSum(TreeNode *root, int sum)
{
	vector<vector<int>> re;
	vector<int> cur;
	isPath(root, sum, cur, re);
	re.push_back(vector<int>());
	return re;
}

void isPath(TreeNode *root, int sum, vector<int> &cur, vector<vector<int>> &re)
{
	if (root == nullptr) return;
	cur.push_back(root->val);
	if (root->val == sum && root->left == nullptr && root->right == nullptr)
		re.push_back(cur);
	isPath(root->left, sum - root->val, cur, re);
	isPath(root->right, sum - root->val, cur, re);
	cur.pop_back();
}