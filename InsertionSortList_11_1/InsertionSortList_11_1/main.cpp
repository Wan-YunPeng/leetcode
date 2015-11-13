#include <iostream>

using namespace std;

struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) :val(x), next(nullptr){};
};

ListNode* insertSort(ListNode *head);
ListNode* findInsertPos(ListNode *head, ListNode *cur);

int main()
{
	ListNode p(3); p.next = &ListNode(2); p.next->next = &ListNode(5);
	ListNode *re = insertSort(&p);
	while (re)
	{
		cout << re->val << " ";
		re = re->next;
	}
	return 0;
}

ListNode* insertSort(ListNode *head)
{
	if (head == nullptr) return nullptr;
	ListNode dumpy(INT_MIN);
	// dumpy.next = head;
	for (ListNode *cur = head; cur != nullptr;)
	{
		auto prev = findInsertPos(&dumpy, cur);
		ListNode *tmp = cur->next;
		cur->next = prev->next;
		prev->next = cur;
		cur = tmp;
	}
	return dumpy.next;
}

ListNode* findInsertPos(ListNode *head, ListNode *cur)
{
	ListNode *prev = nullptr, *p = head;
	for (; p != nullptr && p->val <= cur->val; prev = p, p = p->next)
		;
	return prev;
}