#include <iostream>

using namespace std;

struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x) :val(x), next(nullptr){}
};

void solution(ListNode *head);

int main()
{
	ListNode *l = new ListNode(-1);
	ListNode *tmp = l;
	for (int i = 0; i < 5; ++i)
	{
		int n;
		cin >> n;
		tmp->next = new ListNode(n);
		tmp = tmp->next;
	}

	solution(l);
	l = l->next;
	while (l)
	{
		cout << l->val << " ";
		l = l->next;
	}

	delete l;
	return 0;
}

void solution(ListNode *head)
{
	ListNode *prev = nullptr, *next = nullptr;
	if (head->next)
		prev = head->next;
	if (prev->next)
		next = prev->next;
	if (prev == nullptr || next == nullptr)
		exit(0);

	while (next)
	{
		if (prev->val == next->val)
		{
			next = next->next;
			delete prev->next;
			prev->next = next;
		}
		else
		{
			prev = next;
			next = next->next;
		}
	}
}