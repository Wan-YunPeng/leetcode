#include <iostream>
#include <stack>
#include <assert.h>
using namespace std;

struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) :val(x), left(nullptr), right(nullptr){};
};

bool isSameTree(TreeNode *p, TreeNode *q);
bool isSameTree2(TreeNode *p, TreeNode *q);
int main()
{
	int a = 2;
	//assert(a != 2);
	TreeNode q(1);
	q.left = &TreeNode(2);
	q.right = &TreeNode(3);
	TreeNode p(1);
	p.left = &TreeNode(2);
	p.right = &TreeNode(3);
	bool re = isSameTree2(&p, &q);
	cout << re << endl;
	return 0;
}

bool isSameTree(TreeNode *p, TreeNode *q)
{
	if (p == nullptr && q == nullptr) return true;
	if (p == nullptr || q == nullptr) return false;
	return p->val == q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}

bool isSameTree2(TreeNode *p, TreeNode *q)
{
	if (p == nullptr && q == nullptr) return true;
	if (p == nullptr || q == nullptr) return false;
	stack<TreeNode *> s;
	s.push(p); s.push(q);
	while (!s.empty())
	{
		TreeNode *tmpq = s.top(); s.pop();
		TreeNode *tmpp = s.top(); s.pop();
		
		if (!tmpp && !tmpq) continue;
		if (!tmpp || !tmpq) return false;
		if (tmpp->val != tmpq->val) return false;

		s.push(tmpp->left); s.push(tmpq->left);
		s.push(tmpp->right); s.push(tmpq->right);
	}
	return true;	
}