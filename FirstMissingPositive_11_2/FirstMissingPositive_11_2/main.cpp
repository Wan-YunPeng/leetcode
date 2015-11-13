#include <iostream>
#include <vector>

using namespace std;

int firstMissingPositive(int A[], int n);
static void bucket_sort(int A[], int n);

int main()
{
	int A[5] = { 3, 5, 0, -1, 4 };
	int re = firstMissingPositive(A, sizeof(A) / sizeof(A[0]));
	for (auto i : A)
		cout << i << " ";
	cout << endl;
	cout << re << endl;
	return 0;
}

int firstMissingPositive(int A[], int n)
{
	bucket_sort(A, n);
	for (int i = 0; i < n; ++i)
	{
		if (A[i] != i + 1)
			return i + 1;
	}
	return n + 1;
}


static void bucket_sort(int A[], int n)
{
	for (int i = 0; i < n; ++i)
	{
		while (A[i] != i + 1)
		{
			if (A[i] <= 0 || A[i] > n || A[i] == A[A[i] - 1])
				break;
			swap(A[i], A[A[i] - 1]);
		}
	}
}