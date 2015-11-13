#include <iostream>
using namespace std;

struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) :val(x), left(nullptr), right(nullptr){};
};

void recoverTree(TreeNode *root);
void detecte(pair<TreeNode*, TreeNode*> &broken, TreeNode *prev, TreeNode *cur);

int main()
{
	/*TreeNode root(1);
	root.left = &TreeNode(2);
	root.right = &TreeNode(4);
	root.right->left = &TreeNode(3);
	root.right->right = &TreeNode(5);*/

	TreeNode root(5);
	root.left = &TreeNode(1);
	root.right = &TreeNode(4);
	root.right->left = &TreeNode(3);
	root.right->right = &TreeNode(2);
	
	recoverTree(&root);
	cout << root.left->val << " " << root.val << " " <<
		root.right->left->val << " " << root.right->val << " "
		<< root.right->right->val << endl;
	return 0;
}

void recoverTree(TreeNode *root)
{
	if (root == nullptr) return;
	TreeNode *prev, *cur;
	prev = nullptr;
	cur = root;
	pair<TreeNode *, TreeNode *> broken;
	broken.first = nullptr; broken.second = nullptr;
	while (cur != nullptr)
	{
		if (cur->left == nullptr)
		{
			detecte(broken, prev, cur);
			cout << cur->val << " ";
			prev = cur;
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
				detecte(broken, prev, cur);
				cout << cur->val << " ";
				node->right = nullptr;
				prev = cur;
				cur = cur->right;
			}
		}
	}
	cout << endl;
	if (broken.first != nullptr && broken.second != nullptr)
		swap(broken.first->val, broken.second->val);
	else
		cout << "haha" << endl;
}

void detecte(pair<TreeNode*, TreeNode*> &broken, TreeNode *prev, TreeNode *cur)
{
	if (prev != nullptr && (prev->val > cur->val))
	{
		if (broken.first == nullptr)
			broken.first = prev;
		// 不能用else， 例如{0，1}会导致swap时broken的second为nullptr,因为{0，1}first和second同时被找出
		broken.second = cur;
	}
}