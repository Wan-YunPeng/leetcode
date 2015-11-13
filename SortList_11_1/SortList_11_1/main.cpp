#include <iostream>

using namespace std;

struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) :val(x), next(nullptr){};
};

ListNode *sortList(ListNode *head);
ListNode *merge(ListNode *p, ListNode *q);

int main()
{
	ListNode p(4); p.next = &ListNode(9); p.next->next = &ListNode(6); p.next->next->next = &ListNode(12);
	p.next->next->next->next = &ListNode(10); p.next->next->next->next->next = &ListNode(1);
	auto re = sortList(&p);
	while (re)
	{
		cout << re->val << " ";
		re = re->next;
	}
	return 0;
}

ListNode* sortList(ListNode *head)
{
	if (head == nullptr || head->next == nullptr) return head;
	ListNode *slow = head, *fast = slow;
	while (fast->next != nullptr && fast->next->next != nullptr)
	{
		slow = slow->next;
		fast = fast->next->next;
	}
	fast = slow;
	slow = slow->next;
	fast->next = nullptr;

	auto left = sortList(head);
	auto right = sortList(slow);
	return merge(left, right);
}

ListNode *merge(ListNode *p, ListNode *q)
{
	if (p == nullptr) return q;
	if (q == nullptr) return p;

	ListNode dumpy(-1);
	ListNode *re = &dumpy;
	while (p && q)
	{
		if (p->val <= q->val)
		{
			re->next = p;
			p = p->next;
		}
		else
		{
			re->next = q;
			q = q->next;
		}
		re = re->next;
	}
	re->next = p == nullptr ? q : p;
	return dumpy.next;
}