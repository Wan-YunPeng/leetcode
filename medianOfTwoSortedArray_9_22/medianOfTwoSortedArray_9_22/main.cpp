#include <iostream>
#include <algorithm>
using namespace std;

int solution1(int A[], int B[], int m, int n);
int findMedian(int A[], int B[], int m, int n, int k);

int main()
{
	int A[] = { 8, 9, 10, 11, 12, 13, 14 };
	int B[] = { 11, 12, 13, 14,15 };
	int lenA = sizeof(A) / sizeof(A[0]);
	int lenB = sizeof(B) / sizeof(B[0]);
	int result = solution1(A, B, lenA, lenB);
	cout << result << endl;
	return 0;
}

int solution1(int A[], int B[], int m, int n)
{
	int total = m + n;
	// �ж�totalΪ��������ż��
	if (total & 0x1)
		return findMedian(A, B, m, n, total / 2 + 1);
	else
		return (findMedian(A, B, m, n, total / 2 + 1) +
		findMedian(A, B, m, n, total / 2)) / 2;

}

int findMedian(int A[], int B[], int m, int n, int k)
{
	// ��A��ʾ����Ԫ�ظ�����С���Ǹ�����
	if (m > n) findMedian(B, A, n, m, k);
	if (m == 0) return B[k - 1];
	if (k == 1) return min(A[0], B[0]);

	if (A[m - 1] < B[0] && m < k) return B[k - m - 1];

	// �ֳ���������,iaָ��A��Ҫ�Ƚϵ�Ԫ�أ����ܴ����䳤�ȣ�ibͬ��
	int ia = min(k / 2, m), ib = k - ia;
	// m < k/2 ���Ƚ�A[m]��B[k-ia]
	if (A[ia - 1] > B[ib - 1])
		return findMedian(A, B + ib, m, n - ib, k - ib);
	else if (A[ia - 1] < B[ib - 1])
		return findMedian(A + ia, B, m - ia, n, k - ia);
	else{
		cout << "haha" << A[ia - 1] << endl;
		return A[ia - 1];
	}
}