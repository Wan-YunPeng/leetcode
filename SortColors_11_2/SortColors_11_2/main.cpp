#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;

void sortColor(int A[], int n);
void sortColor2(int A[], int n);
void sortColor3(int A[], int n);

int main()
{
	int A[] = { 1, 2, 1, 2, 1, 1, 2, 1, 0, 2 };
	sortColor3(A, sizeof(A) / sizeof(A[0]));
	for (auto i : A)
		cout << i << " ";
	cout << endl;
	return 0;
}

void sortColor(int A[], int n)
{
	int counts[3] = { 0, 0, 0 };

	for (int i = 0; i < n; ++i)
		counts[A[i]]++;

	for (int i = 0, index = 0; i < 3; ++i)
	{
		for (int j = 0; j < counts[i]; ++j)
			A[index++] = i;
	}
}

void sortColor2(int A[], int n)
{
	int red = 0, blue = n - 1;

	for (int i = 0; i < blue + 1;)
	{
		if (A[i] == 0)
			swap(A[i++], A[red++]);
		else if (A[i] == 2)
			swap(A[i], A[blue--]);
		else
			i++;
	}
}

void sortColor3(int A[], int n)
{
	partition(partition(A,A+n,bind1st(equal_to<int>(), 0)),A + n, bind1st(equal_to<int>(), 1));
}