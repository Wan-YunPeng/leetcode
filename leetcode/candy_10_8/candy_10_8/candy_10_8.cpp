// candy_10_8.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int candy(vector<int> &ratings);
int candy2(vector<int> &ratings);
int solve(const vector<int> &ratings, vector<int> &f, int i);

int _tmain(int argc, _TCHAR* argv[])
{
	int a[] = { 1, 3, 2, 1, 5, 1, 2, 4 };
	vector<int> rating(a, a + sizeof(a) / sizeof(a[0]));
	int re = candy(rating);
	cout << re << endl;
	re = candy2(rating);
	cout << re << endl;
	return 0;
}

int candy(vector<int> &ratings)
{
	const int n = ratings.size();
	vector<int> increment(n,1);

	for (int i = 1, inc = 1; i < n; ++i) // 累计加糖数
	{
		if (ratings[i] > ratings[i - 1])
			increment[i] = max(++inc, increment[i]);
		else
			inc = 1;
	}
	
	for (int i = n - 2, inc = 1; i >= 0; --i)
	{
		if (ratings[i] > ratings[i + 1])
			increment[i] = max(++inc, increment[i]);
		else
			inc = 1;
	}

	for (auto i : increment)
		cout << i << " ";
	cout << endl;
	return accumulate(&increment[0], &increment[0] + n, 0);
}

int candy2(vector<int> &ratings)
{
	vector<int> f(ratings.size());
	int sum = 0;
	for (int i = 0; i < ratings.size(); ++i)
	{
		sum += solve(ratings, f, i);
	}
	return sum;
}

int solve(const vector<int> &ratings, vector<int> &f, int i)
{
	if (0 == f[i])
	{
		f[i] = 1;
		if (i > 0 && ratings[i] > ratings[i - 1])
			f[i] = max(f[i], solve(ratings, f, i - 1) + 1);
		if (i < ratings.size() - 1 && ratings[i] > ratings[i + 1])
			f[i] = max(f[i], solve(ratings, f, i + 1) + 1);
	}
	return f[i];
}