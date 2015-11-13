#include <iostream>
#include <vector>
using namespace std;

int LIS(int A[], int n);
//int LIS(vector<int> num);
int main()
{
	int A[] = { 3, 5, 6, 2, 5, 4, 19, 5, 6, 7, 12};
	vector<int> num(A, A + sizeof(A) / sizeof(A[0]));
	int re = LIS(A, sizeof(A) / sizeof(A[0]));
	//int re = LIS(num);
	cout << re << endl;
	return 0;
}

int LIS(int A[], int n)
{
	vector<int> F(n, 1);
	for (int i = 1; i < n; ++i)
	{
		for (int j = 0; j < i; ++j)
		{
			if (A[i] > A[j] && F[j] + 1 > F[i])
				F[i] = F[j] + 1;
		}
	}
	int max = 1;
	for (auto i : F)
	{
		if (i > max)
			max = i;
	}
	return max;
}
/*
int LIS(vector<int> num)
{
	if (num.empty()) return 0;
	if (num.size() == 1) return 1;
	vector<int> F(num.size(), 0);
	int maxLen = 1;
	//F[1] = 1;
	//if (num[1] > num[0]) // 不论num[1]是否大于num[0]，F[1]都为1；唯一的区别在于大于时，最大长度加1.
	//	maxLen++;
	for (int i = 1; i < num.size(); ++i)  // 前i项中，LIS最后一个元素下标，使得A[F[i]]的序列最小
	{
		if (num[i] > num[F[i - 1]])
		{
			maxLen++;
			F[i] = i;
		}
		else if (i - 2 > 0 && num[i] > num[F[i - 2]])
		{
			F[i] = i;
		}
		else
		{
			if (maxLen == 1) // 当前元素最小，且之前全为降序
				F[i] = i;
			else
				F[i] = F[i - 1];
		}
	}
	for (auto i : F)
		cout << i << " ";
	cout << endl;
	return maxLen;
}
*/