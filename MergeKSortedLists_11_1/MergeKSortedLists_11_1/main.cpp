#include <iostream>
#include <vector>

using namespace std;

struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) :val(x), next(nullptr){};
};

ListNode* mergeK(vector<ListNode *> list);
ListNode *mergeTwo(ListNode *p, ListNode *q);

int main()
{
	ListNode p(2); p.next = &ListNode(7); p.next->next = &ListNode(17);
	ListNode q(4); q.next = &ListNode(10);
	ListNode r(1); r.next = &ListNode(34);
	vector<ListNode *> test;
	test.push_back(&p);  test.push_back(&q); test.push_back(&r);
	ListNode *re = mergeK(test);
	while (re)
	{
		cout << re->val << " ";
		re = re->next;
	}
	return 0;
}

ListNode* mergeK(vector<ListNode *> list)
{
	if (list.empty()) return nullptr;
	if (1 == list.size()) return list[0];
	ListNode *re = list[0];
	for (int i = 1; i < list.size(); ++i)
		re = mergeTwo(re, list[i]);
	return re;
}

ListNode* mergeTwo(ListNode *p, ListNode *q)
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