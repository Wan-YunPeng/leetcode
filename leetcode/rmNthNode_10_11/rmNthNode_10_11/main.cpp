#include <iostream>

using namespace std;

struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x) :val(x), next(nullptr){}
};

ListNode *rmNthNode(ListNode *head, int n);

int main()
{
	ListNode *head = new ListNode(-1);
	ListNode *tmp = head;
	for (int i = 0; i < 5; ++i)
	{
		int x;
		cin >> x;
		tmp->next = new ListNode(x);
		tmp = tmp->next;
	}
	head = rmNthNode(head->next, 1);
	tmp = head;
	while (tmp)
	{
		cout << tmp->val << " ";
		tmp = tmp->next;
	}
	delete head;
	return 0;
}

ListNode *rmNthNode(ListNode *head, int n)
{
	ListNode *p = head, *q = head;

	for (int i = 0; i < n && q; ++i)
	{
		q = q->next;
	}

	while (q->next)
	{
		p = p->next;
		q = q->next;
	}
	q = p->next;
	p->next = p->next->next;
	delete q;
	return head;
}