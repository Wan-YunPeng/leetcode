#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) :val(x), left(nullptr), right(nullptr){};
};

vector<vector<int>> zigZagTraversal(TreeNode *root);
void traversal(TreeNode *root, int level, vector<vector<int>> &re, bool left_to_right);
vector<vector<int>> zigZagTraversal2(TreeNode *root);

int main()
{
	TreeNode root(3);
	root.left = &TreeNode(9);
	root.right = &TreeNode(20);
	root.right->left = &TreeNode(15);
	root.right->right = &TreeNode(7);
	vector<vector<int>> re = zigZagTraversal2(&root);
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

vector<vector<int>> zigZagTraversal(TreeNode *root)
{
	vector<vector<int>> result;
	traversal(root, 1, result, true);
	return result;
}

void traversal(TreeNode *root, int level, vector<vector<int>> &re,bool left_to_right)
{
	if (!root) return;

	if (level > re.size())
		re.push_back(vector<int>());
	if (left_to_right)
		re[level - 1].push_back(root->val);
	else
		re[level - 1].insert(re[level - 1].begin(), root->val);
	traversal(root->left, level + 1, re, !left_to_right);
	traversal(root->right, level + 1, re, !left_to_right);
}

vector<vector<int>> zigZagTraversal2(TreeNode *root)
{
	vector<vector<int>> re;
	queue<TreeNode *> cur,next;

	bool left_to_right = true;
	cur.push(root);
	while (!cur.empty())
	{
		vector<int> tmp;
		while (!cur.empty())
		{
			TreeNode *node = cur.front();
			cur.pop();
			if (left_to_right % 2 == 1)
				tmp.push_back(node->val);
			else
				tmp.insert(tmp.begin(), node->val);
			if (node->left) next.push(node->left);
			if (node->right) next.push(node->right);
		}
		left_to_right = !left_to_right;
		re.push_back(tmp);
		swap(cur, next);
	}
	return re;
}