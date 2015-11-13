#include <iostream>
#include <queue>

using namespace std;

struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) :val(x), left(nullptr), right(nullptr){};
};

bool isSymmetric(TreeNode *p, TreeNode *q);

bool isSymmetric2(TreeNode *p, TreeNode *q);

int main()
{
	TreeNode p(1);
	p.left = &TreeNode(2);
	p.right = &TreeNode(3);
	p.right->left = &TreeNode(4);

	TreeNode q(1);
	q.left = &TreeNode(2);
	q.right = &TreeNode(3);
	q.right->left = &TreeNode(4);

	bool re = isSymmetric2(&p, &q);
	cout << re << endl;
	return 0;
}

bool isSymmetric(TreeNode *p, TreeNode *q)
{
	if (!p && !q) return true;
	if (!p || !q) return false;
	return p->val == q->val && 
		isSymmetric(p->left, q->left) 
		&& isSymmetric(p->right, q->right);
}

bool isSymmetric2(TreeNode *p, TreeNode *q)
{
	if (!p && !q) return true;
	if (!p || !q) return false;
	
	queue<TreeNode *> cur, next;
	TreeNode *p1 , *q1;
	cur.push(p); cur.push(q);
	while (!cur.empty())
	{
		while (!cur.empty())
		{
			p1 = cur.front(); cur.pop();
			q1 = cur.front(); cur.pop();

			if (!p1 && !q1) continue;
			if (!p1 && !q1) return false;
			if (p1->val != q1->val)
				return false;
			next.push(p1->left); next.push(q1->left);
			next.push(p1->right); next.push(q1->right);
		}
		swap(cur, next);
	}
	return true;
}