#include <iostream>

using namespace std;

struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x) :val(x), next(nullptr){}
};

// µÝ¹é°æ
ListNode *removeDuplicates(ListNode *head);

ListNode *removeDuplicates2(ListNode *head);


int main()
{
	ListNode *l = new ListNode(-1);
	ListNode *tmp = l;
	for (int i = 0; i < 7; ++i)
	{
		int x;
		cin >> x;
		tmp->next = new ListNode(x);
		tmp = tmp->next;
	}
	l = removeDuplicates2(l->next);
	while (l)
	{
		cout << l->val << " ";
		l = l->next;
	}

	return 0;
}

ListNode *removeDuplicates(ListNode *head)
{
	if (!head->next || !head) return head;

	ListNode *cur = head;

	if (head->val == head->next->val)
	{
		int x = head->val;
		while (cur->val == x && cur)
		{
			head = head->next;
			delete cur;
			cur = head;
		}

		return removeDuplicates(head);
	}
	else
	{
		head->next = removeDuplicates(head->next);
		return head;
	}

}

ListNode *removeDuplicates2(ListNode *head)
{
	if (head == nullptr) return head;

	ListNode dumpy(INT_MIN);
	dumpy.next = head;

	ListNode *prev = &dumpy, *cur = prev->next;

	if (!cur->next) return head;


	while (cur)
	{
		bool duplicate = false;
		while (cur->next && cur->val == cur->next->val)
		{
			duplicate = true;
			ListNode *tmp = cur;
			cur = cur->next;
			delete tmp;
		}
		if (duplicate)
		{
			ListNode *tmp = cur;
			cur = cur->next;
			delete tmp;
			continue;
		}
		prev->next = cur;
		prev = prev->next;
		cur = cur->next;
	}
	prev->next = cur;
	return dumpy.next;
}