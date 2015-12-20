#include <iostream>
#include <algorithm>

using namespace std;

int maxSubarray(int A[], int n);

int main()
{
	int A[] = { -2, 1, -3, 4, -1, 2, 1, -5, 4 };
	cout << maxSubarray(A, sizeof(A) / sizeof(A[0])) << endl;
	return 0;
}

int maxSubarray(int A[], int n)
{
	int re = INT_MIN, f = A[0];
	for (int i = 1; i < n; ++i)
	{
		f = max(f + A[i], A[i]);
		re = max(re, f);
	}
	return re;
}