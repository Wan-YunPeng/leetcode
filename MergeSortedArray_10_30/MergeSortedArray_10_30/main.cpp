#include <iostream>

using namespace std;

void merge(int A[], int m, int B[], int n);

int main()
{
	int A[15] = { 1, 2, 4, 5 };
	int B[5] = { 3, 6, 7 };
	merge(A, 4, B, 3);
	for (int i = 0; i < 15; ++i)
		cout << A[i] << " ";
	cout << endl;
	return 0;
}

void merge(int A[], int m, int B[], int n)// m >> n
{
	int ia = m - 1, ib = n - 1, icur = m + n - 1;
	while (ia >= 0 && ib >= 0)
	{
		A[icur--] = A[ia] >= B[ib] ? A[ia--] : B[ib--];
	}
	while (ib >= 0)
	{
		A[icur--] = B[ib--];
	}
}