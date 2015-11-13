#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int solution1(int A[], int n);
int solution2(int A[], int n);
template<typename InIt, typename OutIt>
OutIt removeDuplicates(InIt first, InIt last, OutIt output);
int solution3(int A[], int n);
int soluting3str(string B, int n);

int main()
{
	int A[] = { 1, 2, 2, 3, 4, 4, 4 };
	int len = (int)(sizeof(A) / sizeof(A[0]));
	//int newlen = solution1(A, len);
	//int newlen = solution2(A, len);
	string B = "aabbddeeff";
	int newlen = solution3(A, len);
	cout << newlen << endl;
	for (int i = 0; i < (int)(sizeof(A) / sizeof(A[0])); ++i)
		cout << A[i] << endl;
	string str = "aabbccdd";
	string::iterator a = unique(str.begin(), str.end());
	cout << str << endl;

	/*int i = soluting3str(B, B.length());
	cout << i << B <<endl;*/
	return 0;
}

int solution1(int A[], int n)
{
	if (n == 0) return 0;
	int index = 0;
	for (int i = 1; i < n; ++i)
	{
		if (A[index] != A[i])
			A[++index] = A[i];
	}
	return index + 1;
}

int solution2(int A[], int n)
{
	return distance(A, unique(A, A + n));
}

int solution3(int A[], int n)
{
	return removeDuplicates(A, A + n, A) - A;
}

int solution3str(string A, int n)
{
	return removeDuplicates(&A, &A + n, &A) - &A;
}

template<typename InIt, typename OutIt>
OutIt removeDuplicates(InIt first, InIt last, OutIt output)
{
	while (first != last)
	{
		*output++ = *first;
		first = upper_bound(first, last, *first);
	}
	return output;
}