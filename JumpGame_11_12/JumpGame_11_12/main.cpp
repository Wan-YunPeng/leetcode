#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool jump(int A[], int n);
bool jump2(int A[], int n);

int main()
{
	int A[] = { 4, 3, 2, 1, 0, 3 };
	bool re = jump2(A, sizeof(A) / sizeof(A[0]));
	cout << re << endl;
	return 0;
}

bool jump(int A[], int n)
{
	vector<int> f(n, 0);
	// f[0] = A[0] - 1;
	for (int i = 1; i < n; ++i)
	{
		f[i] = max(f[i - 1], A[i - 1]) - 1;
		if (f[i] < 0) return false;
	}
	return f.back() >= 0;
}

bool jump2(int A[], int n)
{
	int reach = 1; // 当前所能到达的最远元素
	for (int i = 0; i < reach && reach < n; ++i)
		reach = (reach, i + 1 + A[i]);
	return reach >= n;
}