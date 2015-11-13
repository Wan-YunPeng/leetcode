#include <iostream>
#include <stack>
using namespace std;

struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) :val(x), left(nullptr), right(nullptr){};
};

TreeNode* flatten(TreeNode *p);
TreeNode* flatten(TreeNode *root, TreeNode *tail);
void flatten3(TreeNode *root);

int main()
{
	TreeNode root(1);
	root.left = &TreeNode(2);
	root.left->left = &TreeNode(3);
	root.left->right = &TreeNode(4);
	root.right = &TreeNode(5);
	root.right->right = &TreeNode(6);
	flatten3(&root);
	TreeNode *re = &root;
	while (re)
	{
		cout << re->val << endl;
		re = re->right;
	}
	/*TreeNode *re = flatten(&root,nullptr);
	while (re)
	{
		cout << re->val << endl;
		re = re->right;
	}*/
	return 0;
}

TreeNode* flatten(TreeNode *p)
{
	if (p == nullptr) return nullptr;

	TreeNode *left = flatten(p->left);
	TreeNode *right = flatten(p->right);

	if (left != nullptr){

		TreeNode *left_down = left;

		while (left_down->right != nullptr)
		{
			left_down = left_down->right;
		}
		p->right = left;
		left_down->right = right;
	}
	return p;
}

TreeNode* flatten(TreeNode *root, TreeNode *tail)
{
	if (root == nullptr) return tail;
	root->right = flatten(root->left, flatten(root->right, tail));
	root->left = nullptr;
	return root;
}

void flatten3(TreeNode *root)
{
	if (root == nullptr) return;
	stack<TreeNode *> s;
	s.push(root);
	while (!s.empty())
	{
		auto p = s.top(); s.pop();
		
		if (p->right)
			s.push(p->right);
		if (p->left)
			s.push(p->left);
		p->left = nullptr;
		if (!s.empty())
			p->right = s.top();
	}
}