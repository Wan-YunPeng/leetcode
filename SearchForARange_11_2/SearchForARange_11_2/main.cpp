#include <iostream>
#include <algorithm>
#include <vector>
//#include <functional>
using namespace std;

vector<int> searchRange(int A[], int n, int target);

int main()
{
	int A[] = { 5, 6, 7, 7, 8, 8, 9 };
	vector<int> re = searchRange(A, sizeof(A) / sizeof(A[0]), 8);
	for (auto i : re)
		cout << i << " ";
	cout << endl;
	return 0;
}

vector<int> searchRange(int A[], int n, int target)
{
	auto l = distance(A, lower_bound(A, A + n, target));
	auto u = distance(A, prev(upper_bound(A, A + n, target)));
	if (A[l] != target)
		return{ -1, -1 };
	else
		return{ l, u };
}