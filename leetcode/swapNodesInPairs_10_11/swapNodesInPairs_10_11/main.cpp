#include <iostream>

using namespace std;

struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x) :val(x), next(nullptr){}
};

ListNode *swapNodes(ListNode *head);

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
	head = swapNodes(head->next);
	tmp = head;
	while (tmp)
	{
		cout << tmp->val << " ";
		tmp = tmp->next;
	}
	delete head;
	return 0;
}

ListNode *swapNodes(ListNode *head)
{
	if (!head || !head->next) return head;
	ListNode dumpy(-1);
	dumpy.next = head->next;

	ListNode *p = head, *q = p->next;
	ListNode *tmp;
	while (q)
	{
		
		tmp = p;
		p->next = q->next;
		q->next = p;
		p = p->next;
		if (p){
			q = p->next;
		}
		else{
			q = nullptr;
		}
		if (q != nullptr)
			tmp->next = q;		
		
	}

	return dumpy.next;
}