#include <iostream>

using namespace std;

int insertPosition(int A[], int n, int target);

template<typename ForwardIterator, typename T>
ForwardIterator lower_bound2(ForwardIterator first, ForwardIterator last, T value);

int main()
{
	int A[] = { 1, 3, 5, 6,8,10 };
	int re = insertPosition(A, sizeof(A) / sizeof(A[0]), 7);
	cout << re << endl;
	return 0;
}

int insertPosition(int A[], int n, int target)
{
	return lower_bound2(A, A + n, target) - A;
}

template<typename ForwardIterator, typename T>
ForwardIterator lower_bound2(ForwardIterator first, ForwardIterator last, T value)
{
	while (first != last)
	{
		auto mid = next(first, distance(first, last) / 2);
		if (value > *mid) first = ++mid;
		else last = mid;
	}
	return first;
}