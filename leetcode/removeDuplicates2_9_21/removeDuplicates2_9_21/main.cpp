#include <iostream>
using namespace std;

int solution1(int A[], int n);
int solution2(int A[], int n);

int main()
{
	int A[] = { 1, 1, 1, 2, 2, 3 };
	int i = solution2(A, sizeof(A) / sizeof(A[0]));
	cout << i << endl;
	for (i = 0; i < sizeof(A) / sizeof(A[0]); ++i)
		cout << A[i] << endl;
	return 0;
}

int solution1(int A[], int n)
{
	if (n == 0) return 0;
	int index = 2;
	for (int i = 2; i < n; ++i)
	{
		if (A[index - 2] != A[i])
			A[index++] = A[i];
	}
	return index;
}

int solution2(int A[], int n)
{
	int index = 0;
	for (int i = 0; i < n; ++i)
	{
		if (i < n - 1 && i > 0 && A[i] == A[i + 1] && A[i] == A[i - 1])
			continue;
		A[index++] = A[i];
	}
	return index;
}