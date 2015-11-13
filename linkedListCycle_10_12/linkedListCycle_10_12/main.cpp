#include <iostream>

struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) :val(x), next(nullptr){}
};

bool hasCycle(ListNode *head);

int main()
{
	return 0;
}

bool hasCycle(ListNode *head)
{
	if (head == nullptr || head->next == nullptr) return false;

	// ��������ָ�룬һ���ܵÿ죬һ���ܵ���
	ListNode *fast = head->next, *slow = head;

	while (fast && fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast)
			return true;
	}
	return false;
}