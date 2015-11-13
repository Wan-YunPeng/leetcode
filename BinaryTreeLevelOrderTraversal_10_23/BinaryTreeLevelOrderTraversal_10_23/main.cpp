#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) :val(x), left(nullptr), right(nullptr){};
};

vector<vector<int>> levelOrder(TreeNode *root);

vector<vector<int>> levelOrder2(TreeNode *root);
void traverse(TreeNode *root, size_t level, vector<vector<int>> &result);

int main()
{
	TreeNode root(3);
	root.left = &(TreeNode(9));
	root.right = &(TreeNode(20));
	root.right->left = &(TreeNode(15));
	root.right->right = &(TreeNode(7));
	vector<vector<int>> re = levelOrder2(&root);
	for (auto vec : re)
	{
		for (auto i : vec)
		{
			cout << i << " ";
		}
		cout << endl;
	}
	return 0;
}

vector<vector<int>> levelOrder(TreeNode *root)
{
	if (root == nullptr) return{};
	queue<TreeNode *> cur, next;
	vector<vector<int>> re;

	cur.push(root);
	while (!cur.empty())
	{
		vector<int> tmp;
		while (!cur.empty())
		{
			TreeNode *q = cur.front();
			cur.pop();
			tmp.push_back(q->val);
			if (q->left != nullptr) next.push(q->left);
			if (q->right != nullptr) next.push(q->right);
		}
		re.push_back(tmp);
		swap(cur, next);
	}
	return re;
}

vector<vector<int>> levelOrder2(TreeNode *root)
{
	vector<vector<int>> re;
	traverse(root, 1, re);
	return re;
}

void traverse(TreeNode *root, size_t level, vector<vector<int>> &result)
{
	if (root == nullptr) return;

	if (level > result.size())
		result.push_back(vector<int>());

	result[level - 1].push_back(root->val);
	traverse(root->left, level + 1, result);
	traverse(root->right, level + 1, result);
}