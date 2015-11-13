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

vector<TreeNode *> uniqueTrees(int n);
vector<TreeNode *> generator(int start, int end);
// morris÷––Ú ‰≥ˆ
void inorder(TreeNode *root);

int main()
{
	vector<TreeNode *> re = uniqueTrees(3);
	for (auto i : re)
	{
		inorder(i);
		cout << endl;
	}
	return 0;
}

vector<TreeNode *> uniqueTrees(int n)
{
	if (n == 0) return{ nullptr };
	if (n == 1) return{ &TreeNode(1) };
	return generator(1, n);
}

vector<TreeNode *> generator(int start, int end)
{
	vector<TreeNode *> subTree;
	if (start > end)
	{
		subTree.push_back(nullptr);
		return subTree;
	}
	for (int k = start; k <= end; ++k)
	{
		vector<TreeNode *> leftSub = generator(start, k - 1);
		vector<TreeNode *> rightSub = generator(k + 1, end);
		for (auto i : leftSub)
		{
			for (auto j : rightSub)
			{
				TreeNode *node = new TreeNode(k);
				node->left = i;
				node->right = j;
				subTree.push_back(node);
			}
		}
	}
	return subTree;
}

void inorder(TreeNode *root)
{
	TreeNode *cur, *prev;
	cur = root;

	while (cur != nullptr)
	{
		if (cur->left == nullptr)
		{
			cout << cur->val << " ";
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
				cout << cur->val << " ";
				prev = cur;
				cur = cur->right;
			}
		}
	}
}