#include <iostream>
#include <algorithm>

using namespace std;

int solution1(int A[],int elem, int n);
int solution2(int A[],int elem, int n);

int main()
{
	int A[] = { 1, 2, 2, 3, 2, 1, 4, 2 };
	int B[] = { 1, 2, 2, 3, 2, 1, 4, 2 };
	int elem = 2;
	int n = sizeof(A) / sizeof(A[0]);
	int re1 = solution1(A, elem, n);
	int re2 = solution2(B, elem, n);
	cout << re1 << endl;
	cout << re2 << endl;
	for (int i = 0; i < n; ++i)
		cout << B[i] << " ";
	cout << endl;
	return 0;
}
// ����������Ϊ�������ݺ󣬱������Ὣ����Ϊָ�룬��sizeof(A) / sizeof(A[0])����1
int solution1(int A[], int elem, int n)
{
	int index = 0;

	for (int i = 0; i <n; ++i)
	{
		if (A[i] != elem){
			A[index++] = A[i];
		}
	}
	for (int i = 0; i < n; ++i)
		cout << A[i] << "  ";
	cout << endl;
	return index;
}


int solution2(int A[], int elem, int n)
{
	return distance(A, remove(A, A + n, elem));
}