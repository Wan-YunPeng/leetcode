#include <iostream>

using namespace std;

struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x) :val(x), next(nullptr){}
};
// 递归版
ListNode *solution(ListNode *head, int k);
// 迭代版
ListNode *solution2(ListNode *head, int k);
ListNode *reverse(ListNode *prev, ListNode *begin, ListNode *end);

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
	head = solution2(dumpy.next, 3);

	while (head)
	{
		cout << head->val << " ";
		head = head->next;
	}
	return 0;
}

ListNode *solution(ListNode *head, int k)
{
	if (head == nullptr || head->next == nullptr || k < 2) return head;

	ListNode *next_group = head;
	for (int i = 0; i < k; ++i)
	{
		if (next_group->next)
			next_group = next_group->next;
		else
			return head;
	}

	ListNode *new_next_group = solution(next_group, k);

	ListNode *cur = head, *prev = nullptr;

	while (cur != next_group)
	{
		ListNode *next = cur->next;
		cur->next = prev ? prev : new_next_group;
		prev = cur;
		cur = next;
	}
	return prev;
}

ListNode *solution2(ListNode *head, int k)
{
	if (head == nullptr || head->next == nullptr || k < 2) return head;

	ListNode dumpy(-1);
	dumpy.next = head;

	for (ListNode *prev = &dumpy, *end = head; end; end = prev->next) // 初始化的end为reverse的头节点
	{
		for (int i = 1; i < k; ++i)
			end = end->next;
		if (end == nullptr) break;
		prev = reverse(prev, prev->next, end);
	}
	return dumpy.next;
}
// prev是first前的一个元素，[begin,end]闭区间，保证三者都不为nullptr，返回reverse后的倒数第一个元素
ListNode *reverse(ListNode *prev, ListNode *begin, ListNode *end)
{
	ListNode *end_next = end->next;
	// 每次处理cur，直到cur为end_next
	for (ListNode *p = begin, *cur = p->next, *next = cur->next; cur != end_next; p = cur, cur = next, next = next ? next->next : nullptr)
		cur->next = p;
	begin->next = end_next;
	prev->next = end;
	return begin;
}