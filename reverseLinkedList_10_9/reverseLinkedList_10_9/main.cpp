#include <iostream>

using namespace std;

struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x) :val(x), next(nullptr){}
};

void reverseLinkedList(ListNode *l, int m, int n);

int main()
{
	ListNode *l = new ListNode(1);
	int i = 2, m = 2, n = 5;
	for (ListNode *next = l; i <= 5; ++i)
	{
		next->next = new ListNode(i);
		next = next->next;
	}
	for (ListNode *next = l; next != nullptr; next = next->next)
		cout << next->val << " ";
	cout << endl;
	reverseLinkedList(l, m, n);
	for (ListNode *next = l; next != nullptr; next = next->next)
		cout << next->val << " ";
	cout << endl;
	delete l;
	return 0;
}

void reverseLinkedList(ListNode *l, int m, int n)
{
	ListNode dummy(-1); // 头节点
	dummy.next = l;

	ListNode *prev = &dummy;
	for (int i = 1; i < m; ++i)
		prev = prev->next;
	ListNode *const head = prev; // 需要第m-1个位置作为head
	prev = prev->next; // 指向第m个元素
	ListNode *cur = prev->next;
	for (int i = m; i < n; ++i)
	{
		prev->next = cur->next;
		cur->next = head->next;
		head->next = cur;
		cur = prev->next;
	}
}