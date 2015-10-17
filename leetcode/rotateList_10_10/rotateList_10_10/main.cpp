#include <iostream>

using namespace std;

struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x) :val(x), next(nullptr){}
};

ListNode *rotateList(ListNode *head, int k);

int main()
{
	ListNode *l = new ListNode(-1);
	ListNode *tmp = l;

	for (int i = 0; i < 5; ++i)
	{
		int x;
		cin >> x;
		tmp->next = new ListNode(x);
		tmp = tmp->next;
	}
	l = rotateList(l->next,2);
	while (l)
	{
		cout << l->val << " ";
		l = l->next;
	}


	delete l;
	return 0;
}

ListNode *rotateList(ListNode *head, int k)
{
	if (head == nullptr || 0 == k) return head;
	
	int length = 1;
	ListNode *p = head;
	while (p->next)
	{
		++length;
		p = p->next;
	}

	// Ê×Î²ÏàÁ¬
	p->next = head;

	int step = length -  k % length;
	int i = 0;
	p = head;
	while (i < (step - 1))
	{
		p = p->next;
		++i;
	}
	head = p->next;
	p->next = nullptr;
	return head;
}