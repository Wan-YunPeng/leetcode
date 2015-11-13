#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) :val(x), left(nullptr), right(nullptr){};
};


vector<int> inorderRevesal(TreeNode *root);

int main()
{
	TreeNode root(1);
	root.left = &TreeNode(4);
	root.right = &TreeNode(2);
	root.right->left = &TreeNode(3);
	vector<int> re = inorderRevesal(&root);
	for (auto i : re)
		cout << i << " ";
	cout << endl;
	return 0;
}

vector<int> inorderRevesal(TreeNode *root)
{
	vector<int> re;
	TreeNode *cur;
	
	cur = root;
	while (cur != nullptr)
	{
		if (cur->left == nullptr)
		{
			re.push_back(cur->val);
			cur = cur->right;
		}
		else
		{
			TreeNode *node = cur->left;
			while (node->right != nullptr && node->right != cur)
				node = node->right;

			if (node->right == nullptr)
			{
				node->right = cur;
				cur = cur->left;
			}
			else
			{
				node->right = nullptr;
				re.push_back(cur->val);
				cur = cur->right;
			}
		}
	}
	return re;
}

