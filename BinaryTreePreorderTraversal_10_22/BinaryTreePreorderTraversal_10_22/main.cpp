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

vector<int> preorder(TreeNode *root);

// �ݹ���ÿ�����ɿռ��öȹ���
void rec_preorder(TreeNode *root);

vector<int> preorderReversal(TreeNode *root);


int main()
{
	TreeNode root(1);
	root.right = &TreeNode(2);
	root.right->left = &TreeNode(3);
	rec_preorder(&root);
	vector<int> re = preorder(&root);
	for (auto i : re)
		cout << i << " ";
	cout << endl;
	re = preorderReversal(&root);
	for (auto i : re)
		cout << i << " ";
	cout << endl;
	return 0;
}

vector<int> preorder(TreeNode *root)
{
	vector<int> re;
	stack<const TreeNode *> p;
	const TreeNode *tmp;
	p.push(root);
	while (!p.empty())
	{
		tmp = p.top();
		p.pop();
		re.push_back(tmp->val);
		if (tmp->left) p.push(tmp->left);
		if (tmp->right) p.push(tmp->right);
	}
	return re;
}

void rec_preorder(TreeNode *root)
{
	if (root == nullptr) return;
	else{
		cout << root->val << endl;
		rec_preorder(root->left);
		rec_preorder(root->right);
	}
}

vector<int> preorderReversal(TreeNode *root)
{
	vector<int> re;
	TreeNode *cur;

	cur = root;
	while (cur != nullptr)
	{
		if (cur->left == nullptr)
		{
			re.push_back(cur->val);
			//prev = cur; // *cur�ոձ����ʹ�
			cur = cur->right;
		}
		else{
			// ����������----����cur��ǰ��
			TreeNode *p = cur->left;
			while (p->right != nullptr && p->right != cur) // ���������Ҳ���֮ǰ�����ʵĽڵ�
				p = p->right;

			if (p->right == nullptr) // û������������������    û��ǰ���ڵ㣬����������Һ���Ϊ��һ���ʽڵ�
			{
				re.push_back(cur->val);
				p->right = cur;
				//prev = cur;
				cur = cur->left;
			}
			else{ // p->right = cur;
				p->right = nullptr;
				cur = cur->right;
			}
		}
	}
	return re;
}