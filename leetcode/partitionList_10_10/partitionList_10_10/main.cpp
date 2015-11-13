#include <iostream>

using namespace std;

struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x) :val(x), next(nullptr){}
};

void partitionList(ListNode *l,const int n);

int main()
{
	ListNode *l = new ListNode(-1);
	ListNode *tmp = l;
	int x;
	for (int i = 1; i <= 6; ++i)
	{
		cin >> x;
		tmp->next = new ListNode(x);
		tmp = tmp->next;
	}
	partitionList(l, 3);
	l = l->next;
	while (l)
	{
		cout << l->val << " ";
		l = l->next;
	}
	return 0;
}

void partitionList(ListNode *l,const int n)
{
	ListNode left_dumpy(-1);
	ListNode right_dumpy(-1);

	auto pl = &left_dumpy;
	auto pr = &right_dumpy;

	for (ListNode *cur = l; cur != nullptr; cur = cur->next)
	{
		if (cur->val < n)
		{
			pl->next = cur;
			pl = pl->next;
		}
		else
		{
			pr->next = cur;
			pr = pr->next;
		}
	}
	
	pl->next = right_dumpy.next;
	pr->next = nullptr;
	l = left_dumpy.next;
}