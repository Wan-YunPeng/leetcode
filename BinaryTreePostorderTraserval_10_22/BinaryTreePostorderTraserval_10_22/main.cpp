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

vector<int> postReversal(TreeNode *root);

vector<int> postOrder(TreeNode *root);


int main()
{
	TreeNode root(1);
	root.left = &TreeNode(4);
	root.right = &TreeNode(2);
	root.right->left = &TreeNode(3);
	vector<int> re = postOrder(&root);
	for (auto i : re)
		cout << i << " ";
	cout << endl;
	return 0;
}

vector<int> postReversal(TreeNode *root)
{
	return{};
}

vector<int> postOrder(TreeNode *root)
{
	vector<int> re;
	stack<TreeNode *> stk;
	TreeNode *p, *q;

	p = root;
	do{
		while (p != nullptr)
		{
			stk.push(p);
			p = p->left;
		}

		q = nullptr;
		while (!stk.empty()){
			p = stk.top();
			stk.pop();
			if (p->right == q)
			{
				re.push_back(p->val);
				q = p; // 保存刚刚访问过的节点
			}
			else{
				stk.push(p);
				p = p->right;
				break;
			}
		}

	} while (!stk.empty());
	return re;
}