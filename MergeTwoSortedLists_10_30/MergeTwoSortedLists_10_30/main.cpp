#include <iostream>

using namespace std;

struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x) :val(x), next(nullptr){};
};

ListNode* merge(ListNode *p, ListNode *q);

int main()
{
	ListNode p(4); p.next = &ListNode(8); p.next->next = &ListNode(10);
	ListNode q(2); q.next = &ListNode(7); q.next->next = &ListNode(13);
	ListNode *re = merge(&p, &q);
	while (re)
	{
		cout << re->val << " ";
		re = re->next;
	}
	cout << endl;
	return 0;
}

ListNode* merge(ListNode *p, ListNode *q)
{
	if (p == nullptr) return q;
	if (q == nullptr) return p;
	ListNode dumpy(-1);
	ListNode *re = &dumpy;
	while (q && p) // ºÏ²¢µ½p
	{
		if (p->val > q->val)
		{
			re->next = q;
			q = q->next;
		}
		else
		{
			re->next = p;
			p = p->next;
		}
		re = re->next;
	}
	re->next = p == nullptr ? q : p;
	return dumpy.next;
}