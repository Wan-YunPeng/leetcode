#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

struct TreeLinkNode
{
	int val;
	TreeLinkNode *left, *right, *next;
	TreeLinkNode(int x) :val(x), left(nullptr), right(nullptr), next(nullptr){};
};

void connect(TreeLinkNode *root);
void connect2(TreeLinkNode *root,TreeLinkNode *sibling);

int main()
{
	TreeLinkNode root(1);
	root.left = &TreeLinkNode(2);
	root.right = &TreeLinkNode(3);
	root.left->left = &TreeLinkNode(4); root.left->right = &TreeLinkNode(5);
	root.right->left = &TreeLinkNode(6); root.right->right = &TreeLinkNode(7);
	connect(&root);
	TreeLinkNode *p = &root, *q = &root;
	while (p)
	{
		q = p;
		while (q)
		{
			cout << q->val << " ";
			q = q->next;
		}
		p = p->left;
		cout << endl;
	}
	return 0;
}

void connect(TreeLinkNode *root)
{
	if (root == nullptr) return;
	queue<TreeLinkNode *> next;
	next.push(root);

	while (!next.empty())
	{
		queue<TreeLinkNode *> tmp;
		while (!next.empty())
		{
			TreeLinkNode *p = next.front(); next.pop();
			auto left = p->left ? p->left : nullptr;
			auto right = p->right ? p->right : nullptr;
			if (left != nullptr) tmp.push(left);
			if (right != nullptr) tmp.push(right);
			TreeLinkNode *q = nullptr;
			if (next.size())
				q = next.front();
			if (q)
				p->next = q;
		}
		swap(tmp, next);
	}
}

void connect(TreeLinkNode *root, TreeLinkNode *sibling)
{
	if (root == nullptr) return;
	else root->next = sibling;

	connect(root->left, root->right);
	if (sibling)
		connect(root->right, sibling->left);
	else
		connect(root->right, nullptr);
}