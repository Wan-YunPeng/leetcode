#include <iostream>

using namespace std;

struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) :val(x), next(nullptr){}
};

ListNode *reorderList(ListNode *head);
ListNode *reverse(ListNode *head);

int main()
{
	ListNode dumpy(-1);
	ListNode *head = &dumpy;
	for (int i = 0; i < 5; ++i)
	{
		int x;
		cin >> x;
		head->next = new ListNode(x);
		head = head->next;
	}

	head = reorderList(dumpy.next);
	while (head)
	{
		cout << head->val << " ";
		head = head->next;
	}
	return 0;
}

ListNode *reorderList(ListNode *head)
{
	if (head == nullptr || head->next == nullptr) return head;

	ListNode *slow = head, *fast = head, *prev = nullptr;
	while (fast && fast->next)
	{
		prev = slow;
		slow = slow->next;
		fast = fast->next->next;
	}

	prev->next = nullptr;

	// 断开之后，slow指向后半段，prev指向前半段的末尾
	// 后半段reverse
	 slow = reverse(slow);

	 ListNode *cur = head;
	while (cur->next)
	{
		ListNode *tmp = cur->next;
		cur->next = slow;
		slow = slow->next;
		cur->next->next = tmp;
		cur = tmp;
	}
	cur->next = slow;
	return head;
}

ListNode *reverse(ListNode *head)
{
	if (head == nullptr || head->next == nullptr) return head;

	ListNode *prev = head;
	for (ListNode *cur = prev->next, *next = cur->next; cur; prev = cur, cur = next, next = next ? next->next : nullptr)
		cur->next = prev;
	head->next = nullptr;
	return prev;
		
}