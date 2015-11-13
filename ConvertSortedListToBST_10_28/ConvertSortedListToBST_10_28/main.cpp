#include <iostream>
using namespace std;

struct ListNode
{
	int val;
	ListNode *next;
};

struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) :val(x), left(nullptr), right(nullptr){};
};

TreeNode* sortedToBST(ListNode *head);
TreeNode* sortedToBST(ListNode *list, int start, int end);

int main()
{
	return 0;
}

TreeNode* sortedToBST(ListNode *head)
{
	int len = 0;
	ListNode *p = head;
	while (p)
	{
		len++;
		p = p->next;
	}
	return sortedToBST(head, 0, len - 1);
}

TreeNode* sortedToBST(ListNode *list, int start, int end)
{
	if (start > end) return nullptr;

	int mid = start + (end - start) / 2;
	TreeNode *leftChild = sortedToBST(list, start, mid - 1);
	TreeNode *parent = new TreeNode(list->val);
	parent->left = leftChild;
	list = list->next;
	parent->right = sortedToBST(list, mid + 1, end);
	return parent;
}