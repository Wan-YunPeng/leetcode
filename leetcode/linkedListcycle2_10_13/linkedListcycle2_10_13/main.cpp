#include <iostream>

using namespace std;

struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x) :val(x), next(nullptr){}
};

ListNode *detectCycle(ListNode *head);

int main()
{
	ListNode dumpy(-1);
	ListNode *head = &dumpy;
	ListNode tmp(1);
	head->next = &tmp;
	ListNode *cycleHead = &tmp;
	head = head->next;
	for (int i = 0; i < 5; ++i)
	{
		int x;
		cin >> x;
		head->next = new ListNode(x);
		head = head->next;
	}
	head->next = cycleHead;
	ListNode *re = detectCycle(dumpy.next);
	if (re)
		cout << "环头节点：" << re->val << endl;
	else
		cout << "无环" << endl;
	return 0;
}

ListNode *detectCycle(ListNode *head)
{
	ListNode *slow = head, *fast = head;

	while (fast && fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;

		if (slow == fast)
		{
			ListNode *slow2 = head;
			while (slow != slow2)
			{
				slow = slow->next;
				slow2 = slow2->next;
			}
			return slow2;
		}
		
	}
	return nullptr;
}