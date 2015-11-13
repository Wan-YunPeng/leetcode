#include <iostream>

using namespace std;

int solution1(int A[], int n, int target);

// deal with duplicates
int solution2(int A[], int n, int target);

int main()
{
	int A[] = { 4, 5, 6, 7, 0, 1, 2 };
	rsize_t len = sizeof(A) / sizeof(A[0]);
	int target = 4;
	int index = solution1(A, len, target);
	cout << index << endl;
	int B[] = { 4, 4, 4, 5, 5, 6, 7, 0, 0, 0, 1, 1, 1, 2, 3 };
	target = 7;
	size_t lenB = sizeof(B) / sizeof(B[0]);
	index = solution2(B, lenB, target);
	cout << index << endl;
	return 0;
}

int solution1(int A[], int n, int target)
{
	int first = 0, last = n;
	while (first != last)
	{
		const int mid = (first + last) / 2;
		if (A[mid] == target) return mid;
		if (A[first] < A[mid])
		{
			if (A[first] <= target && A[mid] > target)
				last = mid;
			else
				first = mid + 1;
		}
		else
		{
			if (A[last - 1] >= target && A[mid] < target)
				first = mid + 1;
			else
				last = mid;
		}
	}
	return -1;
}

int solution2(int B[], int n, int target)
{
	int first = 0, last = n;
	while (first != last)
	{
		const int mid = (first + last) / 2;
		if (B[mid] == target) return mid;
		if (B[mid] > B[first])
		{
			if (B[first] <= target && B[mid] > target)
				last = mid;
			else
				first = mid + 1;
		}
		else if (B[mid] < B[first])
		{
			if (B[mid] < target && target <= B[last - 1])
				first = mid + 1;
			else
				last = mid;
		}
		else
			++first;

	}
	return -1;
}