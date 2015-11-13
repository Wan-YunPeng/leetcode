#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int val) :val(val), next(nullptr){}
};

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2);

int main()
{
	ListNode *l1 = new ListNode(2);
	l1->next = new ListNode(4);
	l1->next->next = new ListNode(3);
	ListNode *l2 = new ListNode(5);
	l2->next = new ListNode(6);
	l2->next->next = new ListNode(4);
	ListNode *re = addTwoNumbers(l1, l2);
	for (; re != nullptr; re = re->next)
		cout << re->val << " ";
	cout << endl;
	delete l1, l2;
	return 0;
}

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
	ListNode re(-1);
	ListNode *prev = &re;
	int carry = 0;
	for (ListNode *pa = l1, *pb = l2; pa != nullptr || pb != nullptr; pa = pa == nullptr ? nullptr : pa->next, pb = pb == nullptr ? nullptr : pb->next)
	{
		const int ai = pa == nullptr ? 0 : pa->val;
		const int bi = pb == nullptr ? 0 : pb->val;
		const int val = (ai + bi + carry) % 10;
		carry = (ai + bi + carry) / 10;
		prev->next = new ListNode(val);
		prev = prev->next;
	}
	if (carry > 0)
		prev->next = new ListNode(carry);
	return re.next;
}